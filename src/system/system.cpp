#include "system.h"

System::System() {
	statistics = new Statistics();

	create_users();
	create_jobs();
	schedule();
	calculate_op_cost();
	print_results();
}


bool System::exist_negatives() {
	for (int i = 0; i < states.size(); i++) {
		if (states[i].get_short_cores() < 0 || 
			states[i].get_medium_cores() < 0 ||
			states[i].get_large_cores() < 0) {
			return true;
	}
}
return false;
}

void System::create_users() {
	int user_nr = generate_random(1, 100);
	for (int i = 0; i < user_nr; i++) {
		users.push_back(new User(i, false));
	}
	users.push_back(new User(user_nr, true));
}

void System::create_jobs() {
	int nr_users = users.size();
	int nr_jobs = 100/*generate_random(LOW_JOBS, HIGH_JOBS)*/;
	unsigned long long int now = /*(unsigned long long int)time(0)*/1513265102;

	random_device rd; 
	exponential_distribution<double> rng(6);
	mt19937 rnd_gen(rd());
	
	for (int i = 0; i < nr_jobs; i++) {
		unsigned long long int rand_seconds = 10 * rng(rnd_gen), duration = THIRTY_EIGHT_HOURS * rng(rnd_gen);
		time_t time = (time_t)(now + rand_seconds);
		int user_id = 0;
		Job * job = new Job(time, duration);
		while (!users[user_id]->can_afford(job)) {
			user_id++;
		}
		statistics->add_usage_price(job->get_price());
		users[user_id]->pay(job);
		job->set_user(users[user_id]);

		jobs.push_back(*job);
	}
	sort(jobs.begin(), jobs.end());
}

void System::insert_state_at_the_end(time_t start, time_t end, Job job) {
	statistics->add_waiting_time(start, job);

	State * start_state = new State(NODES_NR * CORES_NR, start, Start, job.get_name());
	start_state->insert_job(job);
	State * end_state = new State(NODES_NR * CORES_NR, end, End, job.get_name());
	states.push_back(*start_state);
	states.push_back(*end_state);
}

void System::insert_state_and_update(int i, int j, time_t start, time_t end, Job job) {
	statistics->add_waiting_time(start, job);

	State * start_state = i - 1 >= 0 ? new State(states[i - 1], start, Start, job.get_name()) : new State(NODES_NR * CORES_NR, end, Start, job.get_name());
	start_state->insert_job(job);
	State * end_state = !job.is_huge() && j - 1 >= 0 ? new State(states[j - 1], end, End, job.get_name()) : new State(NODES_NR * CORES_NR, end, End, job.get_name());
	for (int k = i; k < j; k++) {
		states[k].insert_job(job);
	}
	states.insert(states.begin() + j, *end_state);
	states.insert(states.begin() + i, *start_state);
}


void System::insert_week_state(time_t start, int i, Job job) {
	time_t end = start + job.get_duration();
	if (i == 0) {
		i++;
	}
	while (i - 1 < states.size() && !states[i - 1].can_insert_job(job)) {
		i++;
		start = states[i - 1].get_time();
		end = start + job.get_duration();
		if (is_weekend(start, end)) {
			start = advance_weekend(start);
			end = start + job.get_duration();
			while (i < states.size() &&  states[i].get_time() <= start) {
				i++;
			}
		}
	}
	int j = i;
	while (j < states.size() && states[j].get_time() <= end) {
		if (!states[j].can_insert_job(job)) {
			i = j + 1;
			start = states[i - 1].get_time();
			end = start + job.get_duration();
			while (i - 1 < states.size() && !states[i - 1].can_insert_job(job)) {
				i++;
				start = states[i - 1].get_time();
				end = start + job.get_duration();
				if (is_weekend(start, end)) {
					start = advance_weekend(start);
					end = start + job.get_duration();
					while (i < states.size() &&  states[i].get_time() <= start) {
						i++;
					}
				}
			}
			j = i;
		} else {
			j++;
		}
	}
	insert_state_and_update(i, j, start, end, job);
}

void System::insert_weekend_state(time_t s, int index, Job job) {
	time_t start = advance_to_friday(s), end;
	int i = index;
	while (i < states.size() && states[i].get_time() < start) {
		i++;
	}
	while (i < states.size() && states[i].get_time() == start) {
		start = advance_to_friday(start);
		while (i < states.size() && states[i].get_time() < start) {
			i++;
		}
	}
	end = start + job.get_duration();
	if (i < states.size()) {
		insert_state_and_update(i, i, start, end, job);
	} else {
		insert_state_at_the_end(start, end, job);
	}
}

void System::insert_state(int &index, Job job) {
	time_t start = job.get_time(), end;
	if (index == -1) {
		index = 0;
		if (job.is_huge()) {
			start = advance_to_friday(start);
		}
		end = start + job.get_duration();
		insert_state_at_the_end(start, end, job);
	} else {
		while (index < states.size() && states[index].get_time() <= start) {
			index++;
		}
		if (!job.is_huge()) {
			insert_week_state(start, index, job);
		} else {
			insert_weekend_state(start, index, job);
		}
	}
} 

void System::schedule() {
	int index = -1;
	for (int i = 0; i < jobs.size(); i++) {
		insert_state(index, jobs[i]);
	}
}

void System::calculate_op_cost() {
	int level = 0;
	time_t start = 0;
	for (int i = 0; i < states.size(); i++) {
		if (states[i].get_type() == Start) {
			if (level == 0) {
				start = states[i].get_time();
			}
			level++;
		} else {
			level--;
			if (level == 0) {
				statistics->add_machine_time(states[i].get_time() - start);
			}
		}
	}
	if (states.size() >= 2) {
		statistics->add_operational_cost((states[states.size() - 1].get_time() - states[0].get_time()) * OPERATIONAL_COST);
	}
}

void System::print_results() {
	if (!std::is_sorted(states.begin(),states.end())) {
		for (int i = 0; i < states.size(); i++){
			cout << states[i] << endl;
			if (i + 1 < states.size()) {
				if (states[i + 1] < states[i]) {
					cout << "[HERE!HERE!HERE!]" << endl << "[HERE!HERE!HERE!]" << endl << "[HERE!HERE!HERE!]" << endl;
				}
			}
		}
		cout << endl;
	}
	print_queues_stats();
	cout << "Is sorted: " << (std::is_sorted(states.begin(),states.end()) ? "true" : "false") << endl;
	cout << "Exist negatives: " << (exist_negatives() ? "true" : "false") << endl;
	cout << "Machine time consumed by jobs: " << statistics->get_machine_time() << endl;
	cout << "Price paid by users: £" << statistics->get_usage_price() << endl;
	cout << "Operational Cost: £" << statistics->get_operational_cost() << endl;
	cout << "Economic Balance: £" << statistics->get_economic_balance() << endl;
	cout << "Average waiting time (seconds):" << " Short(" << statistics->get_short_wt() << "), Medium(" << statistics->get_medium_wt() << "), Large(" << statistics->get_large_wt() << "), Huge(" << statistics->get_huge_wt() << ")" << endl;
	cout << "Average turnaround ratio:" << " Short(" << statistics->get_short_ta() << "), Medium(" << statistics->get_medium_ta() << "), Large(" << statistics->get_large_ta() << "), Huge(" << statistics->get_huge_ta() << ")" << endl;
	//cout << "Price paid by users: £" << usage_price << endl;
}
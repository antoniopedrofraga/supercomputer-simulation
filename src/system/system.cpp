#include "system.h"

System::System() {
	usage_price = USAGE_PRICE;
	operational_cost = OPERATIONAL_COST;

	create_users();
	create_jobs();
	schedule();
}

void System::create_users() {
	int user_nr = generate_random(1, 100);
	for (int i = 0; i < user_nr; i++) {
		users.push_back(new User(i));
	}
}

void System::create_jobs() {
	int nr_users = users.size();
	int nr_jobs = 50/*generate_random(LOW_JOBS, HIGH_JOBS)*/;
	unsigned long long int now = /*(unsigned long long int)time(0)*/1513265102;

	random_device rd; 
	exponential_distribution<double> rng(6);
	mt19937 rnd_gen(rd());
	
	for (int i = 0; i < nr_jobs; i++) {
		unsigned long long int rand_seconds = 10 * rng(rnd_gen), duration = THIRTY_EIGHT_HOURS * rng(rnd_gen);
		time_t time = (time_t)(now + rand_seconds);
		int user_id = generate_random(0, nr_users - 1);
		Job * job = new Job(time, duration);
		while (!users[user_id]->can_afford(job)) {
			user_id = generate_random(0, nr_users - 1);
		}
		users[user_id]->pay(job);
		job->set_user(users[user_id]);

		jobs.push_back(*job);
	}
	sort(jobs.begin(), jobs.end());
}

void System::insert_state_at_the_end(time_t start, time_t end, Job job) {
	State * start_state = new State(NODES_NR * CORES_NR, start, "Started " + job.get_name());
	start_state->insert_job(job);
	State * end_state = new State(NODES_NR * CORES_NR, end, "Ended " + job.get_name());
	states.push_back(*start_state);
	states.push_back(*end_state);
}

void System::insert_state_and_update(int i, int j, time_t start, time_t end, Job job) {
	State * start_state = i - 1 >= 0 ? new State(states[i - 1], start, "Started " + job.get_name()) : new State(NODES_NR * CORES_NR, end, "Started " + job.get_name());
	start_state->insert_job(job);
	State * end_state = !job.is_huge() && j - 1 >= 0 ? new State(states[j - 1], end, "Ended " + job.get_name()) : new State(NODES_NR * CORES_NR, end, "Ended " + job.get_name());
	for (int k = i; k < j; k++) {
		states[k].insert_job(job);
	}
	states.insert(states.begin() + j, *end_state);
	states.insert(states.begin() + i, *start_state);
}


void System::insert_week_state(time_t start, int i, Job job) {
	time_t end = start + job.get_duration();
	int j;
	while (i - 1 < states.size() && !states[i - 1].can_insert_job(job)) {
		i++;
		start = states[i - 1].get_time() + 1;
		end = start + job.get_duration();
		if (is_weekend(start, end)) {
			start = advance_weekend(start);
			end = start + job.get_duration();
			while (i < states.size() &&  states[i].get_time() <= start) {
				i++;
			}
		}
	}
	while (j < states.size() && states[j].get_time() <= end) {
		if (!states[j].can_insert_job(job)) {
			i = j + 1;
			start = states[i - 1].get_time() + 1;
			end = start + job.get_duration();
			while (i - 1 < states.size() && !states[i - 1].can_insert_job(job)) {
				i++;
				start = states[i - 1].get_time() + 1;
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
	int i =  index;
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
	for (int i = 0; i < states.size(); i++) {
		cout << states[i];
	}
}
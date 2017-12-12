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
	int nr_jobs = 30/*generate_random(LOW_JOBS, HIGH_JOBS)*/;
	unsigned long long int now = (unsigned long long int)time(0);
	
	/*
		TODO - Exponential probability
	*/
	for (int i = 0; i < nr_jobs; i++) {
		unsigned long long int rand_seconds = (rand() * rand()) % (10 + 1);
		time_t time = (time_t)(now + rand_seconds);
		int user_id = generate_random(0, nr_users - 1);

		User * user = users[user_id];
		Job * job = new Job(user, time);

		jobs.push_back(*job);
	}
	sort(jobs.begin(), jobs.end());
}

void System::insert_state_at_the_end(time_t start, time_t end, Job job) {
	State * start_state = new State(NODES_NR * CORES_NR, start, "IN " + job.get_name());
	start_state->insert_job(job);
	State * end_state = new State(NODES_NR * CORES_NR, end, "OUT " + job.get_name());
	states.push_back(*start_state);
	states.push_back(*end_state);
}

void System::insert_state_and_update(int i, int j, time_t start, time_t end, Job job) {
	State * start_state = new State(states[i], start, "IN " + job.get_name());
	start_state->insert_job(job);
	State * end_state = new State(states[j - 1], end, "OUT " + job.get_name());
	for (int k = i + 1; k < j; k++) {
		states[k].insert_job(job);
	}
	states.insert(states.begin() + j, *end_state);
	states.insert(states.begin() + i, *start_state);
}

void System::insert_states(int &index, Job job) {
	time_t start = job.get_time(), end;
	if (index == -1) {
		index = 0;
		end = start + job.get_duration();
		insert_state_at_the_end(start, end, job);
	} else {
		while (index < states.size() && states[index].get_time() <= start) {
			index++;
		}
		int i = index, j = index;
		end = start + job.get_duration();
		while (j < states.size() && states[j].get_time() <= end) {
			if (!states[j].can_insert_job(job)) {
				start = states[j].get_time() + 1;
				end = start + job.get_duration();
				i = j + 1;
			}
			j++;
		}
		insert_state_and_update(i, j, start, end, job);
	}
} 

void System::schedule() {
	int index = -1;
	for (int i = 0; i < jobs.size(); i++) {
		insert_states(index, jobs[i]);
	}
	for (int i = 0; i < states.size(); i++) {
		cout << states[i];
	}
}
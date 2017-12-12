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
	int nr_jobs = generate_random(LOW_JOBS, HIGH_JOBS);
	unsigned long long int now = (unsigned long long int)time(0);
	
	/*
		TODO - Exponential probability
	*/
	for (int i = 0; i < nr_jobs; i++) {
		unsigned long long int rand_seconds = (rand() * rand()) % (ONE_WEEK + 1);
    	time_t time = (time_t)(now + rand_seconds);
		int user_id = generate_random(0, nr_users - 1);

		User * user = users[user_id];
		Job * job = new Job(user, time);

		jobs.push_back(*job);
	}
	sort(jobs.begin(), jobs.end());
}

void System::insert_states(int &index, Job job) {
	time_t start = job.get_time();
	if (index == -1) {
		index = 0;
		time_t end = start + job.get_duration();
		State * start_state = new State(NODES_NR * CORES_NR, start);
		start_state->insert_job(job);
		State * end_state = new State(NODES_NR * CORES_NR, end);
		states.push_back(*start_state);
		states.push_back(*end_state);
	} else {
		int i = index;
		while (i < jobs.size() || jobs[i].get_time() < start) {
			i++;
		}

	}
}

void System::schedule() {
	int index = -1;
	for (int i = 0; i < jobs.size(); i++) {
		insert_states(index, jobs[i]);
	}
}
#include "system.h"

System::System() {
	usage_price = USAGE_PRICE;
	operational_cost = OPERATIONAL_COST;

	create_cores();
	create_users();
	create_jobs();
}

void System::create_cores() {
	for (int i = 0; i < NODES_NR; i++) {
		nodes.push_back(new Node(CORES_NR));
	}
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
	
	for (int i = 0; i < nr_jobs; i++) {
		unsigned long long int rand_seconds = (rand() * rand()) % (ONE_WEEK + 1);
    	time_t time = (time_t)(now + rand_seconds);
		int user_id = generate_random(0, nr_users - 1);

		User * user = users[user_id];
		Job * job = new Job(user, time);

		jobs.insert(job);
	}
}

void System::schedule() {
	
}
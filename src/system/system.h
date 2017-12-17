#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <set>
#include <iostream>
#include <ctime>
#include <algorithm>

#include "../users/user.h"
#include "../jobs/job.h"
#include "../utils/utils.h"
#include "state.h"

using namespace std;

class System {
private:
	vector<User *> users;
	vector<Job> jobs;
	vector<State *> states;

	double usage_price; 
	double operational_cost;

	void insert_state(int &index, Job job);
	void insert_week_state(time_t start, int i, Job job);
	void insert_weekend_state(time_t start, int i, Job job);

	bool exist_negatives();
	void create_users();
	void create_jobs();
	void calculate_op_cost();
	void schedule();

	void insert_state_at_the_end(time_t start, time_t end, Job job);
	void insert_state_and_update(int i, int j, time_t start, time_t end, Job job);

	struct StateCompare {
		bool operator()(const State* l, const State* r) {
			return *l < *r;
		}
	};
	struct JobCompare {
		bool operator()(const Job* l, const Job* r) {
			return *l < *r;
		}
	};
public:
	System();
};

#endif

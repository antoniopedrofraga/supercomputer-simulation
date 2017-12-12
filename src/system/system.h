#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <set>
#include <iostream>
#include <ctime>
#include <algorithm>

#include "node.h"
#include "../users/user.h"
#include "../jobs/job.h"
#include "../utils/utils.h"
#include "state.h"

using namespace std;

class System {
private:
	vector<User *> users;
	vector<Job> jobs;
	vector<State> states;

	double usage_price; 
	double operational_cost;

	void insert_states(int &index, Job job);
public:
	System();

	void create_users();
	void create_jobs();
	void schedule();
};

#endif

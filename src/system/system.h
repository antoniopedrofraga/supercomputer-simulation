#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <set>
#include <iostream>
#include <ctime>

#include "node.h"
#include "../users/user.h"
#include "../jobs/job.h"
#include "../utils/utils.h"

using namespace std;

class System {
private:
	vector<Node *> nodes;
	vector<User *> users;
	set<Job *> jobs;

	double usage_price; 
	double operational_cost;
public:
	System();

	void create_cores();
	void create_users();
	void create_jobs();
	void schedule();
};

#endif

#ifndef SYSTEM_H
#define SYSTEM_H

#include <random>
#include <vector>
#include <set>
#include <iostream>

#include "node.h"
#include "../users/user.h"
#include "../jobs/job.h"

using namespace std;

class System {
private:
	vector<Node> nodes;
	vector<User> users;
	set<Job> jobs;

	float usage_price;
	float running_cost;
public:
	System();
};

#endif

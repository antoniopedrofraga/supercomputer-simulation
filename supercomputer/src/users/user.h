#ifndef USER_H
#define USER_H

#include "group.h"
#include "../utils/utils.h"
#include "../jobs/job.h"

class User {
private:
	Configuration * config;
	int id;
	Group group;
	double budget;

	void generate_group(bool support);
public:
	User(Configuration * config, int id, bool support);
	bool can_afford(Job * job);
	void pay(Job * job);
};

#endif
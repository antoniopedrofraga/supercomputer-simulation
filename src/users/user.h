#ifndef USER_H
#define USER_H

#include "group.h"
#include "../utils/utils.h"
#include "../jobs/job.h"

class User {
private:
	int id;
	Group group;
	double budget;

	void generate_group();
public:
	User(int id);
	bool can_afford(Job * job);
	void pay(Job * job);
};

#endif
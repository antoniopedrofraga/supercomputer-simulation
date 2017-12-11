#ifndef USER_H
#define USER_H

#include "group.h"
#include "../utils/utils.h"

class User {
private:
	int id;
	Group group;
	double budget;
public:
	User(int id);

	void generate_group();
	void create_budget();
};

#endif
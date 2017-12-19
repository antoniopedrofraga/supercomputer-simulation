#include "user.h"


User::User(Configuration * config, int id, bool support) {
	this->config = config;
	this->id = id;
	generate_group(support);
}


void User::generate_group(bool support) {
	int rand = support ? 1 : generate_random(1, 3);
	if (rand == 1) {
		this->group = ITsupport;
		this->budget = IT_BUDGET;
	} else if (rand == 2) {
		this->group = Researcher;
		this->budget = config->get_researcher_budget();
	} else {
		this->group = Student;
		this->budget = config->get_student_budget();
	}
}

bool User::can_afford(Job * job) {
	return this->budget > job->get_price();
}

void User::pay(Job * job) {
	if (this->group != ITsupport) {
		this->budget -= job->get_price();
	}
}

#include "user.h"


User::User(int id, bool support) {
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
		this->budget = RESEARCHER_BUDGET;
	} else {
		this->group = Student;
		this->budget = STUDENT_BUDGET;
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

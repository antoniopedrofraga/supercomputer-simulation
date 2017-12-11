#include "user.h"


User::User(int id) {
	this->id = id;
	generate_group();
	create_budget();
}


void User::generate_group() {
	int rand = generate_random(1, 3);
	if (rand == 1) {
		this->group = ITsupport;
	} else if (rand == 2) {
		this->group = Researcher;
	} else {
		this->group = Student;
	}
}

void User::create_budget() {
	double low_budget = LOW_BUDGET, high_budget = HIGH_BUDGET;
	this->budget = generate_random(low_budget, high_budget);
}
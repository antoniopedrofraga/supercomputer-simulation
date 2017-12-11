#include "job.h"

Job::Job(User * user, time_t time) {
	this->user;
	this->time = time;

	int random_type = generate_random(1, 4);
	if (random_type == 1) {
		this->type = Short;
		this->occupation = 10;
	} else if (random_type == 2) {
		this->type = Medium;
		this->occupation = 20;
	} else if (random_type == 3) {
		this->type = Large;
		this->occupation = 50;
	} else {
		this->type = Huge;
		this->occupation = 100;
	}
}
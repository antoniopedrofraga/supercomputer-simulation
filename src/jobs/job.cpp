#include "job.h"

Job::Job(User * user, time_t time) {
	this->user;
	this->time = time;

	int total_nodes = NODES_NR * CORES_NR;
	int random_type = generate_random(1, 4);
	if (random_type == 1) {
		this->type = Short;
		this->duration = (rand() * rand()) % (ONE_HOUR + 1);
		this->cores = generate_random(1, 2 * CORES_NR);
	} else if (random_type == 2) {
		this->type = Medium;
		this->duration = (rand() * rand()) % (EIGHT_HOURS + (ONE_HOUR + 1));
		this->cores = generate_random(2 * CORES_NR + 1, (int)(total_nodes * 0.1));
	} else if (random_type == 3) {
		this->type = Large;
		this->duration = (rand() * rand()) % (SIXTEEN_HOURS + (EIGHT_HOURS + 1));
		this->cores = generate_random((int)(total_nodes * 0.1 + 1), (int)(total_nodes * 0.5));
	} else {
		this->type = Huge;
		this->duration = THIRTY_EIGHT_HOURS;
		this->cores = total_nodes;
	}
}

bool Job::is_short() { return this->type == Short; }
bool Job::is_medium() { return this->type == Medium; }
bool Job::is_large() { return this->type == Large; }
bool Job::is_huge() { return this->type == Huge; }

time_t Job::get_time() {
	return this->time;
}

int Job::get_cores() {
	return this->cores;
}

string Job::get_name() {
	string name = "";
	if (this->type == Short) {
		name += "Short";
	} else if (this->type == Medium) {
		name += "Medium";
	} else if (this->type == Large) {
		name += "Large";
	} else if (this->type == Huge) {
		name += "Huge";
	}
	name += " " + to_string(this->cores) + "\nSubmited: " + ctime(&time);
	return name;
}

unsigned long long int Job::get_duration() {
	return this->duration;
}
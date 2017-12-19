#include "job.h"

Job::Job(Configuration * config, time_t time, unsigned long long int duration) {
	this->config = config;
	this->time = time;
	unsigned long long int total_nodes = config->get_cores_nr() * config->get_nodes_nr();
	if (duration <= ONE_HOUR) {
		this->type = Short;
		this->cores = generate_random(1, 2 * CORES_NR);
	} else if (duration > ONE_HOUR && duration <= EIGHT_HOURS) {
		this->type = Medium;
		this->cores = generate_random(2 * CORES_NR + 1, (int)(total_nodes * 0.1));
	} else if (duration > EIGHT_HOURS && duration <= SIXTEEN_HOURS) {
		this->type = Large;
		this->cores = generate_random((int)(total_nodes * 0.1 + 1), (int)(total_nodes * 0.5));
	} else {
		this->type = Huge;
		this->cores = total_nodes;
	}
	this->duration = duration;
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

double Job::get_price() {
	return (double)duration * cores * config->get_usage_price();
}

void Job::set_user(User * user) {
	this->user = user;
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
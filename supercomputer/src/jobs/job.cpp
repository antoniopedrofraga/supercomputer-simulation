#include "job.h"

/*!
  Contructor of Job object. Defines what is the type of a job according to its duration, generating its number of cores randomly, following a linear distribution.
*/
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

/*!
  Ŕeturns whether the job is short or not.
*/
bool Job::is_short() { return this->type == Short; }

/*!
  Ŕeturns whether the job is medium or not.
*/
bool Job::is_medium() { return this->type == Medium; }

/*!
  Ŕeturns whether the job is large or not.
*/
bool Job::is_large() { return this->type == Large; }

/*!
  Ŕeturns whether the job is huge or not.
*/
bool Job::is_huge() { return this->type == Huge; }

/*!
  Ŕeturns the submission time of a job.
*/
time_t Job::get_time() {
	return this->time;
}

/*!
  Ŕeturns the number of cores taken by a job.
*/
int Job::get_cores() {
	return this->cores;
}

/*!
  Ŕeturns the price to pay to run a job.
*/
double Job::get_price() {
	return (double)duration * cores * config->get_usage_price();
}

/*!
  Defines the user who submited the job.
*/
void Job::set_user(User * user) {
	this->user = user;
}

/*!
  Returns the job duration in seconds.
*/
unsigned long long int Job::get_duration() {
	return this->duration;
}
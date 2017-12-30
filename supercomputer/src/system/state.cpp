#include "state.h"

/*!
  Default contructor of State. 
*/
State::State(long long int total_cores, time_t time, StateType state_type) {
	this->total_cores = total_cores;
	this->short_cores = total_cores * 0.1;
	this->medium_cores = total_cores * 0.2;
	this->large_cores = total_cores * 0.7;
	this->used_cores = 0;

	this->time = time;
	this->state_type = state_type;
}

/*!
  Alternative contructor of State. 
*/
State::State(State state, time_t time, StateType state_type) {
	this->total_cores = state.get_total_cores();
	this->short_cores = state.get_short_cores();
	this->medium_cores = state.get_medium_cores();
	this->large_cores = state.get_large_cores();
	this->used_cores = state.get_used_cores();

	this->time = time;
	this->state_type = state_type;
}

/*!
  Decreases the available number of a computational resources available in the system according to type of job. 
*/
void State::insert_job(Job job) {
	if (job.is_short()) {
		this->short_cores -= job.get_cores();
	} else if (job.is_medium()) {
		this->medium_cores -= job.get_cores();
	} else if (job.is_large()) {
		this->large_cores -= job.get_cores();
	} else if (job.is_huge()) {
		this->short_cores = 0;
		this->medium_cores = 0;
		this->large_cores = 0;
	}
	this->used_cores += job.get_cores();
}

/*!
  Indicates whether a job can run with the available computational resources at this system state. 
*/
bool State::can_insert_job(Job job) {
	int subtraction = -1;
	if (job.is_short()) {
		subtraction = this->short_cores - job.get_cores();
	} else if (job.is_medium()) {
		subtraction = this->medium_cores - job.get_cores();
	} else if (job.is_large()) {
		subtraction = this->large_cores - job.get_cores();
	}
	return subtraction >= 0;
}
/*!
  Returns time of ocurrence. 
*/
time_t State::get_time() {
	return this->time;
}

/*!
  Returns state type. 
*/
StateType State::get_type() {
	return this->state_type;
}

/*!
  Returns the amount of available computational resources for short jobs. 
*/
long long int State::get_short_cores() { return this->short_cores; }

/*!
  Returns the amount of available computational resources for medium jobs. 
*/
long long int State::get_medium_cores() { return this->medium_cores; }

/*!
  Returns the amount of available computational resources for large jobs. 
*/
long long int State::get_large_cores() { return this->large_cores; }

/*!
  Returns the total number of cores. 
*/
long long int State::get_total_cores() { return this->total_cores; }

/*!
  Returns the number of used cores. 
*/
long long int State::get_used_cores() { return this->used_cores; }


/*!
  < Operator overload. 
*/
bool operator<(State const& a, State const& b) {
    return a.time < b.time;
}

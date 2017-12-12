#include "state.h"

State::State(long long int total_cores, time_t time) {
	this->total_cores = total_cores;
	this->short_cores = total_cores * 0.1;
	this->medium_cores = total_cores * 0.2;
	this->large_cores = total_cores * 0.7;
	this->time = time;
}

void State::insert_job(Job job) {
	if (job.is_short()) {
		this->short_cores -= job.get_cores();
	} else if (job.is_medium()) {
		this->medium_cores -= job.get_cores();
	} else if (job.is_large()) {
		this->large_cores -= job.get_cores();
	}
}
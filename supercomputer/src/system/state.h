#ifndef STATE_H
#define STATE_H

using namespace std;
#include <string>
#include <iostream>
#include "statetype.h"
#include "../jobs/job.h"

using namespace std;

class State {
private:
	long long int short_cores;
	long long int medium_cores;
	long long int large_cores;
	long long int total_cores;

	long long int used_cores;

	StateType state_type;

	time_t time;
public:
	State(long long int total_cores, time_t time, StateType state_type);
	State(State state, time_t time, StateType state_type);
	void set_period(time_t start, time_t end);
	void insert_job(Job job);
	bool can_insert_job(Job job);
	time_t get_time();
	string get_name();
	StateType get_type();

	long long int get_short_cores();
	long long int get_medium_cores();
	long long int get_large_cores();
	long long int get_total_cores();
	long long int get_used_cores();

	const bool inline operator<(const State & state) const {
		return this->time < state.time;
	}
};

#endif
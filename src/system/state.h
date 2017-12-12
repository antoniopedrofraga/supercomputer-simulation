#ifndef STATE_H
#define STATE_H

#include <set>
#include "../jobs/job.h"

using namespace std;

class State {
private:
	long long int short_cores;
	long long int medium_cores;
	long long int large_cores;
	long long int total_cores;

	time_t time;
public:
	State(long long int total_cores, time_t time);
	void set_period(time_t start, time_t end);
	void insert_job(Job job);
};

#endif
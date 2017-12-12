#ifndef JOB_H
#define JOB_H

#include "type.h"
#include "../users/user.h"

class Job {
private:
	Type type;
	User * user;
	time_t time;
	unsigned long long int duration;
	int cores;
public:
	Job(User * user, time_t time);
	
	time_t get_time();
	unsigned long long int get_duration();
	int get_cores();

	bool is_short();
	bool is_medium();
	bool is_large();
	bool is_huge();
	
	const bool inline operator<(const Job & job) const {
		return this->time < job.time;
	}
};

#endif

#ifndef JOB_H
#define JOB_H

#include "type.h"
#include "../users/user.h"

class Job {
private:
	Type type;
	User * user;
	time_t time;
	unsigned int occupation;
public:
	Job(User * user, time_t time);
	const bool inline operator<(const Job & job) const {
		return this->time < job.time;
	}
};

#endif

#ifndef JOB_H
#define JOB_H

using namespace std;
#include <string>
#include <ctime>
#include "../utils/utils.h"
#include "../configuration/configuration.h"
#include "type.h"
class User;

class Job {
private:
	Configuration * config;
	Type type;
	User * user;
	time_t time;
	unsigned long long int duration;
	int cores;
public:
	Job(Configuration * config, time_t time, unsigned long long int duration);
	
	time_t get_time();
	unsigned long long int get_duration();
	int get_cores();
	double get_price();
	void set_user(User * user);

	bool is_short();
	bool is_medium();
	bool is_large();
	bool is_huge();
	
	const bool inline operator<(const Job & job) const {
		return this->time < job.time;
	}
};

#endif

#ifndef WEEK_H
#define WEEK_H

#include "../jobs/job.h"
#include <ctime>
#include <string>

class Week {
private:
	time_t start;
	time_t end;

	unsigned int short_nr;
	unsigned int medium_nr;
	unsigned int large_nr;
	unsigned int huge_nr;
public:
	Week(time_t start, time_t end);

	time_t get_start();
	time_t get_end();

	void add_job(Job job);

	friend ostream& operator<<(ostream& os, const Week& week);
};

#endif
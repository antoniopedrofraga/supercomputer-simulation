#include "week.h"

/*!
  Contructor of Week object.
*/
Week::Week(time_t start, time_t end) {
	this->start = start;
	this->end = end;

	this->short_nr = 0;
	this->medium_nr = 0;
	this->large_nr = 0;
	this->huge_nr = 0;
}

/*!
  Ŕeturns the starting time of a week.
*/
time_t Week::get_start() {
	return this->start;
}

/*!
  Ŕeturns the ending time of a week.
*/
time_t Week::get_end() {
	return this->end;
}

/*!
  Defines a start time of a week.
*/
void Week::set_start(time_t start) {
	this->start = start;
}

/*!
  Increments the number of jobs processed this week according to its type.
*/
void Week::add_job(Job job) { 
	if (job.is_short()) {
		this->short_nr++;
	} else if (job.is_medium()) {
		this->medium_nr++;
	} else if (job.is_large()) {
		this->large_nr++;
	} else {
		this->huge_nr++;
	}
}

/*!
  Converts the week object to a specific ostream output format.
*/
ostream& operator<<(ostream& os, const Week& week) {  
	time_t start = week.start, end = week.end;

	std::tm * start_tm = std::localtime(&start);
	char start_buffer[32];
	std::strftime(start_buffer, 32, "%a, %d.%m.%Y %H:%M:%S", start_tm);

	std::tm * end_tm = std::localtime(&end);
	char end_buffer[32];
	std::strftime(end_buffer, 32, "%a, %d.%m.%Y %H:%M:%S", end_tm);

	os << "(" << string(start_buffer) << " to " << string(end_buffer) << ") ";
	os << "Short(" << to_string(week.short_nr) << ") ";
	os << "Medium(" << to_string(week.medium_nr) << ") ";
	os << "Large(" << to_string(week.large_nr) << ") ";
	os << "Huge(" << to_string(week.huge_nr) << ") ";
	return os;  
} 
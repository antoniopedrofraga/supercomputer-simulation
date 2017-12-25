#include "statistics.h"

/*!
  Contructor of Statistics object.
*/
Statistics::Statistics(Configuration * config) {
	this->config = config;
	this->usage_price = 0;
	this->operational_cost = 0;
	this->machine_time = 0;
}

/*!
  Adds usage price to system total usage price.
*/
void Statistics::add_usage_price(double price) {
	this->usage_price += price;
}

/*!
  Adds operational cost to system total operational cost.
*/
void Statistics::add_operational_cost(double cost) {
	this->operational_cost += cost;
}

/*!
  Adds time to system total machine time.
*/
void Statistics::add_machine_time(unsigned long long int time) {
	this->machine_time += time;
}

/*!
  Adds job to waiting time and turn around ratio vectors according to its type.
  Increments the number of Short, Medium, Large or Huge jobs processed in the week of job start time.
*/
void Statistics::add_job(time_t start, Job job) {
	unsigned long long int wt = start - job.get_time();
	double ta = (double)wt / (double)job.get_duration();
	if (job.is_short()) {
		this->short_queue_wt.push_back(wt);
		this->short_queue_ta.push_back(ta);
	} else if (job.is_medium()) {
		this->medium_queue_wt.push_back(wt);
		this->medium_queue_ta.push_back(ta);
	} else if (job.is_large()) {
		this->large_queue_wt.push_back(wt);
		this->large_queue_ta.push_back(ta);
	} else {
		this->huge_queue_wt.push_back(wt);
		this->huge_queue_ta.push_back(ta);
	}

	/*
		Increments value if week exists.
	*/
	bool added = false;
	for (int i = 0; i < this->weeks.size(); i++) {
		if (this->weeks[i].get_start() <= start && this->weeks[i].get_end() > start + job.get_duration()) {
			this->weeks[i].add_job(job);
			added = true;
		} else if (this->weeks[i].get_start() == advance_to_friday(start)) {
			this->weeks[i].add_job(job);
			added = true;
			this->weeks[i].set_start(start);
		}
	}

	/*
		Adds week and increments value if week doesn't exist.
	*/
	if (!added) {
		time_t s, e;
		unsigned int i = 0;
		if (this->weeks.size() == 0) {
			s = start;
		} else {
			s = get_back_to_monday(start);
		}
		e = advance_weekend(s);
		this->weeks.push_back(*(new Week(s, e)));
		i = this->weeks.size() - 1;
		this->weeks[i].add_job(job);
	}
}

/*!
  Returns average of turn around times of short jobs as a string with a precision of 2 decimal places.
*/
string Statistics::get_short_ta() {
	if (this->short_queue_ta.size() == 0) { return "0.00"; }

	double average = accumulate(this->short_queue_ta.begin(), this->short_queue_ta.end(), 0.0) / this->short_queue_ta.size();
	stringstream stream;
	stream << fixed << setprecision(2) << average;
	return stream.str();
}

/*!
  Returns average of turn around times of medium jobs as a string with a precision of 2 decimal places.
*/
string Statistics::get_medium_ta() {
	if (this->medium_queue_ta.size() == 0) { return "0.00"; }

	double average = accumulate(this->medium_queue_ta.begin(), this->medium_queue_ta.end(), 0.0) / this->medium_queue_ta.size();
	stringstream stream;
	stream << fixed << setprecision(2) << average;
	return stream.str();
}

/*!
  Returns average of turn around times of large jobs as a string with a precision of 2 decimal places.
*/
string Statistics::get_large_ta() {
	if (this->large_queue_ta.size() == 0) { return "0.00"; }

	double average = accumulate(this->large_queue_ta.begin(), this->large_queue_ta.end(), 0.0) / this->large_queue_ta.size();
	stringstream stream;
	stream << fixed << setprecision(2) << average;
	return stream.str();
}

/*!
  Returns average of turn around times of huge jobs as a string with a precision of 2 decimal places.
*/
string Statistics::get_huge_ta() {
	if (this->huge_queue_ta.size() == 0) { return "0.00"; }

	double average = accumulate(this->huge_queue_ta.begin(), this->huge_queue_ta.end(), 0.0) / this->huge_queue_ta.size();
	stringstream stream;
	stream << fixed << setprecision(2) << average;
	return stream.str();
}

/*!
  Returns average of waiting times of short jobs as a string with a precision of 2 decimal places.
*/
string Statistics::get_short_wt() {
	if (this->short_queue_wt.size() == 0) { return "0.00"; }

	double average = accumulate(this->short_queue_wt.begin(), this->short_queue_wt.end(), 0.0) / this->short_queue_wt.size();
	stringstream stream;
	stream << fixed << setprecision(2) << average;
	return stream.str();
}

/*!
  Returns average of waiting times of medium jobs as a string with a precision of 2 decimal places.
*/
string Statistics::get_medium_wt() {
	if (this->medium_queue_wt.size() == 0) { return "0.00"; }

	double average = accumulate(this->medium_queue_wt.begin(), this->medium_queue_wt.end(), 0.0) / this->medium_queue_wt.size();
	stringstream stream;
	stream << fixed << setprecision(2) << average;
	return stream.str();
}

/*!
  Returns average of waiting times of large jobs as a string with a precision of 2 decimal places.
*/
string Statistics::get_large_wt() {
	if (this->large_queue_wt.size() == 0) { return "0.00"; }

	double average = accumulate(this->large_queue_wt.begin(), this->large_queue_wt.end(), 0.0) / this->large_queue_wt.size();
	stringstream stream;
	stream << fixed << setprecision(2) << average;
	return stream.str();
}

/*!
  Returns average of waiting times of huge jobs as a string with a precision of 2 decimal places.
*/
string Statistics::get_huge_wt() {
	if (this->huge_queue_wt.size() == 0) { return "0.00"; }

	double average = accumulate(this->huge_queue_wt.begin(), this->huge_queue_wt.end(), 0.0) / this->huge_queue_wt.size();
	stringstream stream;
	stream << fixed << setprecision(2) << average;
	return stream.str();
}

/*!
  Returns system total operational cost as a string with a precision of 2 decimal places.
*/
string Statistics::get_operational_cost() {
	stringstream stream;
	stream << fixed << setprecision(2) << this->operational_cost;
	return stream.str();
}

/*!
  Returns system economic balance as a string with a precision of 2 decimal places.
*/
string Statistics::get_economic_balance() {
	stringstream stream;
	stream << fixed << setprecision(2) << (this->usage_price - this->operational_cost);
	return stream.str();
}

/*!
  Returns the machine time as a string with the number of days, hours, minutes and seconds.
*/
string Statistics::get_machine_time() {
	long long int days = this->machine_time / 60 / 60 / 24;
	long long int hours = (this->machine_time / 60 / 60) % 24;
	long long int minutes = (this->machine_time / 60) % 60;
	long long int seconds = this->machine_time % 60;
	stringstream stream;
	stream <<  to_string(days) + " days, "
	<< to_string(hours) + " hours, " 
	<< to_string(minutes) + " minutes, "
	<< to_string(seconds) + " seconds. ";
	return stream.str();
}

/*!
  Returns system total usage price as a string with a precision of 2 decimal places.
*/
string Statistics::get_usage_price() {
	stringstream stream;
	stream << fixed << setprecision(2) << this->usage_price;
	return stream.str();
}

/*!
  Returns system weekly usage as a string.
*/
string Statistics::get_weekly_usage() {
	stringstream stream;
	for (int i = 0; i < weeks.size(); i++) {
		stream << "Week " << (i + 1) << " " << weeks[i] << endl;
	}
	return stream.str();
}

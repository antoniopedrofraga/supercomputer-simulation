#include "statistics.h"

Statistics::Statistics(Configuration * config) {
	this->config = config;
	this->usage_price = 0;
	this->operational_cost = 0;
    this->machine_time = 0;
}

void Statistics::add_usage_price(double price) {
	this->usage_price += price;
}

void Statistics::add_operational_cost(double cost) {
	this->operational_cost += cost;
}

void Statistics::add_machine_time(unsigned long long int time) {
	this->machine_time += time;
}

void Statistics::add_job(time_t start, Job job) {
	unsigned long long int wt = start - job.get_time();
	double ta = (double) wt / (double) job.get_duration();
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
	if (!added) {
		time_t s, e;
		unsigned int i = 0;
		if (this->weeks.size() == 0) {
			s = start;
		} else {
			s = get_back_to_sunday(start);
		}
		e = advance_weekend(s);
		this->weeks.push_back(*(new Week(s, e)));
		i = this->weeks.size() - 1;
		this->weeks[i].add_job(job);
	}
}

string Statistics::get_short_ta() {
	if (this->short_queue_ta.size() == 0) { return "0.00"; }

	double average = accumulate(this->short_queue_ta.begin(), this->short_queue_ta.end(), 0.0) / this->short_queue_ta.size();
	stringstream stream;
	stream << fixed << setprecision(2) << average;
	return stream.str();
}
string Statistics::get_medium_ta() {
	if (this->medium_queue_ta.size() == 0) { return "0.00"; }

	double average = accumulate(this->medium_queue_ta.begin(), this->medium_queue_ta.end(), 0.0) / this->medium_queue_ta.size();
	stringstream stream;
	stream << fixed << setprecision(2) << average;
	return stream.str();
}
string Statistics::get_large_ta() {
	if (this->large_queue_ta.size() == 0) { return "0.00"; }

	double average = accumulate(this->large_queue_ta.begin(), this->large_queue_ta.end(), 0.0) / this->large_queue_ta.size();
	stringstream stream;
	stream << fixed << setprecision(2) << average;
	return stream.str();
}
string Statistics::get_huge_ta() {
	if (this->huge_queue_ta.size() == 0) { return "0.00"; }

	double average = accumulate(this->huge_queue_ta.begin(), this->huge_queue_ta.end(), 0.0) / this->huge_queue_ta.size();
	stringstream stream;
	stream << fixed << setprecision(2) << average;
	return stream.str();
}


string Statistics::get_short_wt() {
	if (this->short_queue_ta.size() == 0) { return "0.00"; }

	double average = accumulate(this->short_queue_wt.begin(), this->short_queue_wt.end(), 0.0) / this->short_queue_wt.size();
	stringstream stream;
	stream << fixed << setprecision(2) << average;
	return stream.str();
}
string Statistics::get_medium_wt() {
	if (this->medium_queue_ta.size() == 0) { return "0.00"; }

	double average = accumulate(this->medium_queue_wt.begin(), this->medium_queue_wt.end(), 0.0) / this->medium_queue_wt.size();
	stringstream stream;
	stream << fixed << setprecision(2) << average;
	return stream.str();
}
string Statistics::get_large_wt() {
	if (this->large_queue_ta.size() == 0) { return "0.00"; }

	double average = accumulate(this->large_queue_wt.begin(), this->large_queue_wt.end(), 0.0) / this->large_queue_wt.size();
	stringstream stream;
	stream << fixed << setprecision(2) << average;
	return stream.str();
}
string Statistics::get_huge_wt() {
	if (this->huge_queue_ta.size() == 0) { return "0.00"; }

	double average = accumulate(this->huge_queue_wt.begin(), this->huge_queue_wt.end(), 0.0) / this->huge_queue_wt.size();
	stringstream stream;
	stream << fixed << setprecision(2) << average;
	return stream.str();
}

string Statistics::get_operational_cost() {
	stringstream stream;
	stream << fixed << setprecision(2) << this->operational_cost;
	return stream.str();
}

string Statistics::get_economic_balance() {
	stringstream stream;
	stream << fixed << setprecision(2) << (this->usage_price - this->operational_cost);
	return stream.str();
}

string Statistics::get_machine_time() {
    long long int days = this->machine_time / 60 / 60 / 24;
    long long int hours = (this->machine_time / 60 / 60) % 24;
    long long int minutes = (this->machine_time / 60) % 60;
    long long int seconds = this->machine_time % 60;
	stringstream stream;
    stream << (days > 0 ? to_string(days) + " days, " : "")
	<< (hours > 0 ? to_string(hours) + " hours, " : "")
	<< (minutes > 0 ? to_string(minutes) + " minutes, " : "")
	<< (seconds > 0 ? to_string(seconds) + " seconds. " : "");
	return stream.str();
}
string Statistics::get_usage_price() {
	stringstream stream;
	stream << fixed << setprecision(2) << this->usage_price;
	return stream.str();
}

string Statistics::get_weekly_usage() {
	stringstream stream;
	for (int i = 0; i < weeks.size(); i++) {
		stream << "Week " << (i + 1) << " " << weeks[i] << endl;
	}
	return stream.str();
}

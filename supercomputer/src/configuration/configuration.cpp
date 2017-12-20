#include "configuration.h"

Configuration::Configuration() {
	this->users_nr = USERS_NR;
	this->users_nr_min = USERS_NR_MIN;
	this->users_nr_max = USERS_NR_MAX;
	this->users_random = false;

	this->jobs_nr = JOBS_NR;
	this->jobs_nr_min = JOBS_NR_MIN;
	this->jobs_nr_max = JOBS_NR_MAX;
	this->jobs_random = false;

	this->nodes_nr = NODES_NR;
	this->cores_nr = CORES_NR;

	this->usage_price = USAGE_PRICE;
	this->operational_cost = OPERATIONAL_COST;

	this->student_budget = STUDENT_BUDGET;
	this->student_budget_min = STUDENT_BUDGET_MIN;
	this->student_budget_max = STUDENT_BUDGET_MAX;
	this->student_random = false;

	this->researcher_budget = RESEARCHER_BUDGET;
	this->researcher_budget_min = RESEARCHER_BUDGET_MIN;
	this->researcher_budget_max = RESEARCHER_BUDGET_MAX;
	this->researcher_random = false;

	this->requests_span = REQUESTS_SPAN;

	this->start = time(0);
}

unsigned int Configuration::get_users_nr() {
	if (!this->users_random) {
		return this->users_nr;
	} else {
		return generate_random(this->users_nr_min, this->users_nr_max);
	}
}
unsigned int Configuration::get_users_nr_min() {
	return this->users_nr_min;
}
unsigned int Configuration::get_users_nr_max() {
	return this->users_nr_max;
}
bool Configuration::is_users_nr_random() {
	return this->users_random;
}

unsigned int Configuration::get_jobs_nr() {
	if (!this->jobs_random) {
		return this->jobs_nr;
	} else {
		return generate_random(this->jobs_nr_min, this->jobs_nr_max);
	}
}
unsigned int Configuration::get_jobs_nr_min() {
	return this->jobs_nr_min;
}
unsigned int Configuration::get_jobs_nr_max() {
	return this->jobs_nr_max;
}
bool Configuration::is_jobs_nr_random() {
	return this->jobs_random;
}

unsigned int Configuration::get_cores_nr() {
	return this->cores_nr;
}

unsigned int Configuration::get_nodes_nr() {
	return this->nodes_nr;
}

double Configuration::get_student_budget() {
	if (!this->student_random) {
		return this->student_budget;
	} else {
		return generate_random(this->student_budget_min, this->student_budget_max);
	}
}
double Configuration::get_student_budget_min() {
	return this->student_budget_min;
}
double Configuration::get_student_budget_max() {
	return this->student_budget_max;
}
bool Configuration::is_student_budget_random() {
	return this->student_random;
}

double Configuration::get_researcher_budget() {
	if (!this->researcher_random) {
		return this->researcher_budget;
	} else {
		return generate_random(this->researcher_budget_min, this->researcher_budget_max);
	}
}
double Configuration::get_researcher_budget_min() {
	return this->researcher_budget_min;
}
double Configuration::get_researcher_budget_max() {
	return this->researcher_budget_max;
}
bool Configuration::is_researcher_budget_random() {
	return this->researcher_random;
}

double Configuration::get_usage_price() {
	return this->usage_price;
}

double Configuration::get_operational_cost() {
	return this->operational_cost;
}

unsigned long long int Configuration::get_requests_span() {
	return this->requests_span;
}

void Configuration::set_student_random(bool random) {
	this->student_random = random;
}
void Configuration::set_researcher_random(bool random) {
	this->researcher_random = random;
}
void Configuration::set_users_random(bool random) {
	this->users_random = random;
}
void Configuration::set_jobs_random(bool random) {
	this->jobs_random = random;
}

void Configuration::set_usage_price(double usage_price) {
	this->usage_price = usage_price;
}
void Configuration::set_operational_cost(double operational_cost) {
	this->operational_cost = operational_cost;
}
void Configuration::set_nodes_nr(unsigned int nodes_nr) {
	this->nodes_nr = nodes_nr;
}
void Configuration::set_cores_nr(unsigned int cores_nr) {
	this->cores_nr = cores_nr;
}

void Configuration::set_student_budget(double budget) {
	this->student_budget = budget;
}
void Configuration::set_student_budget_min(double min) {
	if (min >= this->student_budget_max) {
		this->student_budget_min = this->student_budget_max - 0.01;
	} else {
		this->student_budget_min = min;
	}
}
void Configuration::set_student_budget_max(double max) {
	if (max <= this->student_budget_min) {
		this->student_budget_max = this->student_budget_min + 0.01;
	}else {
		this->student_budget_max = max;
	}
}

void Configuration::set_researcher_budget(double budget) {
	this->researcher_budget = budget;
}
void Configuration::set_researcher_budget_min(double min) {
	if (min >= this->researcher_budget_max) {
		this->researcher_budget_min = this->researcher_budget_max - 0.01;
	} else {
		this->researcher_budget_min = min;
	}
}
void Configuration::set_researcher_budget_max(double max) {
	if (max <= this->researcher_budget_min) {
		this->researcher_budget_max = this->researcher_budget_min + 0.01;
	}else {
		this->researcher_budget_max = max;
	}
}

void Configuration::set_jobs_nr(unsigned int nr) {
	this->jobs_nr = nr;
}
void Configuration::set_jobs_nr_min(unsigned int min) {
	if (min >= this->jobs_nr_max) {
		this->jobs_nr_min = this->jobs_nr_max - 1;
	} else {
		this->jobs_nr_min = min;
	}
}
void Configuration::set_jobs_nr_max(unsigned int max) {
	if (max <= this->jobs_nr_min) {
		this->jobs_nr_max = this->jobs_nr_min + 1;
	}else {
		this->jobs_nr_max = max;
	}
}

void Configuration::set_users_nr(unsigned int nr) {
	this->users_nr = nr;
}
void Configuration::set_users_nr_min(unsigned int min) {
	if (min >= this->users_nr_max) {
		this->users_nr_min = this->users_nr_max - 1;
	} else {
		this->users_nr_min = min;
	}
}
void Configuration::set_users_nr_max(unsigned int max) {
	if (max <= this->users_nr_min) {
		this->users_nr_max = this->users_nr_min + 1;
	}else {
		this->users_nr_max = max;
	}
}

void Configuration::set_request_span(unsigned long long int span) {
	this->requests_span = span;
}

void Configuration::set_now(bool now) {
	this->now = now;
}
void Configuration::set_time(time_t time) {
	this->start = time;
}

time_t Configuration::get_time() {
	if (now) {
		return time(0);
	} else {
		return this->start;
	}
}
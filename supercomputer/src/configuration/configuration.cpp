#include "configuration.h"

/*!
  Default contructor of configuration. The default input values are defined in the "utils.h" header file.
*/
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

	this->now = true;
	this->start = time(0);
}

/*!
  Ŕeturns a constant value if the variable "users_random" is false, and a random value between two established limits if not.
*/
unsigned int Configuration::get_users_nr() {
	if (!this->users_random) {
		return this->users_nr;
	} else {
		return generate_random(this->users_nr_min, this->users_nr_max);
	}
}

/*!
  Ŕeturns the lower limit of randomly generated values of users numbers.
*/
unsigned int Configuration::get_users_nr_min() {
	return this->users_nr_min;
}

/*!
  Ŕeturns the upper limit of randomly generated values of users numbers.
*/
unsigned int Configuration::get_users_nr_max() {
	return this->users_nr_max;
}

/*!
  Ŕeturns whether the number of users is randomly generated or not.
*/
bool Configuration::is_users_nr_random() {
	return this->users_random;
}

/*!
  Ŕeturns a constant value if the variable "jobs_random" is false, and a random value between two established limits if not.
*/
unsigned int Configuration::get_jobs_nr() {
	if (!this->jobs_random) {
		return this->jobs_nr;
	} else {
		return generate_random(this->jobs_nr_min, this->jobs_nr_max);
	}
}

/*!
  Ŕeturns the lower limit of randomly generated values of jobs numbers.
*/
unsigned int Configuration::get_jobs_nr_min() {
	return this->jobs_nr_min;
}

/*!
  Ŕeturns the upper limit of randomly generated values of jobs numbers.
*/
unsigned int Configuration::get_jobs_nr_max() {
	return this->jobs_nr_max;
}

/*!
  Ŕeturns whether the number of jobs is randomly generated or not.
*/
bool Configuration::is_jobs_nr_random() {
	return this->jobs_random;
}

/*!
  Ŕeturns the number of cores per node.
*/
unsigned int Configuration::get_cores_nr() {
	return this->cores_nr;
}

/*!
  Ŕeturns the total number of nodes.
*/
unsigned int Configuration::get_nodes_nr() {
	return this->nodes_nr;
}

/*!
  Ŕeturns a constant value if the variable "student_random" is false, and a random value between two established limits if not.
*/
double Configuration::get_student_budget() {
	if (!this->student_random) {
		return this->student_budget;
	} else {
		return generate_random(this->student_budget_min, this->student_budget_max);
	}
}

/*!
  Ŕeturns the lower limit of a randomly generated student budget.
*/
double Configuration::get_student_budget_min() {
	return this->student_budget_min;
}

/*!
  Ŕeturns the upper limit of a randomly generated student budget.
*/
double Configuration::get_student_budget_max() {
	return this->student_budget_max;
}

/*!
  Ŕeturns whether the student budget is randomly generated or not.
*/
bool Configuration::is_student_budget_random() {
	return this->student_random;
}


/*!
  Ŕeturns a constant value if the variable "student_random" is false, and a random value between two established limits if not.
*/
double Configuration::get_researcher_budget() {
	if (!this->researcher_random) {
		return this->researcher_budget;
	} else {
		return generate_random(this->researcher_budget_min, this->researcher_budget_max);
	}
}

/*!
  Ŕeturns the lower limit of a randomly generated researcher budget.
*/
double Configuration::get_researcher_budget_min() {
	return this->researcher_budget_min;
}

/*!
  Ŕeturns the upper limit of a randomly generated researcher budget.
*/
double Configuration::get_researcher_budget_max() {
	return this->researcher_budget_max;
}

/*!
  Ŕeturns whether the researcher budget is randomly generated or not.
*/
bool Configuration::is_researcher_budget_random() {
	return this->researcher_random;
}

/*!
  Ŕeturns the usage price of the system per core second.
*/
double Configuration::get_usage_price() {
	return this->usage_price;
}

/*!
  Ŕeturns the operational cost of the system per second.
*/
double Configuration::get_operational_cost() {
	return this->operational_cost;
}

/*!
  Ŕeturns the requests time span in seconds.
*/
unsigned long long int Configuration::get_requests_span() {
	return this->requests_span;
}

/*!
  Defines whether the student budget is randomly generated or not.
*/
void Configuration::set_student_random(bool random) {
	this->student_random = random;
}

/*!
  Defines whether the researcher budget is randomly generated or not.
*/
void Configuration::set_researcher_random(bool random) {
	this->researcher_random = random;
}

/*!
  Defines whether the number of users is randomly generated or not.
*/
void Configuration::set_users_random(bool random) {
	this->users_random = random;
}

/*!
  Defines whether the number of jobs is randomly generated or not.
*/
void Configuration::set_jobs_random(bool random) {
	this->jobs_random = random;
}

/*!
  Defines the value of the usage price of the system.
*/
void Configuration::set_usage_price(double usage_price) {
	this->usage_price = usage_price;
}

/*!
  Defines the value of the operational cost of the system.
*/
void Configuration::set_operational_cost(double operational_cost) {
	this->operational_cost = operational_cost;
}

/*!
  Defines number of nodes of the system.
*/
void Configuration::set_nodes_nr(unsigned int nodes_nr) {
	if (nodes_nr < NODES_NR_MIN) {
		this->nodes_nr = NODES_NR_MIN;
	} else if (nodes_nr > NODES_NR_MAX) {
		this->nodes_nr = NODES_NR_MAX;
	} else {
		this->nodes_nr = nodes_nr;
	}
}

/*!
  Defines number of cores per node.
*/
void Configuration::set_cores_nr(unsigned int cores_nr) {
	if (cores_nr < CORES_NR_MIN) {
		this->cores_nr = CORES_NR_MIN;
	} else if (cores_nr > CORES_NR_MAX) {
		this->cores_nr = CORES_NR_MAX;
	} else {
		this->cores_nr = cores_nr;
	}
}

/*!
  Defines value of a student budget.
*/
void Configuration::set_student_budget(double budget) {
	this->student_budget = budget;
}

/*!
  Defines the lower limit of randomly generated student budgets, never letting this value being higher than the upper limit.
*/
void Configuration::set_student_budget_min(double min) {
	if (min >= this->student_budget_max) {
		this->student_budget_min = this->student_budget_max - 0.01;
	} else {
		this->student_budget_min = min;
	}
}

/*!
  Defines the upper limit of randomly generated student budgets, never letting this value being smaller than the upper limit.
*/
void Configuration::set_student_budget_max(double max) {
	if (max <= this->student_budget_min) {
		this->student_budget_max = this->student_budget_min + 0.01;
	}else {
		this->student_budget_max = max;
	}
}

/*!
  Defines value of a researcher budget.
*/
void Configuration::set_researcher_budget(double budget) {
	this->researcher_budget = budget;
}

/*!
  Defines the lower limit of randomly generated researcher budgets, never letting this value being higher than the upper limit.
*/
void Configuration::set_researcher_budget_min(double min) {
	if (min >= this->researcher_budget_max) {
		this->researcher_budget_min = this->researcher_budget_max - 0.01;
	} else {
		this->researcher_budget_min = min;
	}
}

/*!
  Defines the upper limit of randomly generated researcher budgets, never letting this value being smaller than the upper limit.
*/
void Configuration::set_researcher_budget_max(double max) {
	if (max <= this->researcher_budget_min) {
		this->researcher_budget_max = this->researcher_budget_min + 0.01;
	}else {
		this->researcher_budget_max = max;
	}
}

/*!
  Defines number of jobs.
*/
void Configuration::set_jobs_nr(unsigned int nr) {
	this->jobs_nr = nr;
}

/*!
  Defines the lower limit of randomly generated number of jobs, never letting this value being higher than the upper limit.
*/
void Configuration::set_jobs_nr_min(unsigned int min) {
	if (min >= this->jobs_nr_max) {
		this->jobs_nr_min = this->jobs_nr_max - 1;
	} else {
		this->jobs_nr_min = min;
	}
}

/*!
  Defines the upper limit of randomly generated number of jobs, never letting this value being smaller than the upper limit.
*/
void Configuration::set_jobs_nr_max(unsigned int max) {
	if (max <= this->jobs_nr_min) {
		this->jobs_nr_max = this->jobs_nr_min + 1;
	}else {
		this->jobs_nr_max = max;
	}
}

/*!
  Defines number of users.
*/
void Configuration::set_users_nr(unsigned int nr) {
	this->users_nr = nr;
}

/*!
  Defines the lower limit of randomly generated number of users, never letting this value being higher than the upper limit.
*/
void Configuration::set_users_nr_min(unsigned int min) {
	if (min >= this->users_nr_max) {
		this->users_nr_min = this->users_nr_max - 1;
	} else {
		this->users_nr_min = min;
	}
}

/*!
  Defines the upper limit of randomly generated number of users, never letting this value being smaller than the upper limit.
*/
void Configuration::set_users_nr_max(unsigned int max) {
	if (max <= this->users_nr_min) {
		this->users_nr_max = this->users_nr_min + 1;
	}else {
		this->users_nr_max = max;
	}
}

/*!
  Defines the upper limit of requests time span in seconds.
*/
void Configuration::set_requests_span(unsigned long long int span) {
	this->requests_span = span;
}

/*!
  Defines whether the simulation starting date is the present or not.
*/
void Configuration::set_now(bool now) {
	this->now = now;
}

/*!
  Defines the simulation starting date.
*/
void Configuration::set_time(time_t time) {
	this->start = time;
}

/*!
  Returns the simulation starting date, the current UNIX time stamp if the "now" is true, a defined date if it's false.
*/
time_t Configuration::get_time() {
	if (now) {
		return time(0);
	} else {
		return this->start;
	}
}
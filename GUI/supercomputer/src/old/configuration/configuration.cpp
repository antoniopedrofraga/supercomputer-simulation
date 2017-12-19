#include "configuration.h"

Configuration::Configuration() {
	this->users_nr = USERS_NR;
	this->jobs_nr = JOBS_NR;

	this->nodes_nr = NODES_NR;
	this->cores_nr = CORES_NR;

	this->usage_price = USAGE_PRICE;
	this->operational_cost = OPERATIONAL_COST;

	this->student_budget = STUDENT_BUDGET;
	this->researcher_budget = RESEARCHER_BUDGET;

	this->requests_span = REQUESTS_SPAN;
}

unsigned int Configuration::get_users_nr() {
	return this->users_nr;
}

unsigned int Configuration::get_jobs_nr() {
	return this->jobs_nr;
}

unsigned int Configuration::get_cores_nr() {
	return this->cores_nr;
}

unsigned int Configuration::get_nodes_nr() {
	return this->nodes_nr;
}

double Configuration::get_student_budget() {
	return this->student_budget;
}

double Configuration::get_researcher_budget() {
	return this->researcher_budget;
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
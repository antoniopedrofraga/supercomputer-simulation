#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "../utils/utils.h"

class Configuration {
private:
	unsigned int nodes_nr;
	unsigned int cores_nr;

	double usage_price;
	double operational_cost;

	double student_budget;
	double researcher_budget;

	unsigned int jobs_nr;
	unsigned int users_nr;

	unsigned long long int requests_span;
public:
	Configuration();

	unsigned int get_users_nr();
	unsigned int get_jobs_nr();

	unsigned int get_cores_nr();
	unsigned int get_nodes_nr();

	double get_usage_price();
	double get_operational_cost();

	double get_student_budget();
	double get_researcher_budget();

	unsigned long long int get_requests_span();
};
#endif
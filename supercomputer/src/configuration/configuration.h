#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <ctime>
#include "../utils/utils.h"

class Configuration {
private:
	unsigned int nodes_nr;
	unsigned int cores_nr;

	double usage_price;
	double operational_cost;

	double student_budget;
	double student_budget_min;
	double student_budget_max;
	bool student_random;

	double researcher_budget;
	double researcher_budget_min;
	double researcher_budget_max;
	bool researcher_random;

	unsigned int jobs_nr;
	unsigned int jobs_nr_min;
	unsigned int jobs_nr_max;
	bool jobs_random;

	unsigned int users_nr;
	unsigned int users_nr_min;
	unsigned int users_nr_max;
	bool users_random;

	unsigned long long int requests_span;

	time_t start;
	bool now;
public:
	Configuration();

	unsigned int get_users_nr();
	unsigned int get_users_nr_min();
	unsigned int get_users_nr_max();
	bool is_users_nr_random();

	unsigned int get_jobs_nr();
	unsigned int get_jobs_nr_min();
	unsigned int get_jobs_nr_max();
	bool is_jobs_nr_random();

	unsigned int get_cores_nr();
	unsigned int get_nodes_nr();

	double get_usage_price();
	double get_operational_cost();

	double get_student_budget();
	double get_student_budget_min();
	double get_student_budget_max();
	bool is_student_budget_random();

	double get_researcher_budget();
	double get_researcher_budget_min();
	double get_researcher_budget_max();
	bool is_researcher_budget_random();

	time_t get_time();

	unsigned long long int get_requests_span();

	void set_student_random(bool random);
	void set_researcher_random(bool random);
	void set_users_random(bool random);
	void set_jobs_random(bool random);

	void set_now(bool now);
	void set_time(time_t time);

	void set_usage_price(double usage_price);
	void set_operational_cost(double operational_cost);

	void set_nodes_nr(unsigned int nodes_nr);
	void set_cores_nr(unsigned int cores_nr);

	void set_student_budget(double budget);
	void set_student_budget_min(double min);
	void set_student_budget_max(double max);

	void set_researcher_budget(double budget);
	void set_researcher_budget_min(double min);
	void set_researcher_budget_max(double max);

	void set_jobs_nr(unsigned int nr);
	void set_jobs_nr_min(unsigned int min);
	void set_jobs_nr_max(unsigned int max);

	void set_users_nr(unsigned int nr);
	void set_users_nr_min(unsigned int min);
	void set_users_nr_max(unsigned int max);

	void set_requests_span(unsigned long long int span);
};
#endif
#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <tuple>
#include "../jobs/job.h"
#include "../utils/utils.h"
#include "../configuration/configuration.h"
#include "week.h"

using namespace std;

class Statistics {
private:
	Configuration * config;

	vector<unsigned long long int> short_queue_wt;
	vector<unsigned long long int> medium_queue_wt;
	vector<unsigned long long int> large_queue_wt;
	vector<unsigned long long int> huge_queue_wt;

	vector<double> short_queue_ta;
	vector<double> medium_queue_ta;
	vector<double> large_queue_ta;
	vector<double> huge_queue_ta;

	vector<Week> weeks;

	double usage_price;
	double operational_cost;
	unsigned long long int machine_time;
public:
	Statistics(Configuration * config);

	string get_usage_price();
	string get_machine_time();
	string get_operational_cost();
	string get_economic_balance();
	string get_weekly_usage();

	string get_short_ta();
	string get_medium_ta();
	string get_large_ta();
	string get_huge_ta();

	string get_short_wt();
	string get_medium_wt();
	string get_large_wt();
	string get_huge_wt();

	void add_usage_price(double price);
	void add_operational_cost(double cost);
	void add_machine_time(unsigned long long int time);
	void add_job(time_t start, Job job);
};

#endif
#ifndef STATISTICS_H //Define header if it's not defined
#define STATISTICS_H

#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <ctime>
#include "../jobs/job.h"
#include "../utils/utils.h"
#include "../configuration/configuration.h"
#include "week.h"

using namespace std;

//! Statistics class
/*!
  This object keeps statistics information structured and organized.
 */
class Statistics {
private:
	Configuration * config; /*! Private Config. Object containing the configuration of a simulation. */

	vector<unsigned long long int> short_queue_wt; /*! Private vector<unsigned long long int>. Contains all waiting times of short jobs. */
	vector<unsigned long long int> medium_queue_wt; /*! Private vector<unsigned long long int>. Contains all waiting times of medium jobs. */
	vector<unsigned long long int> large_queue_wt; /*! Private vector<unsigned long long int>. Contains all waiting times of large jobs. */
	vector<unsigned long long int> huge_queue_wt; /*! Private vector<unsigned long long int>. Contains all waiting times of huge jobs. */

	vector<double> short_queue_ta; /*! Private vector<double>. Contains all turn around ratios of short jobs. */
	vector<double> medium_queue_ta; /*! Private vector<double>. Contains all turn around ratios of medium jobs. */
	vector<double> large_queue_ta; /*! Private vector<double>. Contains all turn around ratios of large jobs. */
	vector<double> huge_queue_ta; /*! Private vector<double>. Contains all turn around ratios of huge jobs. */

	vector<Week> weeks; /*! Private vector<Week>. Contains information about number of jobs processed by every queues per week of simulation. */

	double usage_price; /*! Private double. Total usage price of the simulation. */
	double operational_cost; /*! Private double. Total operational cost of the simulation. */
	unsigned long long int machine_time; /*! Private unsigned long long int. Total machine time of the simulation. */
public:
	//! Statistics object default contructor.
    /*!
      Initializes a Statistics object.
      \param Configuration* config. Defines which configuration this statistics object should follow.
    */
	Statistics(Configuration * config);

	//! Public method. Returns the total usage price as a string.
    /*!
      \return string. Usage price string.
    */
	string get_usage_price();

	//! Public method. Returns the total machine time as a string.
    /*!
      \return string. Machine time string.
    */
	string get_machine_time();

	//! Public method. Returns the total operational cost as a string.
    /*!
      \return string. Operational cost string.
    */
	string get_operational_cost();

	//! Public method. Returns the economic balance as a string.
    /*!
      \return string. Economic balance string.
    */
	string get_economic_balance();

	//! Public method. Returns the weekly usage as a string.
    /*!
      \return string. System weekly usage.
    */
	string get_weekly_usage();

	//! Public method. Returns the average turn around ratio of short jobs.
    /*!
      \return string. Turn around ratio of short jobs string.
    */
	string get_short_ta();

	//! Public method. Returns the average turn around ratio of medium jobs.
    /*!
      \return string. Turn around ratio of medium jobs string.
    */
	string get_medium_ta();

	//! Public method. Returns the average turn around ratio of large jobs.
    /*!
      \return string. Turn around ratio of large jobs string.
    */
	string get_large_ta();

	//! Public method. Returns the average turn around ratio of huge jobs.
    /*!
      \return string. Turn around ratio of huge jobs string.
    */
	string get_huge_ta();

	//! Public method. Returns the average waiting time of short jobs.
    /*!
      \return string. Average waiting time of short jobs string.
    */
	string get_short_wt();

	//! Public method. Returns the average waiting time of medium jobs.
    /*!
      \return string. Average waiting time of medium jobs string.
    */
	string get_medium_wt();

	//! Public method. Returns the average waiting time of large jobs.
    /*!
      \return string. Average waiting time of large jobs string.
    */
	string get_large_wt();

	//! Public method. Returns the average waiting time of huge jobs.
    /*!
      \return string. Average waiting time of huge jobs string.
    */
	string get_huge_wt();

	//! Public method. Adds price to total usage price.
    /*!
      \param double price. Price to be added.
    */
	void add_usage_price(double price);

	//! Public method. Adds cost to total operational cost.
    /*!
      \param double cost. Cost to be added.
    */
	void add_operational_cost(double cost);

	//! Public method. Adds time to total machine time.
    /*!
      \param unsigned long long int time. Time in seconds to be added.
    */
	void add_machine_time(unsigned long long int time);

	//! Public method. Adds job to waiting time and turn around vectors.
    /*!
      \param time_t start. Time of start.
      \param Job job. Job to be added.
    */
	void add_job(time_t start, Job job);
};

#endif
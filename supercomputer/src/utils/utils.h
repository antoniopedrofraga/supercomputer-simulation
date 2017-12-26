#ifndef UTILS_H //Define header if it's not defined
#define UTILS_H

#include <random>
#include <float.h>
#include <vector>
#include <iostream>

//! Utils file
/*!
  This file contains constant values that are used globaly.
*/

const int NODES_NR = 128; /*! Public const int. Default number of nodes. The configuration value is initialized with this value. */
const int NODES_NR_MIN = 128; /*! Public const int. Default lower bound of number of nodes. The configuration value is initialized with this value. */
const int NODES_NR_MAX = 512; /*! Public const int. Default upper bound of number of nodes. The configuration value is initialized with this value. */

const int CORES_NR = 16; /*! Public const int. Default number of cores. The configuration value is initialized with this value. */
const int CORES_NR_MIN = 16; /*! Public const int. Default lower bound of number of cores. The configuration value is initialized with this value. */
const int CORES_NR_MAX = 64; /*! Public const int. Default upper bound of number of cores. The configuration value is initialized with this value. */

const int USERS_NR = 100; /*! Public const int. Default number of simulated users. The configuration value is initialized with this value. */
const int USERS_NR_MIN = 1; /*! Public const int. Default lower bound of number of simulated users. The configuration value is initialized with this value. */
const int USERS_NR_MAX = 1000; /*! Public const int. Default upper bound of number of simulated users. The configuration value is initialized with this value. */

const int JOBS_NR = 100; /*! Public const int. Default number of simulated jobs. The configuration value is initialized with this value. */
const int JOBS_NR_MIN = 1; /*! Public const int. Default lower bound of number of simulated jobs. The configuration value is initialized with this value. */
const int JOBS_NR_MAX = 1000; /*! Public const int. Default upper bound of number of simulated jobs. The configuration value is initialized with this value. */


const double USAGE_PRICE = 0.05 / 60 / 60; /*! Public const double. Default usage price. The configuration value is initialized with this value. Cost per core second. Same price as ARCHER. */
const double USAGE_PRICE_MIN = 0.000001; /*! Public const double. Default lower bound of usage price. The configuration value is initialized with this value. */
const double USAGE_PRICE_MAX = 5.000000; /*! Public const double. Default upper bound of usage price. The configuration value is initialized with this value. */

//! Public const double. The value of energy cost per second.
/*!
	[ENERGY]
	Our computer is a green computer, with a power supply of 60 KW.
	In the UK, the a KW per hour costs £0.0285.
	We get a value of 0.0285 per minute, and 0.0285/60 per second.
*/
const double ENERGY_COST = 0.0285 / 60;

//! Public const double. The value of personel cost per second.
/*!
	[PERSONEL]
	This system has a 10 elements team making £60.000 per year.
*/
const double PERSONEL_COST = 60000 * 10 / 365 / 24 / 60 / 60;

//! Public const double. The value of maintenance per second.
/*
	[MAINTENANCE]
	A building maintenace with an average of £10.000 per year.
*/
const double BUILDING_MAINTENANCE = 10000 / 365 / 24 / 60 / 60;

//! Public const double. The value of operational cost of the system per second.
/*
	Operational cost = Personel cost + Enery cost + Maintenance cost.
*/
const double OPERATIONAL_COST = ENERGY_COST + PERSONEL_COST + BUILDING_MAINTENANCE;
const double OPERATIONAL_COST_MIN = 0.000001; /*! Public const double. Default lower bound of operational cost. The configuration value is initialized with this value. */
const double OPERATIONAL_COST_MAX = 5.000000; /*! Public const double. Default upper bound of operational cost. The configuration value is initialized with this value. */


const double STUDENT_BUDGET = 100.0; /*! Public const double. Default student budget. The configuration value is initialized with this value. */
const double STUDENT_BUDGET_MIN = 1.0; /*! Public const double. Default lower bound of student budget. The configuration value is initialized with this value. */
const double STUDENT_BUDGET_MAX = 1000.0; /*! Public const double. Default upper bound of student budget. The configuration value is initialized with this value. */

const double RESEARCHER_BUDGET = 200.0; /*! Public const double. Default researcher budget. The configuration value is initialized with this value. */
const double RESEARCHER_BUDGET_MIN = 1.0; /*! Public const double. Default lower bound of researcher budget. The configuration value is initialized with this value. */
const double RESEARCHER_BUDGET_MAX = 1000.0; /*! Public const double. Default upper bound of researcher budget. The configuration value is initialized with this value. */

const double IT_BUDGET = DBL_MAX; /*! Public const double. The IT staff budget (infinite). */

const unsigned int FRIDAY = 5; /*! Public const unsigned int. In the Time structure in C++, Friday is represented by 5. */
const unsigned int SATURDAY = 6; /*! Public const unsigned int. In the Time structure in C++, Saturday is represented by 6. */
const unsigned int SUNDAY = 0; /*! Public const unsigned int. In the Time structure in C++, Sunday is represented by 0. */
const unsigned int MONDAY = 1; /*! Public const unsigned int. In the Time structure in C++, Monday is represented by 1. */

const unsigned long long ONE_WEEK = 60 * 60 * 24 * 8; /*! Public const unsigned long long. One week in seconds. */
const unsigned long long ONE_HOUR = 60 * 60; /*! Public const unsigned long long. One hour in seconds. */
const unsigned long long EIGHT_HOURS = 60 * 60 * 8; /*! Public const unsigned long long. Eight hours in seconds. */
const unsigned long long SIXTEEN_HOURS = 60 * 60 * 16; /*! Public const unsigned long long. Sixteen hours in seconds. */
const unsigned long long SIXTY_FOUR_HOURS = 60 * 60 * 64; /*! Public const unsigned long long. Sixty four hours in seconds. */
const unsigned long long ONE_DAY = 60 * 60 * 24; /*! Public const unsigned long long. Onde day in seconds. */

const unsigned long long REQUESTS_SPAN = 10; /*! Public const unsigned long long. Default requests time span. The configuration value is initialized with this value. */
const unsigned long long REQUESTS_SPAN_MIN = 1; /*! Public const unsigned long long. Default requests time span lower bound. The configuration value is initialized with this value. */
const unsigned long long REQUESTS_SPAN_MAX = ONE_WEEK; /*! Public const unsigned long long. Default requests time span upper bound. The configuration value is initialized with this value. */

//! Public method. Method to generate a random integer value following a linear distribution. This value lies between a lower and upper bound.
/*!
	\param int low. Lower bound.
	\param int high. Upper bound.
	\return int. Randomly generated integer value.
	\sa unsigned int generate_random(unsigned int low, unsigned int high)
	\sa double generate_random(double low, double high)
*/
int generate_random(int low, int high);

//! Public method. Method to generate a random unsigned integer value following a linear distribution. This value lies between a lower and upper bound.
/*!
	\param unsigned int low. Lower bound.
	\param unsigned int high. Upper bound.
	\return unsigned int. Randomly generated unsigned integer value.
	\sa int generate_random(int low, int high)
	\sa double generate_random(double low, double high)
*/
unsigned int generate_random(unsigned int low, unsigned int high);

//! Public method. Method to generate a random double value following a linear distribution. This value lies between a lower and upper bound.
/*!
	\param double low. Lower bound.
	\param double high. Upper bound.
	\return double. Randomly generated double value.
	\sa int generate_random(int low, int high)
	\sa unsigned int generate_random(unsigned int low, unsigned int high)
*/
double generate_random(double low, double high);

//! Public method. Method to check if a job runs through the weekend.
/*!
	\param time_t start. Starting time of a job.
	\param time_t end. Ending time of a job.
	\return bool. True if it does, false if doesn't.
	\sa bool is_weekend(time_t start)
*/
bool is_weekend(time_t start, time_t end);

//! Public method. Method to check if a job starts in a weekend.
/*!
	\param time_t start. Starting time of a job.
	\return bool. True if it does, false if doesn't.
	\sa bool is_weekend(time_t start, time_t end)
*/
bool is_weekend(time_t start);

//! Public method. Advances a given time until Monday at 9:00.
/*!
	\param time_t start. Starting time of a job.
	\return time_t. Next Monday at 9:00 in UNIX timestamp.
*/
time_t advance_weekend(time_t start);

//! Public method. Advances a given time until Friday at 17:00.
/*!
	\param time_t start. Starting time of a job.
	\return time_t. Next Friday at 17:00 in UNIX timestamp.
*/
time_t advance_to_friday(time_t start);

//! Public method. Returns a given time to Monday at 9:00.
/*!
	\param time_t start. Starting time of a job.
	\return time_t. Previous Monday at 9:00 in UNIX timestamp.
*/
time_t get_back_to_monday(time_t start);

#endif

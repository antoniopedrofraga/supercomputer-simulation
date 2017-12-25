#ifndef JOB_H //Define header if it's not defined
#define JOB_H

using namespace std;
#include <string>
#include <ctime>
#include "../utils/utils.h"
#include "../configuration/configuration.h"
#include "type.h"
class User;

//! Job class
/*!
  This object represents a job submited by an user.
 */
class Job {
private:
	Configuration * config; /*! Private Config. Object containing the configuration of a simulation. */
	Type type; /*! Private Type. Type of job {Short, Medium, Large, Huge}. */
	User * user; /*! Private User*. User who submited the job. */
	time_t time; /*! Private time_t. Submission date. */
	unsigned long long int duration; /*! Private unsigned long long int. Job duration. */
	int cores; /*! Private int. Computational resources taken by this job in cores. */
public:
	//! Job object default contructor.
    /*!
      Initializes a Job object.
      \param Configuration* config. Defines which configuration this job should follow.
      \param time_t time. Submission date of job.
      \param unsigned long long int duration. Job duration in seconds.
    */
	Job(Configuration * config, time_t time, unsigned long long int duration);
	
	//! Public method. Returns the submission time of a job.
    /*!
      \return time_t. Date represented in UNIX timestamp.
    */
	time_t get_time();

	//! Public method. Returns the duration of a job.
    /*!
      \return unsigned long long int. Duration of job.
    */
	unsigned long long int get_duration();

	//! Public method. Returns the number of cores taken to run this job.
    /*!
      \return int. Number of cores.
    */
	int get_cores();

	//! Public method. Returns the price to be paid to run this job.
    /*!
      \return double. Price to be paid by a simulated user.
    */
	double get_price();

	//! Public method. Defines the user who submits the job.
    /*!
      \param User* user. User who submits the job.
    */
	void set_user(User * user);

	//! Public method. Return whether a job is Short or not.
    /*!
      \return bool. True if yes, false if it's not.
    */
	bool is_short();

	//! Public method. Return whether a job is Medium or not.
    /*!
      \return bool. True if yes, false if it's not.
    */
	bool is_medium();

	//! Public method. Return whether a job is Large or not.
    /*!
      \return bool. True if yes, false if it's not.
    */
	bool is_large();

	//! Public method. Return whether a job is Huge or not.
    /*!
      \return bool. True if yes, false if it's not.
    */
	bool is_huge();
	
	//! Operator overload. Overloads the < operator according to time of submission.
    /*!
      \param Job & job. Object to be compared to.
      \return bool. Less condition result according to time of submission.
    */
	const bool inline operator<(const Job & job) const {
		return this->time < job.time;
	}
};

#endif

#ifndef STATE_H //Define header if it's not defined
#define STATE_H

using namespace std;
#include <string>
#include <iostream>
#include "statetype.h"
#include "../jobs/job.h"

using namespace std;

//! State class
/*!
  This object represents a the number of cores available in each queue at every start time and end time of a job.
 */
class State {
private:
	long long int short_cores; /*! Private long long int. Number of short cores available. */
	long long int medium_cores; /*! Private long long int. Number of medium cores available. */
	long long int large_cores; /*! Private long long int. Number of large cores available. */
	long long int total_cores; /*! Private long long int. Number of huge cores available. */

	long long int used_cores; /*! Private long long int. Total number of used cores. */

	StateType state_type; /*! Private StateType. Type defining whether it is a start or an end. */

	time_t time; /*! Private time_t. Time which this state occurs reprensented in UNIX timestamp. */
public:
	//! State object default contructor.
    /*!
      Initializes a Job object.
      \param long long int total_cores. Total number of system cores.
      \param time_t time. Date of occurence.
      \param StateType state_type. StateType indicating whether a job starts or ends.
    */
	State(long long int total_cores, time_t time, StateType state_type);

	//! State object alternative contructor.
    /*!
      Initializes a Job object.
      \param State state. State to copy cat.
      \param time_t time. Date of occurence.
      \param StateType state_type. StateType indicating whether a job starts or ends.
    */
	State(State state, time_t time, StateType state_type);

	//! Public method. Defines the period of life of a state.
    /*!
      \param time_t start. Starting time.
      \param time_t end. Ending time.
    */
	void set_period(time_t start, time_t end);

	//! Public method. Decreases number of available cores according to job type.
    /*!
      \param Job job. Job object containing information about what amount of computational resources to be decreased.
    */
	void insert_job(Job job);

	//! Public method. Indicates whether a job can be inserted in this state or not.
    /*!
      \param Job job. Job object containing information about what amount of computational resources to be decreased.
      \return bool. True if job can be inserted, false if can not.
    */
	bool can_insert_job(Job job);

	//! Public method. Returns the state time of occurence.
    /*!
      \return time_t. Date in UNIX timestamp.
    */
	time_t get_time();

	//! Public method. Returns the state time of occurence.
    /*!
      \return time_t. Date in UNIX timestamp.
    */
	string get_name();

	//! Public method. Returns type of state.
    /*!
      \return StateType. Start or End.
    */
	StateType get_type();

	//! Public method. Returns available number of cores reserved for short jobs.
    /*!
      \return ong long int. Number of cores.
    */
	long long int get_short_cores();

	//! Public method. Returns available number of cores reserved for medium jobs.
    /*!
      \return ong long int. Number of cores.
    */
	long long int get_medium_cores();

	//! Public method. Returns available number of cores reserved for large jobs.
    /*!
      \return ong long int. Number of cores.
    */
	long long int get_large_cores();

	//! Public method. Returns total number of cores.
    /*!
      \return ong long int. Number of cores.
    */
	long long int get_total_cores();

	//! Public method. Returns total number of used cores.
    /*!
      \return ong long int. Number of cores.
    */
	long long int get_used_cores();

};

#endif
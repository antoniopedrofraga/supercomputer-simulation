#ifndef SYSTEM_H //Define header if it's not defined
#define SYSTEM_H

#include <vector>
#include <set>
#include <sstream>
#include <ctime>
#include <algorithm>

#include "../users/user.h"
#include "../jobs/job.h"
#include "../utils/utils.h"
#include "../statistics/statistics.h"
#include "../configuration/configuration.h"
#include "state.h"

using namespace std;

//! System class
/*!
  This object represents the computing system.
 */
class System {
private:
	vector<User *> users; /*! Private vector<User *>. Vector of simulated users. */
	vector<Job> jobs; /*! Private vector<Job>. Vector of simulated jobs. */
	vector<State> states; /*! Private vector<State>. Vector of states. */

	Configuration * config; /*! Private Configuration. Object containing the configuration of the simulation. */
	Statistics * statistics; /*! Private Statistics. Object containing organized and structured information about the simulation. */

	unsigned long long int total_cores_nr; /*! Private unsigned long long int. System total number of cores. */

	//! Private method. Inserts a state in the states vector.
    /*!
      \param int &index. Index of the new state.
      \param Job job. Job related to state.
    */
	void insert_state(int &index, Job job);

	//! Private method. Inserts a short, medium or large job according to its characteristics (submission date, duration, computational resources).
    /*!
      \param time_t start. Submission date.
      \param int i. Index to start iterate in the states vector.
      \param Job job. Job to be inserted.
    */
	void insert_week_state(time_t start, int i, Job job);

	//! Private method. Inserts a huge job according to its characteristics (submission date, duration, computational resources).
    /*!
      \param time_t start. Submission date.
      \param int i. Index to start iterate in the states vector.
      \param Job job. Job to be inserted.
    */
	void insert_weekend_state(time_t start, int i, Job job);

	//! Private method. Returns true if simulation has states with negative computational resources.
    /*!
      \return bool. True if yes, false if no.
    */
	bool exist_negatives();

	//! Private method. Populates vector of users.
	void create_users();

	//! Private method. Populates vector of jobs.
	void create_jobs();

	//! Private method. Calculates operational cost and updates the statistics object.
	void calculate_op_cost();

	//! Private method. Runs scheduler algorithm.
	void schedule();

	//! Private method. Inserts state in vector of states, updating the computational resources in every state from index i to j.
	/*!
      \param int i. Lower bound of states to be updated.
      \param int j. Upper bound of states to be updated.
      \param time_t start. Starting time of job.
      \param time_t end. Ending time of job.
      \param Job job. Job to be inserted.
    */
	void insert_state_and_update(int i, int j, time_t start, time_t end, Job job);
public:
	//! System object default contructor.
    /*!
      Initializes a System object.
      \param Configuration * config. Configuration to be followed by the simulation.
    */
	System(Configuration * config);

	//! System object contructor for custom tests.
    /*!
      Initializes a System object.
      \param Configuration * config. Configuration to be followed by the simulation.
      \param vector<User*> users. Simulated users vector.
      \param vector<Job> jobs. Simulated jobs vector.
    */
	System(Configuration * config, vector<User*> users, vector<Job> jobs);

	//! Private method. Fetchs results of statistics object, returning a string with a specific format.
	/*!
      \return string. String with information about the outputs of the simulation.
    */
	string get_results();
};

#endif

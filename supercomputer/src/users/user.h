#ifndef USER_H //Define header if it's not defined
#define USER_H

#include "group.h"
#include "../utils/utils.h"
#include "../jobs/job.h"

//! System class
/*!
  This object represents a simulated user.
*/
class User {
private:
	Configuration * config; /*! Private Configuration. Object containing the configuration of the simulation. */
	int id; /*! Private int. User ID. */
	Group group; /*! Private Group. Simulated group. */
	double budget; /*! Private double. User budget. */

	//! Private method. Generates the group of an user randomly following a linear distribution.
	/*!
		\param bool support. The user is part of the IT Support if true.
	*/
	void generate_group(bool support);
public:
	//! User object default contructor.
	/*!
		Initializes a User object.
		\param Configuration * config. Configuration to be followed by the simulation.
		\param int id. User id, this value is unique between users.
		\param bool support. The user is part of the IT Support if true.
	*/
	User(Configuration * config, int id, bool support);

	//! Public method. Method to check if an User can afford to run a given job.
	/*!
		\param Job * job. Job to be paid.
    	\return bool. True if user can afford the job, false if not.
  	*/
	bool can_afford(Job * job);

	//! Public method. Decreases the user budget according to the price of a job.
	/*!
		\param Job * job. Job to be paid.
  	*/
	void pay(Job * job);
};

#endif
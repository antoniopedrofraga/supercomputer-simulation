#ifndef CONFIGURATION_H //Define header if it's not defined
#define CONFIGURATION_H

#include <ctime>
#include "../utils/utils.h"

//! Configuration class
/*!
  This object includes the input values of the simulation.
 */
class Configuration {
private:
	unsigned int nodes_nr; /*! Private unsigned int. Total number of system nodes. */
	unsigned int cores_nr; /*! Private unsigned int. Total number of cores per node. */

	double usage_price; /*! Private double. Usage price of the system per core second. */
	double operational_cost; /*! Private double. Operational cost of the system per second. */

	double student_budget; /*! Private double. Student budget. */
	double student_budget_min; /*! Private double. Contains the lower limit of the student budget, this value is used when the variable is generated randomly. */
	double student_budget_max; /*! Private double. Contains the upper limit of the student budget, this value is used when the variable is generated randomly. */
	bool student_random; /*! Private bool. The student budget is generated randomly when this variable is set to true. */

	double researcher_budget; /*! Private double. Researcher budget. */
	double researcher_budget_min; /*! Private double. Contains the lower limit of the researcher budget, this value is used when the variable is generated randomly. */
	double researcher_budget_max; /*! Private double. Contains the upper limit of the researcher budget, this value is used when the variable is generated randomly. */
	bool researcher_random; /*! Private bool. The researcher budget is generated randomly when this variable is set to true. */

	unsigned int jobs_nr;  /*! Private double. Number of jobs. */
	unsigned int jobs_nr_min; /*! Private double. Contains the lower limit of jobs number, this value is used when the variable is generated randomly. */
	unsigned int jobs_nr_max; /*! Private double. Contains the upper limit of jobs number, this value is used when the variable is generated randomly. */
	bool jobs_random; /*! Private bool. The number of jobs is generated randomly when this variable is set to true. */

	unsigned int users_nr; /*! Private double. Number of users. */
	unsigned int users_nr_min; /*! Private double. Contains the lower limit of users number, this value is used when the variable is generated randomly. */
	unsigned int users_nr_max; /*! Private double. Contains the upper limit of users number, this value is used when the variable is generated randomly. */
	bool users_random; /*! Private bool. The number of users is generated randomly when this variable is set to true. */

	unsigned long long int requests_span; /*! Private unsigned long long int. Time span of requests in seconds. */

	time_t start; /*! Private time_t. Start time of the simulation. */
	bool now; /*! Private time_t. Start time of the simulation. */
public:
	//! Configuration object default contructor.
    /*!
      Initializes a Configuration object.
    */
	Configuration();

	//! Public method. Returns the number of users when this value is not generated randomly.
    /*!
      \return unsigned int. The number of users.
    */
	unsigned int get_users_nr();

	//! Public method. Returns the lower limit of randomly generated values of number of users.
    /*!
      \return unsigned int. The lower limit.
    */
	unsigned int get_users_nr_min();

	//! Public method. Returns the upper limit of randomly generated values of number of users.
    /*!
      \return unsigned int. The upper limit.
    */
	unsigned int get_users_nr_max();

	//! Public method. Returns true if the number of users is generated randomly, and false if it's not.
    /*!
      \return bool. Number of users randomness.
    */
	bool is_users_nr_random();


	//! Public method. Returns the number of jobs when this value is not generated randomly.
    /*!
      \return unsigned int. The number of jobs.
    */
	unsigned int get_jobs_nr();

	//! Public method. Returns the lower limit of randomly generated values of number of jobs.
    /*!
      \return unsigned int. The lower limit.
    */
	unsigned int get_jobs_nr_min();

	//! Public method. Returns the upper limit of randomly generated values of number of jobs.
    /*!
      \return unsigned int. The upper limit.
    */
	unsigned int get_jobs_nr_max();

	//! Public method. Returns true if the number of jobs is generated randomly, and false if it's not.
    /*!
      \return bool. Number of jobs randomness.
    */
	bool is_jobs_nr_random();


	//! Public method. Returns the number of cores per node.
    /*!
      \return unsigned int. The number of cores per node.
    */
	unsigned int get_cores_nr();

	//! Public method. Returns the total number of system nodes.
    /*!
      \return unsigned int. The number of nodes.
    */
	unsigned int get_nodes_nr();

	//! Public method. Returns the usage price of the system per core second.
    /*!
      \return double. Usage price of the system per core second.
    */
	double get_usage_price();

	//! Public method. Returns the operational cost of the system per second.
    /*!
      \return double. Operational cost of the system per second.
    */
	double get_operational_cost();

	//! Public method. Returns the student budget.
    /*!
      \return double. Student budget value.
    */
	double get_student_budget();

	//! Public method. Returns the lower limit of randomly generated values of student budget.
    /*!
      \return double. The lower limit of student budget.
    */
	double get_student_budget_min();

	//! Public method. Returns the upper limit of randomly generated values of student budget.
    /*!
      \return double. The upper limit of student budget.
    */
	double get_student_budget_max();

	//! Public method. Returns true if the student budget is generated randomly, and false if it's not.
    /*!
      \return bool. Student budget randomness.
    */
	bool is_student_budget_random();

	//! Public method. Returns the researcher budget.
    /*!
      \return double. Student budget value.
    */
	double get_researcher_budget();

	//! Public method. Returns the lower limit of randomly generated values of researcher budget.
    /*!
      \return double. The lower limit of researcher budget.
    */
	double get_researcher_budget_min();

	//! Public method. Returns the upper limit of randomly generated values of researcher budget.
    /*!
      \return double. The upper limit of researcher budget.
    */
	double get_researcher_budget_max();

	//! Public method. Returns true if the researcher budget is generated randomly, and false if it's not.
    /*!
      \return bool. Researcher budget randomness.
    */
	bool is_researcher_budget_random();

	//! Public method. Returns the starting time of the simulation in UNIX timestamp format.
    /*!
      \return time_t. Starting time of the simulation.
    */
	time_t get_time();

	//! Public method. Returns the requests time span in seconds.
    /*!
      \return time_t. Requests time span.
    */
	unsigned long long int get_requests_span();

	//! Public method. Changes the way the student budget is defined.
    /*!
      \param bool random. True if random generated, false if constant.
    */
	void set_student_random(bool random);

    //! Public method. Changes the way the researcher budget is defined.
    /*!
      \param bool random. True if random generated, false if constant.
    */
	void set_researcher_random(bool random);

	//! Public method. Changes the way the number of users is defined.
    /*!
      \param bool random. True if random generated, false if constant.
    */
	void set_users_random(bool random);

	//! Public method. Changes the way the number of jobs is defined.
    /*!
      \param bool random. True if random generated, false if constant.
    */
    void set_jobs_random(bool random);

    //! Public method. Changes whether the simulation starting time is the present date or not.
    /*!
      \param bool now. True if the date is the present, false if not.
    */
	void set_now(bool now);

	//! Public method. Defines a date value for non-present starting dates simulations.
    /*!
      \param time_t time. Value of date in UNIX timestamp format.
    */
	void set_time(time_t time);

	//! Public method. Defines the usage price of the system per core second.
    /*!
      \param double usage_price. New value of usage price.
    */
	void set_usage_price(double usage_price);

	//! Public method. Defines the operational cost of the system per core second.
    /*!
      \param double usage_price. New value of operational cost.
    */
	void set_operational_cost(double operational_cost);

	//! Public method. Defines the total number of system nodes.
    /*!
      \param unsigned int nodes_nr. New value of total number of system nodes.
    */
	void set_nodes_nr(unsigned int nodes_nr);

	//! Public method. Defines the number of cores per node.
    /*!
      \param unsigned int nodes_nr. New value of number of cores per node.
    */
	void set_cores_nr(unsigned int cores_nr);

	//! Public method. Defines the student budget of a new simulation.
    /*!
      \param double budget. New value of student budget.
    */
	void set_student_budget(double budget);

	//! Public method. Defines the lower limit student budgets when this value is randomly generated.
    /*!
      \param double min. New value of lower limit.
    */
	void set_student_budget_min(double min);

	//! Public method. Defines the upper limit student budgets when this value is randomly generated.
    /*!
      \param double max. New value of upper limit.
    */
	void set_student_budget_max(double max);

	//! Public method. Defines the researcher budget of a new simulation.
    /*!
      \param double budget. New value of researcher budget.
    */
	void set_researcher_budget(double budget);

	//! Public method. Defines the lower limit researcher budgets when this value is randomly generated.
    /*!
      \param double min. New value of lower limit.
    */
	void set_researcher_budget_min(double min);

	//! Public method. Defines the upper limit researcher budgets when this value is randomly generated.
    /*!
      \param double max. New value of upper limit.
    */
	void set_researcher_budget_max(double max);

	//! Public method. Defines the number of jobs of a new simulation.
    /*!
      \param unsigned int budget. New value of jobs number.
    */
	void set_jobs_nr(unsigned int nr);

	//! Public method. Defines the lower limit of jobs when this value is randomly generated.
    /*!
      \param unsigned int min. New value of lower limit.
    */
	void set_jobs_nr_min(unsigned int min);

	//! Public method. Defines the upper limit of jobs when this value is randomly generated.
    /*!
      \param unsigned int max. New value of upper limit.
    */
	void set_jobs_nr_max(unsigned int max);

	//! Public method. Defines the number of users of a new simulation.
    /*!
      \param unsigned int budget. New value of users number.
    */
	void set_users_nr(unsigned int nr);

	//! Public method. Defines the lower limit of users when this value is randomly generated.
    /*!
      \param unsigned int min. New value of lower limit.
    */
	void set_users_nr_min(unsigned int min);

	//! Public method. Defines the upper limit of users when this value is randomly generated.
    /*!
      \param unsigned int max. New value of upper limit.
    */
	void set_users_nr_max(unsigned int max);


	//! Public method. Defines the requests time span.
    /*!
      \param unsigned long long int span. New value of requests time span.
    */
	void set_requests_span(unsigned long long int span);
};
#endif
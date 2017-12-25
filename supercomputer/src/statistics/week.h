#ifndef WEEK_H //Define header if it's not defined
#define WEEK_H

#include "../jobs/job.h"
#include <ctime>
#include <string>

//! Week class
/*!
  This object keeps information about number of jobs processed in a week by each queue.
 */
class Week {
private:
	time_t start; /*! Private time_t. Timestamp representing the starting date of week. */
	time_t end; /*! Private time_t. Timestamp representing the ending date of week. */

	unsigned int short_nr; /*! Private unsigned int. Number of short jobs processed. */
	unsigned int medium_nr; /*! Private unsigned int. Number of medium jobs processed. */
	unsigned int large_nr; /*! Private unsigned int. Number of large jobs processed. */
	unsigned int huge_nr; /*! Private unsigned int. Number of huge jobs processed. */
public:
	//! Week object default contructor.
    /*!
      Initializes a Week object.
      \param time_t start. Defines the stating date of the week.
      \param time_t end. Defines the ending date of the week.
    */
	Week(time_t start, time_t end);

	//! Public method. Returns the starting date of a job.
    /*!
      \return time_t. Date represented in UNIX timestamp.
    */
	time_t get_start();

	//! Public method. Returns the ending date of a job.
    /*!
      \return time_t. Date represented in UNIX timestamp.
    */
	time_t get_end();

	//! Public method. Defines new starting date of a week.
    /*!
      \param time_t start. Starting date represented in UNIX timestamp.
    */
	void set_start(time_t start);

	//! Public method. Defines new starting date of a week.
    /*!
      \param time_t start. Starting date represented in UNIX timestamp.
    */
	void add_job(Job job);

	//! Operator overload. Overloads the << operator of a Week object.
    /*!
      \param ostream& os. Ostream.
      \param const Week& week. Week to be converted.
      \return ostream&. Week object converted to ostream.
    */
	friend ostream& operator<<(ostream& os, const Week& week);
};

#endif
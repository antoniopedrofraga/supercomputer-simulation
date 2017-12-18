#include "utils.h"

using namespace std;

int generate_random(int low, int high) {
	mt19937 rng;
	rng.seed(std::random_device()());
	uniform_int_distribution<mt19937::result_type> distribution(low, high);
	return distribution(rng);
}

double generate_random(double low, double high) {
	std::default_random_engine rng;
	uniform_real_distribution<double> distribution(low, high);
	return distribution(rng);
}

//bool compare_state_ptr(State* a, State* b) { return (*a < *b); }

/*
	Sunday = 0, Monday = 1, Tuesday = 2, Wednesday = 3 (...)
*/
bool is_weekend(time_t start, time_t end) {
	struct tm *tm_start = localtime(&start), *tm_end = localtime(&end);
	unsigned int start_day = tm_start->tm_wday, end_day = tm_end->tm_wday, 
	start_hour = tm_start->tm_hour, end_hour = tm_end->tm_hour;
	if (start_day == SATURDAY || end_day == SATURDAY) {
		return true;
	} else if (start_day == FRIDAY && start_hour >= 17 || end_day == FRIDAY && end_hour >= 17) {
		return true;
	} else if (start_day == SUNDAY && start_hour < 9 || end_day == SUNDAY && end_hour < 9) {
		return true;
	}
	return false;
}

bool is_weekend(time_t start) {
	struct tm *tm_start = localtime(&start);
	unsigned int start_day = tm_start->tm_wday, start_hour = tm_start->tm_hour;
	if (start_day == SATURDAY) {
		return true;
	} else if (start_day == FRIDAY && start_hour >= 17) {
		return true;
	} else if (start_day == SUNDAY && start_hour < 9) {
		return true;
	}
	return false;
}

time_t advance_weekend(time_t start) {
	struct tm *tm_start = localtime(&start);
	while (tm_start->tm_wday != SUNDAY) {
		start += ONE_DAY;
		tm_start = localtime(&start);
	}
	tm_start->tm_hour = 9;
	tm_start->tm_min = 0;
	tm_start->tm_sec = 0;
	return mktime(tm_start);
}

time_t advance_to_friday(time_t start) {
	struct tm *tm_start = localtime(&start);
	if (tm_start->tm_wday == FRIDAY && tm_start->tm_hour >= 17) {
		start += ONE_DAY;
		tm_start = localtime(&start);
	}
	while (tm_start->tm_wday != FRIDAY) {
		start += ONE_DAY;
		tm_start = localtime(&start);
	}
	tm_start->tm_hour = 17;
	tm_start->tm_min = 0;
	tm_start->tm_sec = 0;
	return mktime(tm_start);
}

void print_queues_stats() {
	cout << "   ____                                _____ _        _ " << endl      
		<< "  / __ \\                              / ____| |      | |      " << endl
		<< " | |  | |_   _  ___ _   _  ___  ___  | (___ | |_ __ _| |_ ___ " << endl
		<< " | |  | | | | |/ _ \\ | | |/ _ \\/ __|  \\___ \\| __/ _` | __/ __|" << endl
		<< " | |__| | |_| |  __/ |_| |  __/\\__ \\  ____) | || (_| | |_\\__ \\ " << endl
  		<< "  \\___\\_\\\\__,_|\\___|\\__,_|\\___||___/ |_____/ \\__\\__,_|\\__|___/" << endl
  		<< endl << endl;
}
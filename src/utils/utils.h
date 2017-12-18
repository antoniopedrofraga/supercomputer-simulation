#ifndef UTILS_H
#define UTILS_H

//#include "../system//state.h"
#include <random>
#include <float.h>
#include <vector>
#include <iostream>

const int NODES_NR = 128;
const int CORES_NR = 16;

/*
Cost per core, per hour. Same price as ARCHER.
*/
const double USAGE_PRICE = 0.05 / 60 / 60;
/*
[ENERGY]
Our computer is a green computer, with a power supply of 60 KW
In the UK, the a KW per hour costs £0.0285.
We get a value of 0.0285 per minute, and 0.0285/60 per second
*/
const double ENERGY_COST = 0.0285 / 60;
/*
[PERSONEL]
This system has a 6 elements team winning £60.000 per year
*/
const double PERSONEL_COST = 60000 * 6 / 365 / 24 / 60 / 60;
/*
We shall ignore the building maintenance. It won't add a sgnificantly high price to everything
*/
const double OPERATIONAL_COST = ENERGY_COST + PERSONEL_COST;

const double STUDENT_BUDGET = 100.0;
const double RESEARCHER_BUDGET = 200.0;
const double IT_BUDGET = DBL_MAX;

const int LOW_JOBS = 20;
const int HIGH_JOBS = 500;

const unsigned int FRIDAY = 5;
const unsigned int SATURDAY = 6;
const unsigned int SUNDAY = 0;

const unsigned long long ONE_WEEK = 60 * 60 * 24 * 8;
const unsigned long long ONE_HOUR = 60 * 60;
const unsigned long long EIGHT_HOURS = 60 * 60 * 8;
const unsigned long long SIXTEEN_HOURS = 60 * 60 * 16;
const unsigned long long THIRTY_EIGHT_HOURS = 60 * 60 * 38;
const unsigned long long ONE_DAY = 60 * 60 * 24;

int generate_random(int low, int high);
double generate_random(double low, double high);
bool is_weekend(time_t start, time_t end);
bool is_weekend(time_t start);
time_t advance_weekend(time_t start);
time_t advance_to_friday(time_t start);
void print_queues_stats();
//bool compare_state_ptr(State* a, State* b);

#endif

#ifndef UTILS_H
#define UTILS_H

#include <random>

const int NODES_NR = 128;
const int CORES_NR = 16;

const double USAGE_PRICE = 0.03;
const double OPERATIONAL_COST = 0.01;

const double LOW_BUDGET = 10.0;
const double HIGH_BUDGET = 100.0;

const int LOW_JOBS = 20;
const int HIGH_JOBS = 500;

const unsigned int FRIDAY = 5;
const unsigned int SATURDAY = 6;
const unsigned int SUNDAY = 0;

const unsigned long long ONE_WEEK = 60 * 60 * 24 * 8;
const unsigned long long ONE_HOUR = 60 * 60;
const unsigned long long EIGHT_HOURS = 60 * 60 * 8;
const unsigned long long SIXTEEN_HOURS = 60 * 60 * 16;
const unsigned long long TWENTY_SEVEN_HOURS = 60 * 60 * 27;

int generate_random(int low, int high);
double generate_random(double low, double high);
bool is_weekend(time_t start, time_t end);

#endif

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

const unsigned long long ONE_WEEK = 60 * 60 * 24 * 8;

int generate_random(int low, int high);
double generate_random(double low, double high);

#endif

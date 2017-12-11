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
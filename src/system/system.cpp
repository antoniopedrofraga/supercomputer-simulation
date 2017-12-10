#include "system.h"

System::System() {

	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> nodes_distribution(128, 1024);
	std::uniform_int_distribution<std::mt19937::result_type> cores_distribution(16, 128);

	int nodes_nr = nodes_distribution(rng);
	int cores_nr = cores_distribution(rng);

	cout << "Created a system with " << nodes_nr << " nodes, each one with " << cores_nr << " cores" << endl;
}
#include "system.h"

System::System() {
	usage_price = USAGE_PRICE;
	operational_cost = OPERATIONAL_COST;

	create_cores();
	create_users();
}

void System::create_cores() {
	for (int i = 0; i < NODES_NR; i++) {
		nodes.push_back(new Node(CORES_NR));
	}
}

void System::create_users() {
	mt19937 rng;
	rng.seed(std::random_device()());
	uniform_int_distribution<mt19937::result_type> user_distribution(1, 100);
	int user_nr = user_distribution(rng);

	for (int i = 0; i < user_nr; i++) {
		
	}
}
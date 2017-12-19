#include "system/system.h"
#include "configuration/configuration.h"
#include <ctime>

using namespace std;

int main() {
	Configuration * config = new Configuration();
	config->set_jobs_nr(10);
	System * system = new System(config);
	cout << system->get_results();
	return 0;
}
#include "system/system.h"
#include "configuration/configuration.h"
#include <ctime>

using namespace std;

int main() {
	Configuration * config = new Configuration();
	config->set_jobs_nr(100);
	vector<User*> users = {new User(config, 0, false), new User(config, 1, true)};
	vector<Job> jobs = { *(new Job(config, time(0), THIRTY_EIGHT_HOURS)), *(new Job(config, time(0), ONE_HOUR)), *(new Job(config, time(0), ONE_HOUR))};
	System * system = new System(config);
	cout << system->get_results();
	return 0;
}
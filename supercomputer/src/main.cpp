#include "system/system.h"
#include "configuration/configuration.h"
#include <regex>

using namespace std;

/*!
  Creates a simulation with the default values. 
*/
int main(int argc, char ** argv) {
	Configuration * config = new Configuration();
	System * system = new System(config);
	cout << system->get_results();
	return 0;
}
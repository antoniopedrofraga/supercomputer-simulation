//#include "libs/gnuplot-iostream.h"
#include "system/system.h"
#include "configuration/configuration.h"
#include <ctime>

using namespace std;

int main() {
	Configuration * config = new Configuration();
	System * system = new System(config);
	cout << system->get_results();
	return 0;
}
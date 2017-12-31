#include "system/system.h"
#include "configuration/configuration.h"
#include <regex>

using namespace std;

/*!
  Creates a simulation with the default values. 
*/
int main() {
	string text = string("Is sorted: true\n\nExist negatives: false\n\n")
	+ string("Machine time consumed by jobs: ?[0-9]*\\.?[0-9]+ days, ?[0-9]*\\.?[0-9]+ hours, ?[0-9]*\\.?[0-9]+ minutes, ?[0-9]*\\.?[0-9]+ seconds. +?\n\n")
	+ string("Price paid by users: £?[0-9]*\\.?[0-9]+\n\nOperational Cost: £?[0-9]*\\.?[0-9]+\n\n")
	+ string("Economic Balance: £?[0-9]*\\.?[0-9]+\n\n")
	+ string("Average waiting time \\(seconds\\): Short\\(?[0-9]*\\.?[0-9]+\\), Medium\\(?[0-9]*\\.?[0-9]+\\), Large\\(?[0-9]*\\.?[0-9]+\\), Huge\\(?[0-9]*\\.?[0-9]+\\)\n\n")
	+ string("Average turnaround ratio: Short\\(?[0-9]*\\.?[0-9]+\\), Medium\\(?[0-9]*\\.?[0-9]+\\), Large\\(?[0-9]*\\.?[0-9]+\\), Huge\\(?[0-9]*\\.?[0-9]+\\)\n\n\n")
	+ string("Queues weekly usage: \n((Week ?[0-9]+ \\((Mon|Sun|Tue|Wed|Thu|Fri|Sat), ?[0-9]+.?[0-9]+.?[0-9]+ ?[0-9]+:?[0-9]+:?[0-9]+ to (Mon|Sun|Tue|Wed|Thu|Fri|Sat), ?[0-9]+\\.?[0-9]+\\.?[0-9]+ ?[0-9]+:?[0-9]+:?[0-9]+\\)")
	+ string(" Short\\(?[0-9]+\\) Medium\\(?[0-9]+\\) Large\\(?[0-9]+\\) Huge\\(?[0-9]+\\) \n)+)\n");
	regex pattern(text);

	int count = 0;
	for (int i = 0; i < 1000; i++) {
		Configuration * config = new Configuration();
		System * system = new System(config);
		if (!regex_match(system->get_results(), pattern)) {
			cout << "FALSE: " << count << endl;
			cout << system->get_results();
			exit(1);
		}
		count++;
	}
	cout << "TRUE" << endl;
	return 0;
}
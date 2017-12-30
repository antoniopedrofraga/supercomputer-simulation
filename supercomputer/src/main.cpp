#include "system/system.h"
#include "configuration/configuration.h"
#include "libs/gnuplot-iostream.h"
#include <regex>

using namespace std;

/*!
  Creates a simulation with the default values. 
*/
int main() {
	/*string text = string("Is sorted: true\n\nExist negatives: false\n\n")
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
	return 0;*/
	for (int lambda = 1; lambda <= 20; lambda++) {
		random_device rd; 
		exponential_distribution<double> rng(lambda);
		mt19937 rnd_gen(rd());
		
		vector<unsigned long long int> types(4, 0);
		vector<unsigned long long int> durations(SIXTY_FOUR_HOURS, 0);
		for (unsigned long long int i = 0; i < 100000000; i++) {
			double value = rng(rnd_gen);
			while (value > 1.0) { value = rng(rnd_gen); }
			unsigned long long int duration =  value * SIXTY_FOUR_HOURS;
			if (duration <= ONE_HOUR) {
				++types[0];
			} else if (duration > ONE_HOUR && duration <= EIGHT_HOURS) {
				++types[1];
			} else if (duration > EIGHT_HOURS && duration <= SIXTEEN_HOURS) {
				++types[2];
			} else {
				++types[3];
			}
			unsigned int index = value * SIXTY_FOUR_HOURS;
			++durations[index];
		}
		Gnuplot gp;
		gp << "set tics scale 0; set border 3; set style line 1 lc rgb '#0060ad' lt 1 lw 2; set clip two; set ylabel \"Occurences\";set xlabel \"Duration\"; set term png; set xtics (\"Short\" 0, \"Medium\"  1, \"Large\" 2, \"Huge\" 3)\n";
		gp << "set output \"./outputs/types_lambda" + to_string(lambda) + ".png\";\n";
		gp << "plot" << gp.file1d(types) << " notitle with linespoint ls 1" << std::endl;
		gp << "set tics scale 0; set border 3; set style line 1 lc rgb '#0060ad' lt 1 lw 1; set clip two; set ylabel \"Occurences\";set xlabel \"Duration\"; set term png; set xtics (\"1 hour\" " + to_string(ONE_HOUR) + ", \"8 hours\"  " + to_string(EIGHT_HOURS) + ", \"16 hours\" " + to_string(SIXTEEN_HOURS) + ", \"64 hours\" " + to_string(SIXTY_FOUR_HOURS) + ")\n";
		gp << "set output \"./outputs/durations_lambda" + to_string(lambda) + ".png\";\n";
		gp << "plot" << gp.file1d(durations) << " notitle with linespoint ls 1" << std::endl;
	}
}
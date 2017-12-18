//#include "libs/gnuplot-iostream.h"
#include "system/system.h"
#include <ctime>

using namespace std;

int main() {
	new System();
	/*for (int lambda = 1; lambda < 10; lambda++) {
		random_device rd; 
		exponential_distribution<double> rng(lambda);
		mt19937 rnd_gen(rd());
		
		vector<unsigned long long int> types(4, 0);
		vector<unsigned long long int> durations(THIRTY_EIGHT_HOURS, 0);
		for (unsigned long long int i = 0; i < 10000000; i++) {
			double value = rng(rnd_gen);
			while (value > 1.0) { value = rng(rnd_gen); }
			unsigned long long int duration =  value * THIRTY_EIGHT_HOURS;
			if (duration <= ONE_HOUR) {
				++types[0];
			} else if (duration > ONE_HOUR && duration <= EIGHT_HOURS) {
				++types[1];
			} else if (duration > EIGHT_HOURS && duration <= SIXTEEN_HOURS) {
				++types[2];
			} else {
				++types[3];
			}
			++durations[int(value * THIRTY_EIGHT_HOURS)];
		}

		Gnuplot gp;

		gp << "set tics scale 0; set border 3; set style line 1 lc rgb '#0060ad' lt 1 lw 2; set clip two; set ylabel \"Occurences\";set xlabel \"Duration\"; set term png; set xtics (\"Short\" 0, \"Medium\"  1, \"Large\" 2, \"Huge\" 3)\n";
		gp << "set output \"../outputs/types_lambda" + to_string(lambda) + ".png\";\n";
		gp << "plot" << gp.file1d(types) << " notitle with linespoint ls 1" << std::endl;
		gp << "set tics scale 0; set border 3; set style line 1 lc rgb '#0060ad' lt 1 lw 1; set clip two; set ylabel \"Occurences\";set xlabel \"Duration\"; set term png; set xtics (\"1 hour\" " + to_string(ONE_HOUR) + ", \"8 hours\"  " + to_string(EIGHT_HOURS) + ", \"16 hours\" " + to_string(SIXTEEN_HOURS) + ", \"38 hours\" " + to_string(THIRTY_EIGHT_HOURS) + ")\n";
		gp << "set output \"../outputs/durations_lambda" + to_string(lambda) + ".png\";\n";
		gp << "plot" << gp.file1d(durations) << " notitle with linespoint ls 1" << std::endl;
	}*/
	return 0;
}
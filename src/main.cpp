#include "system/system.h"

using namespace std;

int main() {
	System * system = new System();
	/*random_device rd; 
	exponential_distribution<double> rng(6);
	mt19937 rnd_gen(rd());
	
	vector<unsigned long long int> v(4, 0);
	for (unsigned long long int i = 0; i < 100; i++) {
		double value = rng(rnd_gen);
		while (value > 1.0) { value = rng(rnd_gen); }
		unsigned long long int duration =  value * THIRTY_EIGHT_HOURS;
		if (duration <= ONE_HOUR) {
			++v[0];
		} else if (duration > ONE_HOUR && duration <= EIGHT_HOURS) {
			++v[1];
		} else if (duration > EIGHT_HOURS && duration <= SIXTEEN_HOURS) {
			++v[2];
		} else {
			++v[3];
		}
	}

	Gnuplot gp;

	gp << "set tics scale 0; set border 3; set style line 1 lc rgb '#0060ad' lt 1 lw 2; set clip two; set ylabel \"Occurences\";set xlabel \"Duration\"; set term png; set xtics (\"Short\" 0, \"Medium\"  1, \"Large\" 2, \"Huge\" 3)\n";
	gp << "set output \"../outputs/times.png\";\n";
	gp << "plot" << gp.file1d(v) << " notitle with linespoint ls 1" << std::endl;*/
	return 0;
}
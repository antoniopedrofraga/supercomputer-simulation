all: *.cpp
	g++ -std=c++11 -g *.cpp */*.cpp -o ../bin/supercomputer
gnuplot: *.cpp
	g++ -std=c++11 -g *.cpp */*.cpp -o ../bin/supercomputer -lboost_iostreams -lboost_system -lboost_filesystem
run:
	make all
	../bin/supercomputer
all: ./supercomputer/src/*.cpp
	g++ -std=c++14 ./supercomputer/src/*.cpp ./supercomputer/src/*/*.cpp -o ./bin/supercomputer-console 
linux-gui:
	qmake ./supercomputer/supercomputer.pro -r -spec linux-g++-64 CONFIG+=release -o ./bin/linux-gui
windows-gui:
	qmake ./supercomputer/supercomputer.pro -spec win32-g++ CONFIG+=release -o ./bin/windows-gui
run:
	make all
	./bin/supercomputer
testing: ./supercomputer/src/*/*.cpp ./testing/test_*.cpp
	g++ -std=c++14 -g -W ./testing/test_*.cpp ./supercomputer/src/*/*.cpp -o ./bin/test_supercomputer
	./bin/test_supercomputer
testing-coverage:
	g++ -std=c++14 -g -W ./testing/test_*.cpp ./supercomputer/src/*/*.cpp --coverage -o ./bin/test_supercomputer
	./bin/test_supercomputer
	lcov -t "Supercomputer Simulation test coverage" -o ./testing/coverage/total_coverage.info -c -d .
	lcov --remove ./testing/coverage/total_coverage.info '/usr/include/*' '5/*' '*catch.hpp' -o ./testing/coverage/coverage.info
	genhtml -o ./testing/coverage ./testing/coverage/coverage.info
	rm -f -r *.gcda *.gcno
clean:
	rm -f -r ./testing/coverage/*
doxygen:
	doxygen ./documentation/doxygen.config
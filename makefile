all: ./supercomputer/src/*.cpp
	g++ -std=c++14 -g ./supercomputer/src/*.cpp ./supercomputer/src/*/*.cpp -o ./bin/supercomputer
run:
	make all
	./bin/supercomputer
testing: ./supercomputer/src/*/*.cpp ./testing/test_supercomputer.cpp
	g++ -std=c++14 ./testing/test_supercomputer.cpp ./supercomputer/src/*/*.cpp -o ./testing/test_supercomputer
	./testing/test_supercomputer
testing-coverage:
	g++ -std=c++14 ./testing/test_supercomputer.cpp ./supercomputer/src/*/*.cpp -o ./testing/test_supercomputer
	./testing/test_supercomputer
	lcov -t "Supercomputer Simulation test coverage" -o ./data/coverage.info -c -d .
	genhtml -o data ./data/coverage.info
	rm -f -r *.gcda *.gcno
clean:
	rm -f -r ./data/*
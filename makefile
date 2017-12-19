all: ./supercomputer/src/*.cpp
	g++ -std=c++14 -g ./supercomputer/src/*.cpp ./supercomputer/src/*/*.cpp -o ./bin/supercomputer
run:
	make all
	./bin/supercomputer
test-sort:
	g++ -std=c++14 ./test/test_sort_lib.cpp ./sort.cpp -o ./test/test-sort
	./test/test-sort
test-coverage:
	g++ -std=c++14./test/test_sort_lib.cpp ./sort.cpp --coverage -o ./test/test-sort
	./test/test-sort
	lcov -t "Supercomputer Simulation test coverage" -o ./data/coverage.info -c -d .
	genhtml -o data ./data/coverage.info
	rm -f -r *.gcda *.gcno
clean:
	rm -f -r ./data/*
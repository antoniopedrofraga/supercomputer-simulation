#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../sort.h"

using namespace sortlib;

std::vector<int> correct_input1 = {25, 3, -1, 20, 30, -50};
std::vector<int> correct_output1 = {-50, -1, 3, 20, 25, 30};
std::vector<Int> correct_output1_index = {CreateInt(-50, 5), CreateInt(-1, 2), CreateInt(3, 1), CreateInt(20, 3), CreateInt(25, 0), CreateInt(30, 4)};

std::vector<int> correct_input2 = {1000, 20, -3, 5000, 21, 1, -300, -5000};
std::vector<int> correct_output2 = {-5000, -300, -3, 1, 20, 21, 1000, 5000};
std::vector<Int> correct_output2_index = {CreateInt(-5000, 7), CreateInt(-300, 6), CreateInt(-3, 2), CreateInt(1, 5), CreateInt(20, 1), CreateInt(21, 4), CreateInt(1000, 0), CreateInt(5000, 3)};

std::vector<int> wrong_input = {-1, 3, 2};
std::vector<int> wrong_output = {-1, 3, 2};
std::vector<Int> wrong_output_index = {CreateInt(-1, 0), CreateInt(2, 1), CreateInt(3, 2)};

TEST_CASE( "Testing heap sort", "[heap_sort]" ) {
    REQUIRE( heap_sort(correct_input1) == correct_output1);
    REQUIRE( heap_sort(correct_input2) == correct_output2);
    REQUIRE( heap_sort(wrong_input) != wrong_output);
}

TEST_CASE( "Testing insertion sort", "[insertion_sort]" ) {
    REQUIRE( insertion_sort(correct_input1) == correct_output1);
    REQUIRE( insertion_sort(correct_input2) == correct_output2);
    REQUIRE( insertion_sort(wrong_input) != wrong_output);
}

TEST_CASE( "Testing heap sort index", "[heap_sort_index]" ) {
    REQUIRE( sortlib::heap_sort_index(correct_input1) == correct_output1_index);
    REQUIRE( sortlib::heap_sort_index(correct_input2) == correct_output2_index);
    REQUIRE( sortlib::heap_sort_index(wrong_input) != wrong_output_index);
}

TEST_CASE( "Testing insertion sort index", "[insertion_sort_index]" ) {
    REQUIRE( sortlib::insertion_sort_index(correct_input1) == correct_output1_index);
    REQUIRE( sortlib::insertion_sort_index(correct_input2) == correct_output2_index);
    REQUIRE( sortlib::insertion_sort_index(wrong_input) != wrong_output_index);
}

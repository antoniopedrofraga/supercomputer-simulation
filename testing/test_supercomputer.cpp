#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()
#include "test.h"
#include <regex>

using namespace std;

TEST_CASE( "Test Supercomputer With Custom Jobs", "[Supercomputer]" ) {
    Configuration * config = new Configuration();
    time_t time = 1513962000;
    config->set_jobs_nr(6);
    config->set_time(time);
    config->set_now(false);
    vector<User*> users = {new User(config, 0, false), new User(config, 1, true)};
    vector<Job> jobs = { *(new Job(config, time, SIXTY_FOUR_HOURS - ONE_HOUR)), *(new Job(config, time, SIXTY_FOUR_HOURS)), *(new Job(config, time, SIXTY_FOUR_HOURS)), *(new Job(config, time, SIXTY_FOUR_HOURS)), *(new Job(config, time + 1, ONE_HOUR)), *(new Job(config, time + 2, EIGHT_HOURS)), *(new Job(config, time + 3, SIXTEEN_HOURS))};
    System * system = new System(config, users, jobs);

    string text = string("Machine time consumed by jobs: ?[0-9]*\\.?[0-9]+ days, ?[0-9]*\\.?[0-9]+ hours, ?[0-9]*\\.?[0-9]+ minutes, ?[0-9]*\\.?[0-9]+ seconds. +?\n\n")
    + string("Price paid by users: £?[0-9]*\\.?[0-9]+\n\nOperational Cost: £?[0-9]*\\.?[0-9]+\n\n")
    + string("Economic Balance: £?[0-9]*\\.?[0-9]+\n\n")
    + string("Average waiting time \\(seconds\\): Short\\(?[0-9]*\\.?[0-9]+\\), Medium\\(?[0-9]*\\.?[0-9]+\\), Large\\(?[0-9]*\\.?[0-9]+\\), Huge\\(?[0-9]*\\.?[0-9]+\\)\n\n")
    + string("Average turnaround ratio: Short\\(?[0-9]*\\.?[0-9]+\\), Medium\\(?[0-9]*\\.?[0-9]+\\), Large\\(?[0-9]*\\.?[0-9]+\\), Huge\\(?[0-9]*\\.?[0-9]+\\)\n\n\n")
    + string("Queues weekly usage: \n((Week ?[0-9]+ \\((Mon|Sun|Tue|Wed|Thu|Fri|Sat), ?[0-9]+.?[0-9]+.?[0-9]+ ?[0-9]+:?[0-9]+:?[0-9]+ to (Mon|Sun|Tue|Wed|Thu|Fri|Sat), ?[0-9]+\\.?[0-9]+\\.?[0-9]+ ?[0-9]+:?[0-9]+:?[0-9]+\\)")
    + string(" Short\\(?[0-9]+\\) Medium\\(?[0-9]+\\) Large\\(?[0-9]+\\) Huge\\(?[0-9]+\\) \n)+)\n");

    regex pattern(text);
    REQUIRE(regex_match(system->get_results(), pattern));
}

TEST_CASE( "Test Supercomputer With Default Configurations", "[Supercomputer]" ) {
    Configuration * config = new Configuration();
    config->set_jobs_nr(500);

    string text = string("Machine time consumed by jobs: ?[0-9]*\\.?[0-9]+ days, ?[0-9]*\\.?[0-9]+ hours, ?[0-9]*\\.?[0-9]+ minutes, ?[0-9]*\\.?[0-9]+ seconds. +?\n\n")
    + string("Price paid by users: £?[0-9]*\\.?[0-9]+\n\nOperational Cost: £?[0-9]*\\.?[0-9]+\n\n")
    + string("Economic Balance: £?[0-9]*\\.?[0-9]+\n\n")
    + string("Average waiting time \\(seconds\\): Short\\(?[0-9]*\\.?[0-9]+\\), Medium\\(?[0-9]*\\.?[0-9]+\\), Large\\(?[0-9]*\\.?[0-9]+\\), Huge\\(?[0-9]*\\.?[0-9]+\\)\n\n")
    + string("Average turnaround ratio: Short\\(?[0-9]*\\.?[0-9]+\\), Medium\\(?[0-9]*\\.?[0-9]+\\), Large\\(?[0-9]*\\.?[0-9]+\\), Huge\\(?[0-9]*\\.?[0-9]+\\)\n\n\n")
    + string("Queues weekly usage: \n((Week ?[0-9]+ \\((Mon|Sun|Tue|Wed|Thu|Fri|Sat), ?[0-9]+.?[0-9]+.?[0-9]+ ?[0-9]+:?[0-9]+:?[0-9]+ to (Mon|Sun|Tue|Wed|Thu|Fri|Sat), ?[0-9]+\\.?[0-9]+\\.?[0-9]+ ?[0-9]+:?[0-9]+:?[0-9]+\\)")
    + string(" Short\\(?[0-9]+\\) Medium\\(?[0-9]+\\) Large\\(?[0-9]+\\) Huge\\(?[0-9]+\\) \n)+)\n");

    regex pattern(text);
    System * system = new System(config);
    REQUIRE(regex_match(system->get_results(), pattern));
}
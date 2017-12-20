#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../supercomputer/src/system/system.h"

using namespace std;

TEST_CASE( "Test initial configurations", "[Config]" ) {
    Configuration * config = new Configuration();

    REQUIRE(config->get_users_nr() == USERS_NR);
    REQUIRE(config->get_users_nr_min() == USERS_NR_MIN);
    REQUIRE(config->get_users_nr_max() == USERS_NR_MAX);
    REQUIRE(!config->is_users_nr_random());

    REQUIRE(config->get_jobs_nr() == JOBS_NR);
    REQUIRE(config->get_jobs_nr_min() == JOBS_NR_MIN);
    REQUIRE(config->get_jobs_nr_max() == JOBS_NR_MAX);
    REQUIRE(!config->is_jobs_nr_random());

    REQUIRE(config->get_nodes_nr() == NODES_NR);
    REQUIRE(config->get_cores_nr() == CORES_NR);

    REQUIRE(config->get_usage_price() == USAGE_PRICE);
    REQUIRE(config->get_operational_cost() == OPERATIONAL_COST);

    REQUIRE(config->get_researcher_budget() == RESEARCHER_BUDGET);
    REQUIRE(config->get_researcher_budget_min() == RESEARCHER_BUDGET_MIN);
    REQUIRE(config->get_researcher_budget_max() == RESEARCHER_BUDGET_MAX);
    REQUIRE(!config->is_researcher_budget_random());

    REQUIRE(config->get_student_budget() == STUDENT_BUDGET);
    REQUIRE(config->get_student_budget_min() == STUDENT_BUDGET_MIN);
    REQUIRE(config->get_student_budget_max() == STUDENT_BUDGET_MAX);
    REQUIRE(!config->is_student_budget_random());

    REQUIRE(config->get_requests_span() == REQUESTS_SPAN);
    REQUIRE(config->get_time() == time(0));
}

TEST_CASE( "Test configuration changes", "[Config]" ) {
    Configuration * config = new Configuration();

    config->set_users_nr(10);
    REQUIRE(config->get_users_nr() == 10);
    config->set_users_random(true);
    REQUIRE(config->is_users_nr_random());
    config->set_users_nr_max(300);
    config->set_users_nr_min(301);
    REQUIRE(config->get_users_nr_min() < config->get_users_nr_max());
    config->set_users_nr_min(200);
    REQUIRE(config->get_users_nr_min() == 200);
    config->set_users_nr_max(150);
    REQUIRE(config->get_users_nr_min() < config->get_users_nr_max());

    REQUIRE(config->get_users_nr_min() <= config->get_users_nr());
    REQUIRE(config->get_users_nr() <= config->get_users_nr_max());

    config->set_jobs_nr(50);
    REQUIRE(config->get_jobs_nr() == 50);
    config->set_jobs_random(true);
    REQUIRE(config->is_jobs_nr_random());
    config->set_jobs_nr_max(100);
    config->set_jobs_nr_min(101);
    REQUIRE(config->get_jobs_nr_min() < config->get_jobs_nr_max());
    config->set_jobs_nr_min(50);
    REQUIRE(config->get_jobs_nr_min() == 50);
    config->set_jobs_nr_max(49);
    REQUIRE(config->get_jobs_nr_min() < config->get_jobs_nr_max());

    REQUIRE(config->get_jobs_nr_min() <= config->get_jobs_nr());
    REQUIRE(config->get_jobs_nr() <= config->get_jobs_nr_max());

    config->set_nodes_nr(256);
    config->set_cores_nr(64);
    REQUIRE(config->get_nodes_nr() == 256);
    REQUIRE(config->get_cores_nr() == 64);
    config->set_nodes_nr(NODES_NR_MIN - 1);
    REQUIRE(config->get_nodes_nr() == NODES_NR_MIN);
    config->set_nodes_nr(NODES_NR_MAX + 1);
    REQUIRE(config->get_cores_nr() == CORES_NR_MAX);
    config->set_cores_nr(CORES_NR_MIN - 1);
    REQUIRE(config->get_cores_nr() == CORES_NR_MIN);
    config->set_cores_nr(CORES_NR_MAX + 1);
    REQUIRE(config->get_cores_nr() == CORES_NR_MAX);

    config->set_usage_price(1.0);
    REQUIRE(config->get_usage_price() == 1.0);
    config->set_operational_cost(0.5);
    REQUIRE(config->get_operational_cost() == 0.5);

    config->set_researcher_budget(300.0);
    REQUIRE(config->get_researcher_budget() == 300.0);
    config->set_researcher_random(true);
    REQUIRE(config->is_researcher_budget_random());
    config->set_researcher_budget_max(400.0);
    config->set_researcher_budget_min(400.01);
    REQUIRE(config->get_researcher_budget_min() < config->get_researcher_budget_max());
    config->set_researcher_budget_min(100.0);
    config->set_researcher_budget_max(99.0);
    REQUIRE(config->get_researcher_budget_min() < config->get_researcher_budget_max());

    REQUIRE(config->get_researcher_budget_min() <= config->get_researcher_budget());
    REQUIRE(config->get_researcher_budget() <= config->get_researcher_budget_max());

    config->set_student_budget(200.0);
    REQUIRE(config->get_student_budget() == 200.0);
    config->set_student_random(true);
    REQUIRE(config->is_student_budget_random());
    config->set_student_budget_max(250.0);
    config->set_student_budget_min(270.0);
    REQUIRE(config->get_student_budget_min() < config->get_student_budget_max());
    config->set_student_budget_min(100.0);
    config->set_student_budget_max(99.0);
    REQUIRE(config->get_student_budget_min() < config->get_student_budget_max());

    REQUIRE(config->get_student_budget_min() <= config->get_student_budget());
    REQUIRE(config->get_student_budget() <= config->get_student_budget_max());

    config->set_requests_span(20);
    REQUIRE(config->get_requests_span() == 20);

    time_t twenty_seconds_ago = time(0) - 20;
    config->set_now(false);
    config->set_time(twenty_seconds_ago);
    REQUIRE(config->get_time() == twenty_seconds_ago);
}
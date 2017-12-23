#include "test.h"

TEST_CASE( "Test Jobs", "[Job]" ) {
	Configuration * config = new Configuration();
	time_t now = time(0);

	Job * short_job = new Job(config, now, ONE_HOUR);
	Job * medium_job = new Job(config, now, EIGHT_HOURS);
	Job * large_job = new Job(config, now, SIXTEEN_HOURS);
	Job * huge_job = new Job(config, now, SIXTY_FOUR_HOURS);

	REQUIRE(short_job->is_short());
	REQUIRE(medium_job->is_medium());
	REQUIRE(large_job->is_large());
	REQUIRE(huge_job->is_huge());

	REQUIRE(short_job->get_price() == short_job->get_duration() * short_job->get_cores() * config->get_usage_price());
	REQUIRE(medium_job->get_price() == medium_job->get_duration() * medium_job->get_cores() * config->get_usage_price());
	REQUIRE(large_job->get_price() == large_job->get_duration() * large_job->get_cores() * config->get_usage_price());
	REQUIRE(huge_job->get_price() == huge_job->get_duration() * huge_job->get_cores() * config->get_usage_price());

	REQUIRE(short_job->get_time() == now);
	REQUIRE(medium_job->get_time() == now);
	REQUIRE(large_job->get_time() == now);
	REQUIRE(huge_job->get_time() == now);
}
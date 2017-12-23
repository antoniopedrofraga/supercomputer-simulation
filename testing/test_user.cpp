#include "test.h"

TEST_CASE( "Test Users", "[User]" ) {
	Configuration * config = new Configuration();
	time_t now = time(0);
	Job * job = new Job(config, now, SIXTY_FOUR_HOURS);

	User * support = new User(config, 1, true);
	for (int i = 0; i < 20; i++) {
		support->pay(job);
	}
	REQUIRE(support->can_afford(job));
}
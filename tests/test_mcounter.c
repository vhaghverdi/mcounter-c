#include "mcounter.h"
#include "unity.h"

void test_construct_with_args(void)
{
	puts("Creating counter with start value of 5:");
	MCounter mc = mc_new_n(5);
	mc_print(mc);
	TEST_ASSERT_MESSAGE(mc_count(mc) == 5,
			    "Failed to construct with argument.");
	TEST_ASSERT_MESSAGE(mc_error(mc) == false,
			    "Counter should not be in error state.");

	mc_free(&mc);
	TEST_ASSERT_MESSAGE(mc == NULL, "Failed to free and null.");
}

void test_add(void)
{
	puts("Creating new counter:");
	MCounter mc = mc_new();
	mc_print(mc);
	TEST_ASSERT_MESSAGE(mc_count(mc) == 0, "Expected initial count of 0.");
	TEST_ASSERT_MESSAGE(mc_error(mc) == false,
			    "Counter should not be in error state.");

	puts("\nAdd 1:");
	mc_add_1(mc);
	mc_print(mc);
	TEST_ASSERT_MESSAGE(mc_count(mc) == 1, "Count should be 1.");

	puts("\nAdd 10:");
	mc_add_10(mc);
	mc_print(mc);
	TEST_ASSERT_MESSAGE(mc_count(mc) == 11, "Count should be 11.");

	puts("\nAdd 100:");
	mc_add_100(mc);
	mc_print(mc);
	TEST_ASSERT_MESSAGE(mc_count(mc) == 111, "Count should be 111.");

	puts("\nAdd 1000:");
	mc_add_1000(mc);
	mc_print(mc);
	TEST_ASSERT_MESSAGE(mc_count(mc) == 1111, "Count should be 1111.");

	TEST_ASSERT_MESSAGE(mc_error(mc) == false,
			    "Counter should not be in error state.");

	mc_free(&mc);
}

void test_error(void)
{
	puts("Creating new counter:");
	MCounter mc = mc_new();
	mc_print(mc);

	puts("\nAdding 1000 at a time:");
	for (int i = 0; i < 12; i++) {
		puts("\nAdding 1000:");
		mc_add_1000(mc);
		mc_print(mc);
	}

	TEST_ASSERT_MESSAGE(mc_error(mc) == true,
			    "Counter should be in error state.");

	puts("\nResetting:");
	mc_reset(mc);
	mc_print(mc);
	TEST_ASSERT_MESSAGE(mc_count(mc) == 0, "Expected count of 0.");
	TEST_ASSERT_MESSAGE(
		mc_error(mc) == false,
		"Counter should not be in an error state after a reset.");

	mc_free(&mc);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_construct_with_args);
	RUN_TEST(test_add);
	RUN_TEST(test_error);
	return UNITY_END();
}

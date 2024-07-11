#include <criterion/criterion.h>
#include "libft.h"

Test(ft_abs_tests, positive_input) {
	int64_t n = 42;
	cr_assert_eq(ft_abs(n), 42, "Expected absolute value of 42 to be 42");
}

Test(ft_abs_tests, negative_input) {
	int64_t n = -42;
	cr_assert_eq(ft_abs(n), 42, "Expected absolute value of -42 to be 42");
}

Test(ft_abs_tests, zero_input) {
	int64_t n = 0;
	cr_assert_eq(ft_abs(n), 0, "Expected absolute value of 0 to be 0");
}

Test(ft_abs_tests, max_int64_input) {
	int64_t n = INT64_MAX;
	cr_assert_eq(ft_abs(n), INT64_MAX, "Expected absolute value of INT64_MAX to be INT64_MAX");
}

Test(ft_abs_tests, min_int64_input) {
	int64_t n = INT64_MIN;
	// Special case as the absolute value of INT64_MIN is out of range for int64_t
	cr_assert_eq(ft_abs(n), INT64_MIN, "Expected absolute value of INT64_MIN to be INT64_MIN (overflow behavior)");
}

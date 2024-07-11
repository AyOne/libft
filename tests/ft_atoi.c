#include <criterion/criterion.h>
#include "libft.h"

Test(ft_atoi_tests, positive_number)
{
	char *str = "42";
	cr_assert_eq(ft_atoi(str), 42, "Expected atoi of '42' to be 42");
}

Test(ft_atoi_tests, negative_number)
{
	char *str = "-42";
	cr_assert_eq(ft_atoi(str), -42, "Expected atoi of '-42' to be -42");
}

Test(ft_atoi_tests, leading_spaces)
{
	char *str = "   42";
	cr_assert_eq(ft_atoi(str), 42, "Expected atoi of '   42' to be 42");
}

Test(ft_atoi_tests, plus_sign)
{
	char *str = "+42";
	cr_assert_eq(ft_atoi(str), 42, "Expected atoi of '+42' to be 42");
}

Test(ft_atoi_tests, non_numeric_characters)
{
	char *str = "42abc";
	cr_assert_eq(ft_atoi(str), 42, "Expected atoi of '42abc' to stop at first non-numeric and result to be 42");
}

Test(ft_atoi_tests, only_non_numeric_characters)
{
	char *str = "abc";
	cr_assert_eq(ft_atoi(str), 0, "Expected atoi of 'abc' to be 0");
}

#include <criterion/criterion.h>
#include <strings.h>
#include <stdlib.h>
#include <stddef.h>
#include <signal.h>

// Assuming ft_bzero is declared in "libft.h"
#include "libft.h"

#define BSIZE 1024
#define BFSIZE 4096

Test(ft_bzero, basic)
{
	char str[BSIZE];
	char str2[BSIZE];

	memset(str, 'a', BSIZE);
	memset(str2, 'a', BSIZE);

	bzero(str, 20);
	ft_bzero(str2, 20);

	cr_assert_arr_eq(str, str2, BSIZE, "ft_bzero does not zero out the first 20 bytes correctly");
}

Test(ft_bzero, zero_value)
{
	char buff[BSIZE];
	char buff2[BSIZE];

	memset(buff, '\x1', sizeof(buff));
	memset(buff2, '\x1', sizeof(buff2));

	ft_bzero(buff, 0);
	bzero(buff2, 0);

	cr_assert_arr_eq(buff, buff2, BSIZE, "ft_bzero changes something when called with a size of 0");
}

Test(ft_bzero, null, .signal = SIGSEGV)
{
	ft_bzero(NULL, 12);
	cr_assert_fail("ft_bzero does not segfault when null params is sent");
}

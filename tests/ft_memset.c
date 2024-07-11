#include <stddef.h>
#include <signal.h>
#include <criterion/criterion.h>
#include <string.h>
#include <stdlib.h>

// Assuming ft_memset is declared in "libft.h"
#include "libft.h"

#define BSIZE 1024
#define BFSIZE 4096

//void *ft_memset(void *b, int c, size_t len); // Prototype for ft_memset if not included in libft.h

Test(ft_memset, basic)
{
	char b1[BSIZE];
	char b2[BSIZE];

	memset(b1, 'B', BSIZE);
	ft_memset(b2, 'B', BSIZE);

	memset(b1, 'A', 20);
	ft_memset(b2, 'A', 20);

	cr_assert_arr_eq(b1, b2, BSIZE, "ft_memset does not fill a buffer with 'A' correctly");
}

Test(ft_memset, unsigned)
{
	char b1[BSIZE];
	char b2[BSIZE];

	memset(b1, 'B', BSIZE);
	ft_memset(b2, 'B', BSIZE);

	memset(b1, '\200', 22);
	ft_memset(b2, '\200', 22);

	cr_assert_arr_eq(b1, b2, BSIZE, "ft_memset does not handle unsigned char correctly");
}

Test(ft_memset, return_value)
{
	char b[BSIZE];

	char *r1 = memset(b, 'A', 18);
	char *r2 = ft_memset(b, 'A', 18);

	cr_assert_eq(r1, r2, "ft_memset return value is incorrect");

	r1 = memset("", 'A', 0);
	r2 = ft_memset("", 'A', 0);

	cr_assert_eq(r1, r2, "ft_memset return value is incorrect on empty string");
}

Test(ft_memset, fat)
{
	char *b1 = (char *)malloc(sizeof(char) * (BFSIZE + 1));
	char *b2 = (char *)malloc(sizeof(char) * (BFSIZE + 1));

	memset(b1, '\5', BFSIZE);
	ft_memset(b2, '\5', BFSIZE);

	cr_assert_arr_eq(b1, b2, BFSIZE, "ft_memset does not handle large buffer correctly");

	free(b1);
	free(b2);
}

Test(ft_memset, null, .signal = SIGSEGV)
{
	//cr_assert_any_throw(ft_memset(NULL, 'a', 12), "ft_memset should throw when NULL parameter is sent");
	ft_memset(NULL, 'a', 12);
	cr_assert_fail("ft_memset should throw when NULL parameter is sent");
}

Test(ft_memset, zero_value)
{
	char buff[BSIZE];
	char buff2[BSIZE];

	memset(buff, 0, sizeof(buff));
	memset(buff2, 0, sizeof(buff2));

	ft_memset(buff, '\xff', 0);
	memset(buff2, '\xff', 0);

	cr_assert_arr_eq(buff, buff2, BSIZE, "ft_memset changes something when called with a size of 0");
}

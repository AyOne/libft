#include <stdio.h>
#include "libft.h"

int main()
{
	int num = 42;
	char ch = 'A';
	float f = 3.14;
	char *str = "Hello, world!";
	int count = 0;

	ft_printf("Integer: %d\n", num);
	ft_printf("Character: %c\n", ch);
	ft_printf("String: %s\n", str);
	ft_printf("Count: %n", &count);
	ft_printf("%d\n", count);

	return 0;
}
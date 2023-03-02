#include "libft.h"
#include <ctype.h>
#include <stdio.h>

int ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c += ('a' - 'A');
	return (c);
}

int main(void)
{
	printf("ft_tolower: %d\n", ft_tolower('b'));
	printf("tolower: %d\n", tolower('b'));
	printf("----------------\n");

	printf("ft_tolower: %d\n", ft_tolower('g'));
	printf("tolower: %d\n", tolower('g'));
	printf("----------------\n");

	printf("ft_tolower: %d\n", ft_tolower('P'));
	printf("tolower: %d\n", tolower('P'));
	printf("----------------\n");

	printf("ft_tolower: %d\n", ft_tolower('&'));
	printf("tolower: %d\n", tolower('&'));
	printf("----------------\n");

	printf("ft_tolower: %d\n", ft_tolower(3));
	printf("tolower: %d\n", tolower(3));
	printf("----------------\n");

	return (0);
}

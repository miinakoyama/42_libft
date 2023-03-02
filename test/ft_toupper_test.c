#include "libft.h"
#include <ctype.h>
#include <stdio.h>

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c -= ('a' - 'A');
	return (c);
}

int main(void)
{
	printf("ft_toupper: %d\n", ft_toupper('b'));
	printf("toupper: %d\n", toupper('b'));
	printf("----------------\n");

	printf("ft_toupper: %d\n", ft_toupper('g'));
	printf("toupper: %d\n", toupper('g'));
	printf("----------------\n");

	printf("ft_toupper: %d\n", ft_toupper('P'));
	printf("toupper: %d\n", toupper('P'));
	printf("----------------\n");

	printf("ft_toupper: %d\n", ft_toupper('&'));
	printf("toupper: %d\n", toupper('&'));
	printf("----------------\n");

	printf("ft_toupper: %d\n", ft_toupper(3));
	printf("toupper: %d\n", toupper(3));
	printf("----------------\n");

	return (0);
}

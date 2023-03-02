/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:27:05 by miina             #+#    #+#             */
/*   Updated: 2023/02/16 02:18:29 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int	ft_isprint(int c)
{
	return ((' ' <= c && c <= '~'));
}

int main(void)
{
	printf("ft_isprint('A'): %d\n", ft_isprint('A'));
	printf("isprint('A'): %d\n", isprint('A'));
	printf("----------------\n");
	printf("ft_isprint('4'): %d\n", ft_isprint('4'));
	printf("isprint('4'): %d\n", isprint('4'));
	printf("----------------\n");
	printf("ft_isprint('+'): %d\n", ft_isprint('+'));
	printf("isprint('+'): %d\n", isprint('+'));
	printf("----------------\n");
	printf("ft_isprint(2): %d\n", ft_isprint(2));
	printf("isprint(2): %d\n", isprint(2));
	printf("----------------\n");
	printf("ft_isprint(20): %d\n", ft_isprint(20));
	printf("isprint(20): %d\n", isprint(20));
	printf("----------------\n");
	printf("ft_isprint(127): %d\n", ft_isprint(127));
	printf("isprint(127): %d\n", isprint(127));

	return (0);
}
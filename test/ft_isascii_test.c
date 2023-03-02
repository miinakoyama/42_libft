/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:26:59 by miina             #+#    #+#             */
/*   Updated: 2023/02/16 02:16:10 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int	ft_isascii(int c)
{
	return ((0 <= c && c <= 127));
}

int main(void)
{
	printf("ft_isascii('A'): %d\n", ft_isascii('A'));
	printf("isascii('A'): %d\n", isascii('A'));
	printf("----------------\n");
	printf("ft_isascii('='): %d\n", ft_isascii('='));
	printf("isascii('='): %d\n", isascii('='));
	printf("----------------\n");
	printf("ft_isascii('5'): %d\n", ft_isascii('5'));
	printf("isascii('5'): %d\n", isascii('5'));
	printf("----------------\n");
	printf("----------------\n");
	printf("ft_isascii(5): %d\n", ft_isascii(5));
	printf("isascii(5): %d\n", isascii(5));
	printf("----------------\n");
	printf("ft_isascii(-4): %d\n", ft_isascii(-4));
	printf("isascii(-4): %d\n", isascii(-4));
	printf("----------------\n");
	printf("ft_isascii(900): %d\n", ft_isascii(900));
	printf("isascii(900): %d\n", isascii(900));
	printf("----------------\n");
	
	return (0);
}
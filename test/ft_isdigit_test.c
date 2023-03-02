/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:27:02 by miina             #+#    #+#             */
/*   Updated: 2023/02/16 02:16:48 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int main(void)
{
	printf("ft_isdigit('0'): %d\n", ft_isdigit('0'));
	printf("isadigit('0'): %d\n", isdigit('0'));
	printf("----------------\n");
	printf("ft_isdigit('6'): %d\n", ft_isdigit('6'));
	printf("isadigit('6'): %d\n", isdigit('6'));
	printf("----------------\n");
	printf("ft_isdigit('A'): %d\n", ft_isdigit('A'));
	printf("isadigit('A'): %d\n", isdigit('A'));
	printf("----------------\n");
	printf("ft_isdigit('+'): %d\n", ft_isdigit('+'));
	printf("isadigit('+'): %d\n", isdigit('+'));
	printf("----------------\n");

	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:26:51 by miina             #+#    #+#             */
/*   Updated: 2023/02/16 02:19:43 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int ft_isalpha(int c)
{
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}

int ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

// int	ft_isalnum(int c)
// {
// 	if (!('0' <= c && c <= '9'))
// 	{
// 		if (!(('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')))
// 			return (0);
// 	}
// 	return (1);
// }

//書き方かえた
int ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}

int main(void)
{
	printf("ft_isalnum('A'): %d\n", ft_isalnum('A'));
	printf("isalnum('A'): %d\n", isalnum('A'));
	printf("----------------\n");
	printf("ft_isalnum('a'): %d\n", ft_isalnum('a'));
	printf("isalnum('a'): %d\n", isalnum('a'));
	printf("----------------\n");
	printf("ft_isalnum('1'): %d\n", ft_isalnum('1'));
	printf("isalnum('1'): %d\n", isalnum('1'));
	printf("----------------\n");
	printf("ft_isalnum('-'): %d\n", ft_isalnum('-'));
	printf("isalnum('-'): %d\n", isalnum('-'));
	printf("----------------\n");
	printf("ft_isalnum('?'): %d\n", ft_isalnum('?'));
	printf("isalnum('?'): %d\n", isalnum('?'));
	printf("----------------\n");
	printf("ft_isalnum(500): %d\n", ft_isalnum(500));
	printf("isalnum(500): %d\n", isalnum(500));

	return (0);
}
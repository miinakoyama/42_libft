/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miina <miina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:27:40 by miina             #+#    #+#             */
/*   Updated: 2023/02/11 20:26:23 by miina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *str)
{
	size_t count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

int main(void)
{
	const char *str1 = "Hello";
	const char *str2 = "Hello";
	printf("ft_strlen: %zu\n", ft_strlen(str1));
	printf("strlen: %zu\n", strlen(str1));
	printf("----------------\n");

	const char *str3 = "";
	const char *str4 = "";
	printf("ft_strlen: %zu\n", ft_strlen(str3));
	printf("strlen: %zu\n", strlen(str4));
	printf("----------------\n");

	const char *str5 = "Hello World!";
	const char *str6 = "Hello World!";
	printf("ft_strlen: %zu\n", ft_strlen(str5));
	printf("strlen: %zu\n", strlen(str6));
	printf("----------------\n");

	//セグフォ
	const char *str7 = NULL;
	const char *str8 = NULL;
	printf("ft_strlen: %zu\n", ft_strlen(str7));
	printf("strlen: %zu\n", strlen(str8));
	printf("----------------\n");
}	
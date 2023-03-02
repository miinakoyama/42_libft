/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:15:26 by mkoyama           #+#    #+#             */
/*   Updated: 2023/02/17 21:07:53 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

// 文字列 s 中に最初に文字 c が現れた位置へのポインターを返す。
// c='\0'のケースはsの末尾の'\0'が入っている最後のポインタを返す。
char *ft_strchr(const char *s, int c)
{
	while (*s != '\0') 
	{
		if (*s == (char)c) //charにキャストする!!!(intとcharを比較するのは危険!)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0') //charにキャスト!!!!!
		return ((char *)s); // c='\0'のケースはsの末尾の'\0'が入っている最後のポインタを返すのをここでしてる
	return (NULL);
}



int main(void)
{
	printf("ft_strchr: %s\n", ft_strchr("Hello", 'l'));
	printf("strchr:    %s\n", strchr("Hello", 'l'));
	printf("----------------\n");

	printf("ft_strchr: %s\n", ft_strchr("Hello", '\0'));
	printf("strchr:    %s\n", strchr("Hello", '\0'));
	printf("----------------\n");

	printf("ft_strchr: %s\n", ft_strchr("", 'l'));
	printf("strchr:    %s\n", strchr("", 'l'));
	printf("----------------\n");

	printf("ft_strchr: %s\n", ft_strchr("Hello", 'a'));
	printf("strchr:    %s\n", strchr("Hello", 'a'));
	printf("----------------\n");

	printf("ft_strchr: %s\n", ft_strchr("Hello", -2));
	printf("strchr:    %s\n", strchr("Hello", -2));
	printf("----------------\n");

	return (0);
}
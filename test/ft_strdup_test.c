/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:36:28 by miina             #+#    #+#             */
/*   Updated: 2023/02/17 17:16:28 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	char *dstcpy;
	const char *srccpy;

	if (dst == NULL && src == NULL)
		return (NULL);
	dstcpy = dst;
	srccpy = src;
	while (n-- > 0)
		*dstcpy++ = *srccpy++;
	return (dst);
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
	char *destcpy;
	const char *srccpy;

	destcpy = dest;
	srccpy = src;
	if (srccpy == destcpy || n == 0)
		return (dest);
	if (srccpy < destcpy) // この時は後ろからコピーしていく
	{
		// まずsrcもdestもポインタを後ろに持っていく
		srccpy += n - 1;
		destcpy += n - 1;
		while (n--)
			*destcpy-- = *srccpy--;
	}
	else
		// src>destの時は先頭からコピー→memcpyを使う
		ft_memcpy(destcpy, srccpy, n);
	return (dest);
}

// 新しい文字列に *s1 を複製する
char *ft_strdup(const char *s1)
{
	char *s2;
	size_t len;

	len = ft_strlen(s1) + 1;
	s2 = (char *)malloc(sizeof(char) * len);
	if (!s2)
		return (NULL);
	return ((char *)ft_memmove(s2, s1, len)); //上でlenは既にヌル文字分がたされてるからlen+1じゃなくてlenでok
}

int main(void)
{
	char *str1 = "abcdefg";
	printf("strdup:    %s\n", strdup(str1));
	printf("ft_strdup: %s\n", ft_strdup(str1));
	printf("----------------\n");

	char *str2 = "";
	printf("strdup:    %s\n", strdup(str2));
	printf("ft_strdup: %s\n", ft_strdup(str2));
	printf("----------------\n");

	char *str3 = " 1 2 3 4 5 6 7";
	printf("strdup:    %s\n", strdup(str3));
	printf("ft_strdup: %s\n", ft_strdup(str3));
	printf("----------------\n");

	char *str4 = "Hello, World!";
	printf("strdup:    %s\n", strdup(str4));
	printf("ft_strdup: %s\n", ft_strdup(str4));
	printf("----------------\n");

	return (0);
}
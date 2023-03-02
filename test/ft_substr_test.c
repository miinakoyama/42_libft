/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:37:17 by miina             #+#    #+#             */
/*   Updated: 2023/02/17 21:42:56 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (dstsize == 0)
		return ft_strlen(src);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return i;
}

//char *ft_substr(char const *s, unsigned int start, size_t len)
//{
//	char *ns;
//	size_t slen;
//	unsigned int start2;
//
//	start2 = start;
//	if (!s)
//		return (NULL);
//	slen = ft_strlen(s);
//	if (slen < start || len == 0)
//	{
//		ns = malloc(1);
//		if (!ns)
//			return (NULL);
//		*ns = '\0';
//	} else
//	{
//		while (start--)
//			s++;
//		if (slen - start2 + 1 < len)
//			len = slen - start2 + 1;
//		ns = (char *)malloc(sizeof(char) * (len + 1));
//		if (!ns)
//			return (NULL);
//		ft_strlcpy(ns, s, len + 1);
//	}
//	return (ns);
//}

// 文字列 s の start 文字目から len 文字分をmallocで確保したchar*に入れてそれを返す
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *ns;
	size_t slen;
	unsigned int start2; //startcpyとかの方がわかりやすい

	start2 = start; //スタートの数を変えた後にもう一回使いたかったから
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < start) //startnの方がsの長さより長いときはから文字を返す
		len = 0;
	while (start--) //sのstart文字目までポインタを持っていく
		s++;
	if (slen - start2 + 1 < len) //sのstart文字目からlen文字までにsが終わっちゃう時は、len文字分じゃなくてstartからsが終わるまでを新しい文字列に入れる
		len = slen - start2 + 1; //型がが違うの同士で引き算してるけど大丈夫？
	ns = (char *)malloc(sizeof(char) * (len + 1)); //環境によってcharの長さが違う時もあるから一応書いておいた方がいい
	if (!ns)
		return (NULL);
	ft_strlcpy(ns, s, len + 1); //何かに代入しなくても大丈夫??
	return (ns);
}

int main(void)
{
	printf("ft_substr(\"Hello\", 10, 2): %s\n", ft_substr("Hello", 10, 2));

	printf("ft_substr(\"Hello\", 4, 0): %s\n", ft_substr("Hello", 4, 0));

	printf("ft_substr(\"Hello\", 0, 2): %s\n", ft_substr("Hello", 0, 2));

	printf("ft_substr(\"Hello\", 3, 10): %s\n", ft_substr("Hello", 3, 10));

	printf("ft_substr(\"Hello, World\", 4, 6): %s\n", ft_substr("Hello, World", 4, 6));

	// len > 0 の時は?
	// len = SIZE_MAX + 1 - 引数に入れた数
	// printf("ft_substr(\"Hello\", 4, -2): %s\n", ft_substr("Hello", 3, -2));

	return (0);
}
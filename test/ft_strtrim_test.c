/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:53:47 by miina             #+#    #+#             */
/*   Updated: 2023/02/17 22:04:35 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

char *ft_strdup(const char *s1)
{
	char *s2;
	size_t len;

	len = ft_strlen(s1) + 1;
	s2 = (char *)malloc(len);
	if (!s2)
		return (NULL);
	return ((char *)ft_memmove(s2, s1, len));
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

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *ns;
	size_t slen;
	unsigned int start2;

	start2 = start;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < start)
		len = 0;
	while (start--)
		s++;
	if (slen - start2 + 1 < len)
		len = slen - start2 + 1;
	ns = (char *)malloc(sizeof(char) * (len + 1));
	if (!ns)
		return (NULL);
	ft_strlcpy(ns, s, len + 1);
	return (ns);
}

//文字列setの中に文字sがあったら1、なかったら0を返す
static int ft_search(char s1, char const *set)
{
	while (*set != '\0')
	{
		if (*set != s1)
			set++;
		else
			return (1);
	}
	return (0);
}

//*s1 から *set で指定された文字列を新たに作り返す
// mallocで確保したメモリに文字列 *s1 の先頭と末尾から *set で指定された文字が削除されたコピーを返
char *ft_strtrim(char const *s1, char const *set)
{
	char *ans;
	const char *s1back; //s1の1番後ろのポインタ s1_backとかの方がわかりやすい
	size_t s1len; //s1の長さ

	s1back = s1;
	if (s1 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s1back += s1len - 1; //s1backを1番後ろに持ってくる('\0'の直前)
	if (set == NULL) //set=NULLの時はs1をそのまま複製 nullチェックは最初の方がいい
		return (ft_strdup(s1));
	while (s1 && ft_search(*s1, set)) //前から見ていって、最初にsetにない文字が出てくる場所までポインタを持ってくる
		s1++;
	while (s1len-- && ft_search(*s1back, set)) // 後ろから見ていって、最初にsetにない文字が出てくる場所までポインタを持ってくる
		s1back--;
	ans = ft_substr(s1, 0, s1back - s1 + 1); // s1は最初にsetにない文字が出てくる場所にきているから、そこからs1back - s1文字と終端文字
	return (ans);
}


int main(void)
{
	printf("ft_strtrim(\"1234AAA22331122\", \"1234\"): %s\n", ft_strtrim("1234AAA22331122", "1234"));

	printf("ft_strtrim(\"1234A12AA22331122\", \"1234\"): %s\n", ft_strtrim("1234A12AA22331122", "1234"));

	printf("ft_strtrim(\"    AAA123    2\", \" \"): %s\n", ft_strtrim("    AAA123    2", " "));

	return (0);
}


/*以下python tutor用
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (dstsize == 0)
		return strlen(src);
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

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *ns;
	size_t slen;
	unsigned int start2;

	start2 = start;
	if (!s)
		return (NULL);
	slen = strlen(s);
	if (slen < start)
		len = 0;
	while (start--)
		s++;
	if (slen - start2 + 1 < len)
		len = slen - start2 + 1;
	ns = (char *)malloc(sizeof(char) * (len + 1));
	if (!ns)
		return (NULL);
	ft_strlcpy(ns, s, len + 1);
	return (ns);
}

static int ft_search(char s1, char const *set)
{
	while (*set != '\0')
	{
		if (*set != s1)
			set++;
		else
			return (1);
	}
	return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
	char *ans;
	char *s1back;
	size_t s1len;
	size_t count;

	count = 0;
	s1back = s1;
	if (s1 == NULL)
		return (NULL);
	s1len = strlen(s1);
	s1back += s1len - 1;
	if (set == NULL)
		return (strdup(s1));
	while (s1 && ft_search(*s1, set)) // 最初にsetにない文字が出てくる場所までポインタを持ってくる
		s1++;
	while (s1len && ft_search(*s1back, set))
		s1back--;
	ans = ft_substr(s1, 0, s1back - s1 + 1);
	return (ans);
}

int main(void)
{
	char *str1 = "1234AAA22331122";
	printf("ft_strtrim(\"1234AAA22331122\", \"1234\"): %s\n", ft_strtrim("1234AAA22331122", "1234"));

	return (0);
}
*/
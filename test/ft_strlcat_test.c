/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:41:26 by mkoyama           #+#    #+#             */
/*   Updated: 2023/02/17 21:21:51 by mkoyama          ###   ########.fr       */
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

//size_t ft_strlen1(char *str)
//{
//	size_t count;
//
//	count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return (count);
//}
//
//size_t ft_strlen2(const char *str)
//{
//	size_t count;
//
//	count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return (count);
//}
//
//size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
//{
//	size_t dstlen;
//	size_t srclen;
//
//	dstlen = ft_strlen1(dst);
//	srclen = ft_strlen2(src);
//	if (dstsize <= dstlen)
//		return (dstsize + srclen);
//	while (*dst != '\0')
//		dst++;
//	while (dstsize - dstlen - 1 > 0)
//	{
//		if (*src == '\0')
//			break;
//		*dst++ = *src++;
//		dstsize--;
//	}
//	*dst = '\0';
//	return (dstlen + srclen);
//}

static char *ft_strncat(char *dest, const char *src, unsigned int nb)
{
	char *destcp;

	destcp = dest;
	while (*destcp != '\0')
		destcp++;
	while (*src != '\0' && nb > 0)
	{
		*destcp++ = *src++;
		nb--;
	}
	*destcp = '\0';
	return (dest);
}

// *srcから*dst の末尾に 最大で dstsize - strlen(*dst) - 1 バイトの文字列を追加する
// dstsize - strlen(*dst) - 1 バイトコピーする前にヌル文字が見つかると、 そこでコピーを中止する

//  複写先の文字列dest と複写元の文字列 src の長さ(バイト数)の和が size_t 型で返る(この長さには、末端のNULL文字は含まない)
//  戻り値は、初期値のstrlen(*dest) + strlen(*src)となる
//  戻り値>= dstsizeの時、切り捨てが発生したことを意味する
size_t ft_strlcat(char *dst, const char *src, size_t dstsize) //dstsizeはdstの長さ
{
	size_t dstlen;
	size_t srclen;

	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst); //これを下に持ってけば上のifはいらない
	srclen = ft_strlen(src);
	if (dstsize <= 0) // dstsizeが0の時は何もせずにsrclenをreturn <=じゃなくて==でいい
		return srclen;
	if (dstsize <= dstlen) //ここ+1いらない!!!
		return (srclen + dstsize);
	ft_strncat(dst, src, dstsize - dstlen - 1);
	//dst[dstsize - 1] = '\0'; strncatで入れてるからいらない!!!!
	return (dstlen + srclen);
}

//size_t ft_strlcat(char *dst, const char *src, size_t dstsize) //dstsize: 連結後の文字数
//{
//	size_t dstlen;
//	size_t srclen;
//	size_t rv;
//
//	dstlen = ft_strlen(dst); // dstの文字数
//	srclen = ft_strlen(src); //srcの文字数
//	rv = dstlen + srclen;
//	if (dstsize <= 0) // dstsizeが0の時は何もせずにsrclenをreturn
//		return srclen;
//	while (*dst != '\0') // dstの1番後ろまでポインタを持ってくる
//		dst++;
//	if (dstsize <= dstlen + 1) //dstsizeがdstlen+1以下の時には連結しないからリターン
//		return (dstsize + srclen);
//	while (dstsize > dstlen + 1 && *src != '\0') 
//	{
//		*dst++ = *src++;
//		dstlen++;
//	}
//	if (dstsize > dstlen + 1) // 上のwhileで、*src == '\0'でループを抜けた時(まだ連結後にdstsizeに余裕がある時)
//	{
//		*dst = '\0';
//		return (dstsize);
//	}
//	else
//	{
//		dst[dstsize - 1] = '\0';
//		return (rv);
//	}
//}

int main(void)
{
	char dst1[20] = "abc";
	const char src1[] = "1234567";
	char dst2[20] = "abc";
	const char src2[] = "1234567";
	printf("<strlcat>\n");
	printf("return value: %lu\n", strlcat(dst1, src1, 6));
	printf("dst: %s\n", dst1);
	printf("<ft_strlcat>\n");
	printf("return value: %lu\n", ft_strlcat(dst2, src2, 6));
	printf("dst: %s\n", dst2);
	printf("----------------\n");

	char dst3[20] = "abc";
	const char src3[] = "1234567";
	char dst4[20] = "abc";
	const char src4[] = "1234567";
	printf("<strlcat>\n");
	printf("return value: %lu\n", strlcat(dst3, src3, 20));
	printf("dst: %s\n", dst3);
	printf("<ft_strlcat>\n");
	printf("return value: %lu\n", ft_strlcat(dst4, src4, 20));
	printf("dst: %s\n", dst4);
	printf("----------------\n");

//dst=NULLでdstsize=0の時はdstはnullのままでreturnはsrcの長さ
	char *dst5 = NULL;
	const char src5[] = "42tokyo";
	char *dst6 = NULL;
	const char src6[] = "42tokyo";
	printf("<strlcat>\n");
	printf("return value: %lu\n", strlcat(dst5, src5, 0));
	printf("dst: %s\n", dst5);
	printf("<ft_strlcat>\n");
	printf("return value: %lu\n", ft_strlcat(dst6, src6, 0));
	printf("dst: %s\n", dst6);
	printf("----------------\n");

//src=NULLの時はセグフォ
	//char dst7[20] = "abc";
	//const char *src7 = NULL;
	//char dst8[20] = "abc";
	//const char *src8 = NULL;
	//printf("<strlcat>\n");
	//printf("return value: %lu\n", strlcat(dst7, src7, 2));
	//printf("dst: %s\n", dst7);
	//printf("<ft_strlcat>\n");
	//printf("return value: %lu\n", ft_strlcat(dst8, src8, 2));
	//printf("dst: %s\n", dst8);
	//printf("----------------\n");

	char dst9[20] = "abc";
	const char src9[] = "1234567";
	char dst10[20] = "abc";
	const char src10[] = "1234567";
	printf("<strlcat>\n");
	printf("return value: %lu\n", strlcat(dst9, src9, 0));
	printf("dst: %s\n", dst9);
	printf("<ft_strlcat>\n");
	printf("return value: %lu\n", ft_strlcat(dst10, src10, 0));
	printf("dst: %s\n", dst10);
	printf("----------------\n");

	// dst=NULLでdstsize!=0の時はセグフォ
	// char *dst11 = NULL;
	// const char src11[] = "42tokyo";
	// char *dst12 = NULL;
	// const char src12[] = "42tokyo";
	// printf("<strlcat>\n");
	// printf("return value: %lu\n", strlcat(dst11, src11, 2));
	// printf("dst: %s\n", dst5);
	// printf("<ft_strlcat>\n");
	// printf("return value: %lu\n", ft_strlcat(dst12, src12, 2));
	// printf("dst: %s\n", dst6);
	// printf("----------------\n");

	return (0);
}

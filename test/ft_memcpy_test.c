/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:27:09 by miina             #+#    #+#             */
/*   Updated: 2023/02/17 16:36:23 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

//*src の先頭から n 文字分を、*dst へコピーする
//途中にヌル文字を含んでいてもコピーを続ける
//*dst と *src が重なっているときの動作は未定義 
void *ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dstcpy; //mem系は全部unsigned にキャスト
	const unsigned char *srccpy;

	if (dst == NULL && src == NULL) //両方NULLの時はNULLを返す
		return (NULL);
	dstcpy = (unsigned char *)dst;
	srccpy = (const unsigned char *)src;
	while (n-- > 0) //前から順にコピーしていく
		*dstcpy++ = *srccpy++;
	return (dst);
}

int main(void)
{
	char src1[20] = "Hello, World!";
	char dst1[20];
	char src2[20] = "Hello, World!";
	char dst2[20];
	ft_memcpy(dst1, src1, strlen(src1) + 1);
	printf("ft_memcpy: %s\n", dst1);
	memcpy(dst2, src2, strlen(src2) + 1);
	printf("memcpy:    %s\n", dst2);
	printf("----------------\n");

	char src3[20] = "Hello, World!";
	char dst3[20];
	char src4[20] = "Hello, World!";
	char dst4[20];
	ft_memcpy(dst3, src3, 2);
	printf("ft_memcpy: %s\n", dst3);
	memcpy(dst4, src4, 2);
	printf("memcpy:    %s\n", dst4);
	printf("----------------\n");

	char src5[20] = "Hello\0, World!";
	char dst5[20];
	char src6[20] = "Hello\0, World!";
	char dst6[20];
	ft_memcpy(dst5, src5, 10);
	printf("ft_memcpy: %s\n", dst5);
	printf("ft_memcpy: %s\n", dst5+7);
	memcpy(dst6, src6, 10);
	printf("memcpy:    %s\n", dst6);
	printf("memcpy:    %s\n", dst6+7);
	printf("----------------\n");

	char src7[20] = "Hello!";
	char dst7[20] = "1234567890";
	char src8[20] = "Hello!";
	char dst8[20] = "1234567890";
	ft_memcpy(dst7, src7, strlen(src7) + 1);
	printf("ft_memcpy: %s\n", dst7);
	memcpy(dst8, src8, strlen(src8) + 1);
	printf("memcpy:    %s\n", dst8);
	printf("----------------\n");

	//両方nullだとnull
	printf("ft_memcpy: %p\n", ft_memcpy(NULL, NULL, 4));
	printf("memcpy:    %p\n", memcpy(NULL, NULL, 4));
	printf("----------------\n");

	//dst=NULLの時セグフォ
	// printf("ft_memcpy: %p\n", ft_memcpy("Hello!", NULL, 4));
	// printf("memcpy:    %p\n", memcpy("Hello!", NULL, 4));
	// printf("----------------\n");

	// src=NULLの時もセグフォ
	// printf("ft_memcpy: %p\n", ft_memcpy(NULL, "Hello!", 4));
	// printf("memcpy:    %p\n", memcpy(NULL, "Hello!", 4));
	// printf("----------------\n");

	return (0);
}

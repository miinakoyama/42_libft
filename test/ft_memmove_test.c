/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:32:00 by mkoyama           #+#    #+#             */
/*   Updated: 2023/02/17 16:41:58 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string.h>
#include <stdio.h>
#include "libft.h"

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

//void *ft_memmove(void *dest, const void *src, size_t n)
//{
//	char *destcpy;
//	char *srccpy;
//
//	destcpy = (char *)dest;
//	srccpy = (char *)src;
//	if (srccpy == destcpy || n == 0)
//		return (dest);
//	if (srccpy < destcpy && destcpy - srccpy < (int)n)
//	{
//		while (n-- > 0)
//			destcpy[n - 1] = srccpy[n - 1];
//		return (dest);
//	}
//	if (srccpy > destcpy && srccpy - destcpy < (int)n)
//	{
//		while (n-- > 0)
//			*destcpy++ = *srccpy++;
//		return (dest);
//	}
//	ft_memcpy(dest, src, n);
//	return (dest);
//}

/*
//memcpy使ったver
void *ft_memmove(void *dest, const void *src, size_t n)
{
	char *destcpy;
	const char *srccpy;

	destcpy = dest;
	srccpy = src;
	if (srccpy == destcpy || n == 0)
		return (dest);
	if (srccpy < destcpy) //この時は後ろからコピーしていく
	{
		//まずsrcもdestもポインタを後ろに持っていく
		srccpy += n - 1;
		destcpy += n - 1;
		while (n--)
			*destcpy-- = *srccpy--;
	}
	else
		//src>destの時は先頭からコピー→memcpyを使う
		ft_memcpy(destcpy, srccpy, n);
	return (dest);
}
*/

/*
//mamcpyを使わないでみる->ダメだった
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
		// src>destの時は先頭からコピー
		while (n--)
			*destcpy++ = *srccpy++;
	return (dest);
}
*/

/*
//一ノ瀬さんと同じやつだけどcrashしたやつ
void *ft_memmove(void *dest, const void *src, size_t n)
{
	char *destcpy;
	char *srccpy;

	if (dest == NULL && src == NULL)
		return (NULL);
	destcpy = (char *)dest;
	srccpy = (char *)src;
	if (dest == src)
		return (dest);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			destcpy[n - 1] = srccpy[n - 1];
			n--;
		}
	}
	return (dest);
}
*/

//ポインタを使わなくした->これもcrash->このmacのせいだった
void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *destcpy;
	const unsigned char *srccpy;
	size_t i;

	destcpy = (unsigned char *)dest;
	srccpy = (const unsigned char *)src;
	if (srccpy == destcpy || n == 0) //どっちもNULLの時もここに入ってNULLを返す
		return (dest);
	if (srccpy < destcpy) // destの方が後ろの時は(重なってるとsrcが書き換えられる可能性があるから)後ろからコピーしていく
	{
		i = n; //n+1じゃなくてnの方がよかった!!!!!!!!!変えた!!!
		while (i-- > 0)
			destcpy[i] = srccpy[i];
	}
	else //srcの方が後ろの時は前からコピー
	{
		i = 0;
		while (i < n)
		{
			destcpy[i] = srccpy[i];
			i++;
		}
	}
	return (dest);
}


int main(void)
{
	char src1[20] = "Hello, World!";
	char dst1[20];
	char src2[20] = "Hello, World!";
	char dst2[20];
	ft_memmove(dst1, src1, 3);
	printf("ft_memmove:    %s\n", dst1);
	memmove(dst2, src2, 3);
	printf("memmove:    %s\n", dst2);
	printf("----------------\n");

	//*dst=NULLの時はセグフォ
	//char src4[20] = "Hello, World!";
	//char *dst4 = NULL;
	//memmove(dst4, src4, 3);
	//printf("memmove:    %s\n", dst4);

	//*src=NULLの時はセグフォ
	//char *src4 = NULL;
	//char dst4[20];
	//memmove(dst4, src4, 3);
	//printf("memmove:    %s\n", dst4);

	//n=0の時:何もしない
	char src5[20] = "Hello, World!";
	char dst5[20];
	char src6[20] = "Hello, World!";
	char dst6[20];
	ft_memmove(dst5, src5, 0);
	printf("ft_memmove:    %s\n", dst5);
	memmove(dst6, src6, 0);
	printf("memmove:    %s\n", dst6);
	printf("----------------\n");

	//どっちもNULLの時: NULLが返って来る
	printf("memmove: %p\n", memmove(NULL, NULL, 4));
	printf("ft_memmove: %p\n", ft_memmove(NULL, NULL, 4));
	printf("----------------\n");

	return (0);
}
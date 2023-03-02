/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:26:44 by miina             #+#    #+#             */
/*   Updated: 2023/02/17 16:09:24 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

// バイト列 *s から始まる領域の先頭 n バイトを 数値ゼロ (値が '\0' のバイト) で埋める
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*news;
	// メモリ上のデータをバイト単位でアクセスするため(この関数はバイト単位でメモリにアクセスしたいから)
	// unsignedなのはなのはメモリが負になったら困るから
	news = (unsigned char *)s;
	while (n--)
	{
		*news = 0;
		if (n != 0) //ループの1番最後のn=0の時にnews++をしちゃうと、ポインタが一個先に行っちゃう(なくてもいいかも?)
			news++;
	}
}

int main(void)
{
	char str1[] = "0123456789";
	char str2[] = "0123456789";
	ft_bzero(str1 + 2, 5);
	printf("ft_bzero: %s\n", str1);
	bzero(str2 + 2, 5);
	printf("bzero:    %s\n", str2);
	printf("----------------\n");

	char str3[] = "0123456789";
	char str4[] = "0123456789";
	ft_bzero(str3 + 4, 3);
	printf("ft_bzero: %s\n", str3);
	bzero(str4 + 4, 3);
	printf("bzero:    %s\n", str4);
	printf("----------------\n");

	//char str5[] = "";
	//char str6[] = "";
	//ft_bzero(str5 + 2, 5);
	//printf("ft_bzero: %s\n", str6);
	//bzero(str5 + 2, 5);
	//printf("bzero: %s\n", str6);
	//printf("----------------\n");

	char str7[] = "abc";
	char str8[] = "abc";
	ft_bzero(str7 + 1, 0);
	printf("ft_bzero: %s\n", str7);
	bzero(str8 + 1, 0);
	printf("bzero:    %s\n", str8);
	printf("----------------\n");

	return (0);
}
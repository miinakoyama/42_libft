/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:27:32 by miina             #+#    #+#             */
/*   Updated: 2023/02/17 16:44:10 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

// buf の先頭から n バイト分 ch をセットする
// buf を超えてセットした場合の動作は未定義
void	*ft_memset(void *buf, int ch, size_t n) //void*型にすることでどんな型のポインタでも使える(intでもcharでも)
{
	unsigned char	*newbuf; //unsigned charの理由: メモリをバイト単位でセットしたいからchar型で、バイトの値が負になったら困るからunsigned(charは最初のビットが符号ビット)
	unsigned char nch;

	nch = (unsigned char)ch; //下でchar型に入れてるから
	newbuf = (unsigned char *)buf;
	while (n-- > 0) //size_tをマイナスするのは本当はあんまり良くないかも & >0はなくてもいい
		*newbuf++ = nch;
	return (buf);
}

int main(void)
{
	char str1[] = "0123456789";
	char str2[] = "0123456789";
	ft_memset(str1 + 2, '*', 5);
	printf("ft_memset: %s\n", str1);
	memset(str2 + 2, '*', 5);
	printf("memset:    %s\n", str2);
	printf("----------------\n");

	char str3[] = "0123456789";
	char str4[] = "0123456789";
	ft_memset(str3, '*', 2);
	printf("ft_memset: %s\n", str3);
	memset(str4, '*', 2);
	printf("memset:    %s\n", str4);
	printf("----------------\n");

	//char str5[] = "";
	//char str6[] = "";
	//ft_memset(str5, '*', 3);
	//printf("ft_memset: %s\n", str5);
	//memset(str6, '*',3);
	//printf("memset:    %s\n", str6);
	//printf("----------------\n");

	char str7[] = "0123456789";
	char str8[] = "0123456789";
	ft_memset(str7+3, '*', 0);
	printf("ft_memset: %s\n", str7);
	memset(str8+3, '*', 0);
	printf("memset:    %s\n", str8);
	printf("----------------\n");
	
	char str9[] = "";
	char str10[] = "";
	ft_memset(str9, '*', 0);
	printf("ft_memset: %s\n", str9);
	memset(str10, '*', 0);
	printf("memset:    %s\n", str10);
	printf("----------------\n");
	
	//char str11[] = "0123";
	//char str12[] = "0123";
	//ft_memset(str11+10, '*', 2);
	//printf("ft_memset: %s\n", str11);
	//memset(str12+10, '*', 2);
	//printf("memset:    %s\n", str12);
	//printf("----------------\n");

	return (0);
}
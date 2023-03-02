/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 02:18:45 by miina             #+#    #+#             */
/*   Updated: 2023/02/17 16:35:39 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

//*s1 と*s2 を先頭から n バイト分比較
// 比較はunsigned char として行われる
// memcmp() は *s1と *s2 をメモリブロックとして扱うため、途中にヌル文字('\0')を含んでいても比較を続ける

//*s1 ＞ *s2の場合　　→正の値
//*s1 ＝ *s2の場合　　→0 
//* s1  ＜ *s2の場合　　→負の値 
int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ns1;
	unsigned char	*ns2;

	ns1 = (unsigned char *)s1;
	ns2 = (unsigned char *)s2;
	while (n--)
	{
		if (*ns1 != *ns2) //違ったらその時点でs1-s2を返す
			return ((int)(*ns1 - *ns2));
		ns1++;
		ns2++;
	}
	return (0); //全部同じだったらwhile抜けて0を返す
}

int main(void)
{
	const char *s1 = "Hello";
	const char *s2 = "Hello, World";
	printf("memcmp:    %d\n", memcmp(s1, s2, 3));
	printf("ft_memcmp: %d\n",ft_memcmp(s1, s2, 3));
	printf("----------------\n");

	printf("memcmp:    %d\n", memcmp(s1, s2, 8));
	printf("ft_memcmp: %d\n", ft_memcmp(s1, s2, 8));
	printf("----------------\n");

	printf("memcmp:    %d\n", memcmp(s2, s1, 9));
	printf("ft_memcmp: %d\n", ft_memcmp(s2, s1, 9));
	printf("----------------\n");

	//セグフォ
	//const char *s3 = NULL;
	//const char *s4 = NULL;
	//printf("memcmp:    %d\n", memcmp(s3, s4, 3));
	//printf("ft_memcmp: %d\n", ft_memcmp(s3, s4, 3));
	//printf("----------------\n");

	const char *s5 = NULL;
	const char *s6 = NULL;
	printf("memcmp:    %d\n", memcmp(s5, s6, 0));
	printf("ft_memcmp: %d\n", ft_memcmp(s5, s6, 0));
	printf("----------------\n");

	const char *s7 = "H\0ello";
	const char *s8 = "H\0ello, World";
	printf("memcmp:    %d\n", memcmp(s7, s8, 4));
	printf("ft_memcmp: %d\n", ft_memcmp(s7, s8, 4));
	printf("----------------\n");
}
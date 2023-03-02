/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:37:04 by miina             #+#    #+#             */
/*   Updated: 2023/02/17 16:26:20 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

// ポインター s が指し示すメモリー領域の先頭の n バイトから最初に登場する文字 c を探す。 c と s が指し示すメモリー領域の各バイトは両方とも unsigned char と解釈される。
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ns;
	unsigned char	nc;

	ns = (unsigned char *)s;
	nc = (unsigned char)c;
	while (n--)
	{
		if (*ns == nc) //一緒のが見つかったらそこのポインタを返す
			return (ns);
		ns++;
	}
	return (NULL); //見つからなかったらwhile抜けてnullを返す
}

int main(void)
{
	const char *s1 = "Hello";
	printf("memchr:    %p\n", memchr(s1, 'e', 5));
	printf("ft_memchr: %p\n", ft_memchr(s1, 'e', 5));
	printf("----------------\n");

	const char *s2 = "Hello";
	printf("memchr:    %p\n", memchr(s2, 'n', 5));
	printf("ft_memchr: %p\n", ft_memchr(s2, 'n', 5));
	printf("----------------\n");

	const char *s3 = "Hello";
	printf("memchr:    %p\n", memchr(s3, 'o', 2));
	printf("ft_memchr: %p\n", ft_memchr(s3, 'o', 2));
	printf("----------------\n");

	const char *s4 = "H\nello";
	printf("memchr:    %p\n", memchr(s4, 'e', 4));
	printf("ft_memchr: %p\n", ft_memchr(s4, 'e', 4));
	printf("----------------\n");

	//s=NULLの時セグフォ
	//const char *s5 = NULL;
	//printf("memchr:    %p\n", memchr(s5, 'e', 4));
	//printf("ft_memchr: %p\n", ft_memchr(s5, 'e', 4));
	//printf("----------------\n");

	const char *s6 = "Hello";
	printf("memchr:    %p\n", memchr(s6, 'e', 0));
	printf("ft_memchr: %p\n", ft_memchr(s6, 'e', 0));
	printf("----------------\n");
	
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:11:58 by miina             #+#    #+#             */
/*   Updated: 2023/02/17 16:10:03 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

// バイト列 *s から始まる領域の先頭 n バイトを 数値ゼロ (値が '\0' のバイト) で埋める
void ft_bzero(void *s, size_t n)
{
	unsigned char *news;

	news = s;
	while (n--)
	{
		*news = 0;
		if (n != 0)
			news++;
	}
}

// ヒープメモリから size バイトのブロックを count 個割り当てる
//確保されたブロックを0埋めする
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (!size || !count)
		return (ft_calloc(1, 1));
	if (SIZE_MAX / size < count) //オーバーフローする時
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

int main(void)
{
	char *ptr = calloc(4, sizeof(char));
	ptr[0] = 'a';
	ptr[1] = 'b';
	ptr[2] = 'c';
	ptr[3] = '\0';
	printf("calloc:    %s\n", ptr);
	free(ptr);

	char *ptr1 = ft_calloc(4, sizeof(char));
	ptr1[0] = 'a';
	ptr1[1] = 'b';
	ptr1[2] = 'c';
	ptr1[3] = '\0';
	printf("ft_calloc: %s\n", ptr1);
	free(ptr1);

	printf("----------------\n");

	char *ptr2 = calloc(0, sizeof(char));
	printf("calloc:    %s\n", ptr2);
	free(ptr2);

	char *ptr3 = ft_calloc(0, sizeof(char));
	printf("ft_calloc: %s\n", ptr3);
	free(ptr3);

	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:20:48 by miina             #+#    #+#             */
/*   Updated: 2023/02/17 17:48:39 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

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

void *ft_calloc(size_t count, size_t size)
{
	void *ptr;

	if (!size || !count)
		return (ft_calloc(1, 1));
	if (SIZE_MAX / size < count)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

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

char *ft_strncat(char *dest, const char *src, unsigned int nb)
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

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dstlen;
	size_t srclen;

	if (dst == NULL)
		return ft_strlen(src);
	dstlen = ft_strlen(dst); //ここが問題だった!!!(dstはこの時何も入っていない(初期化されていない)からstrlen使えない)
	srclen = ft_strlen(src);
	if (dstsize <= 0) // dstsizeが0の時は何もせずにsrclenをreturn
		return srclen;
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	ft_strncat(dst, src, dstsize - dstlen - 1);
	dst[dstsize - 1] = '\0';
	return (dstlen + srclen);
}

// s1の末尾にs2を連結する
// s1の範囲外へアクセスするような形で連結した場合と、s1とs2が重なっていた場合の動作は「未定義」なので、考慮しなくてよい
//本家なし
char *ft_strjoin(char const *s1, char const *s2)
{
	char *joinedstr;
	size_t len;

	if (!s1 && !s2) //両方NULLの時
		return (NULL);
	if (!s1 && s2) //s1だけNULLの時
		len = ft_strlen(s2) + 1;
	if (s1 && !s2) //s2だけNULLの時
		len = ft_strlen(s1) + 1;
	if (s1 && s2)
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joinedstr = (char *)ft_calloc(len, sizeof(char));
	if (!joinedstr)
		return (NULL);
	if (s1 && *s1 != '\0') //後半はs1が空の時の処置
		ft_strlcat(joinedstr, s1, len); //何かに代入しなくてもいいのか?
	if (s2 && *s2 != '\0') //後半はs2が空の時の処置
		ft_strlcat(joinedstr, s2, len);
	return (joinedstr);
}

int main(void)
{
	printf("ft_strjoin(\"Hello\", \"World\"): %s\n", ft_strjoin("Hello", "World"));
	printf("ft_strjoin(NULL, \"World\"): %s\n", ft_strjoin(NULL, "World"));
	printf("ft_strjoin(\"Hello\", NULL): %s\n", ft_strjoin("Hello", NULL));
	printf("ft_strjoin(NULL, NULL): %s\n", ft_strjoin(NULL, NULL));
	printf("ft_strjoin(NULL, NULL): %s\n", ft_strjoin(NULL, NULL));
	printf("ft_strjoin(\"where is my\", \"malloc ???\"): %s\n", ft_strjoin("where is my ", "malloc ???"));

	printf("strcmp: %d\n", strcmp(ft_strjoin("", "42"), "42"));
	printf("ft_strjoin(\"42\", \"\"): %s\n", ft_strjoin("42", ""));
	printf("ft_strjoin(\"\", \"\"): %s\n", ft_strjoin("", ""));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 02:42:25 by miina             #+#    #+#             */
/*   Updated: 2023/02/17 18:13:32 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

//haystackにneedleが見つかったら1、見つからなかったら0を返す
//lenの長さ分だけチェックする
int	cmp_str(const char *haystack, const char *needle, size_t len)
{
	while (*needle != '\0')
	{
		if (len-- <= 0 || *haystack != *needle)
			return (0);
		haystack++;
		needle++;
	}
	return (1);
}

// len 文字より少ない文字列haystackの中で、ヌル文字で終了する文字列 needle が最初に出現する位置
char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	i = 0;
	if (*needle == '\0') //needleが空の時haystackを返す
		return ((char *)haystack);
	while (i < len && *haystack != '\0') //len文字分チェックし終わるかhaystackが最後までいくかしない限りチェック
	{
		if (*haystack == *needle && cmp_str(haystack, needle, len - i)) //最初の文字が一緒の時にはそれ以降もチェック(len-iなのは、チェックしたい長さから今までチェックした長さを引いてる)
			return ((char *)haystack); //見つかったらretrun
		haystack++;
		i++;
	}
	return (NULL); //見つからなかったらwhileループ抜けてnullを返す
}


int main(void)
{
	//World
	printf("strnstr:    %s\n", strnstr("Hello World", "World", 11));
	printf("ft_strnstr: %s\n", ft_strnstr("Hello World", "World", 11));
	printf("----------------\n");

	//(null)
	printf("strnstr:    %s\n", strnstr("Hello World", "World", 10));
	printf("ft_strnstr: %s\n", ft_strnstr("Hello World", "World", 10));
	printf("----------------\n");

	//(null) (lenが0より大きいとセグフォ)
	printf("strnstr:    %s\n", strnstr(NULL, "is", 0));
	printf("ft_strnstr: %s\n", ft_strnstr(NULL, "is", 0));
	printf("----------------\n");

	//(null)
	printf("strnstr:    %s\n", strnstr(NULL, "", 0));
	printf("ft_strnstr: %s\n", ft_strnstr(NULL, "", 0));
	printf("----------------\n");

	//bbcdefg
	printf("strnstr:    %s\n", strnstr("abbbcdefg", "bbc", 20));
	printf("ft_strnstr: %s\n", ft_strnstr("abbbcdefg", "bbc", 20));
	printf("----------------\n");

	//Hello World
	printf("strnstr:    %s\n", strnstr("Hello World", "", 0));
	printf("ft_strnstr: %s\n", ft_strnstr("Hello World", "", 0));
	printf("----------------\n");

	//(null)
	printf("strnstr:    %s\n", strnstr("Hello World", "World", 0));
	printf("ft_strnstr: %s\n", ft_strnstr("Hello World", "World", 0));
	printf("----------------\n");

	//セグフォ
	// printf("strnstr:    %s\n", strnstr("Hello World", NULL, 0));
	// printf("ft_strnstr: %s\n", ft_strnstr("Hello World", NULL, 0));
	// printf("----------------\n");

	//セグフォ
	// printf("strnstr:    %s\n", strnstr("Hello World", NULL, 10));
	// printf("ft_strnstr: %s\n", ft_strnstr("Hello World", NULL, 10));
	// printf("----------------\n");

	//セグフォ
	//printf("strnstr:    %s\n", strnstr(NULL, NULL, 0));
	//printf("ft_strnstr: %s\n", ft_strnstr(NULL, NULL, 0));
	//printf("----------------\n");

	return (0);
}
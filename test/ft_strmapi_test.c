/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:47:05 by miina             #+#    #+#             */
/*   Updated: 2023/02/17 14:44:52 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

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

// mallocを使用して割り当て、文字列 *s の各文字に関数 f を適用した新しい文字列を作成する
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *ans;
	size_t len;
	unsigned int i;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (!ans)
		return (NULL);
	while (s[i])
	{
		ans[i] = f(i, *(s + i));
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

char f(unsigned int i, char c)
{
	return (c + 1);
}

int main(void)
{
	char *str1 = "1234";
	printf("ft_strmapi(\"1234\", *f): %s\n", ft_strmapi("1234", &f));
}

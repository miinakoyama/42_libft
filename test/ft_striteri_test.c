/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:15:48 by miina             #+#    #+#             */
/*   Updated: 2023/02/17 17:18:10 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// 引数として渡された文字列 *s の各文字に関数 f を適用し、そのインデックスを第1引数として渡す
//各文字はポインタとしてfに渡され、必要に応じて修正される
void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}

void print_char(unsigned int index, char *c)
{
	printf("Index: %u, Character: %c\n", index, *c);
}

int main(void)
{
	char s[] = "Hello, World!";

	ft_striteri(s, &print_char);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:45:23 by miina             #+#    #+#             */
/*   Updated: 2023/02/17 16:18:08 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_getlen(long ln)
{
	size_t count;

	if (ln == 0) //これを追加
		return (1);
	count = 0;
	while (ln)
	{
		ln /= 10;
		count++;
	}
	return (count);
}

static char	*ft_getstr(char *ans, long ln, size_t len, int sign)
{
	if (sign == 1) //負の数の時は'-'分を足す
		len++;
	ans[len] = '\0'; //最後にヌル文字追加
	while (len--) //後ろから追加していく
	{
		ans[len] = '0' + ln % 10;
		// ex) 123: ans[2] = 3, 123/10=12: ans[1] = 2, 12/10=1: ans[0] = 1
		ln /= 10;
	}
	if (sign == 1)
		*ans = '-';
	return (ans);
}

// 引数として受け取った数値を文字列で返す
char	*ft_itoa(int n)
{
	char *ans;
	long ln;
	size_t len;
	int sign; // 負の時は1、正の時は0

	sign = 0;
	ln = (long)n; //オーバーフローしないようにlong型にしておく
	if (ln < 0) //負の時にはsignを-1にして、lnに-1をかけて正にする
	{
		sign = 1;
		ln *= -1;
	}
	len = ft_getlen(ln);
	ans = malloc(sizeof(char) * (len + sign + 1));
	if (!ans)
		return (NULL);
	return (ft_getstr(ans, ln, len, sign));
}

int main(void)
{
	printf("ft_itoa(12345): %s\n", ft_itoa(12345));
	printf("ft_itoa(-12345): %s\n", ft_itoa(-12345));
	printf("ft_itoa(INT_MAX): %s\n", ft_itoa(INT_MAX));
	printf("ft_itoa(INT_MIN): %s\n", ft_itoa(INT_MIN));
	printf("ft_itoa(INT_MIN): %s\n", ft_itoa(0));

	return (0);
}
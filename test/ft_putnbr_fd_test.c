/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:14:02 by miina             #+#    #+#             */
/*   Updated: 2023/02/17 19:37:32 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

/*
//itoaはmallocしてるから使えない
static size_t ft_getlen(long ln)
{
	size_t count;

	count = 0;
	while (ln)
	{
		ln /= 10;
		count++;
	}
	return (count);
}

static char *ft_getstr(char *ans, long ln, size_t len, int sign)
{
	if (sign == 1)
		len++;
	ans[len] = '\0';
	while (len--)
	{
		ans[len] = '0' + ln % 10;
		ln /= 10;
	}
	if (sign == 1)
		*ans = '-';
	return (ans);
}

char *ft_itoa(int n)
{
	char *ans;
	long ln;
	size_t len;
	int sign; // 負の時は1、正の時は0

	sign = 0;
	ln = (long)n; // オーバーフローしないようにlong型にしておく
	if (ln < 0)		// 負の時にはsignを-1にして、lnに-1をかけて正にする
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
*/



void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long ln;
	long num[11]; //INT_MAXが10桁だからそれとヌル文字で最大11文字(これは1文字だからintでもよかった)
	size_t i;

	i = 0;
	ln = (long)n; //INT_MINをプラスに変えた時にオーバーフローしちゃうから
	if (ln < 0) //nがマイナスの時はプラスに変えて-を出力
	{
		ln *= -1;
		ft_putchar_fd('-', fd);
	}
	while (ln != 0 || i == 0) //n=0の時のためにi==0を入れた
	{
		num[i] = ln % 10; //一桁目から入れていく(だから逆順に出力する必要がある)
		ln /= 10;
		i++;
	}
	while (i-- != 0) //入れたのと逆順に出力
		ft_putchar_fd('0' + num[i], fd);
}

int main(void)
{
	int fd;
	int a = 0;

	fd = open("output_putnbr.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	ft_putnbr_fd(a, fd);
	close(fd);
	return (0);
}
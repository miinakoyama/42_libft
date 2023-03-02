/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:06:39 by miina             #+#    #+#             */
/*   Updated: 2023/02/17 16:49:42 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

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

// 指定されたファイルディスクリプタに対して文字列sを出力して改行
void ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

int main(void)
{
	int fd;
	char *str = "123456789abede";

	fd = open("output_putendl.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	ft_putendl_fd(str, fd);
	close(fd);
	return (0);
}
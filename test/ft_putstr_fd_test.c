/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:52:06 by miina             #+#    #+#             */
/*   Updated: 2023/02/17 21:50:37 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

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

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	//while (*s)
	//{
	//	ft_putchar_fd(*s, fd);
	//	s++;
	//}
	write(fd, s, ft_strlen(s)); //ft_putcharでwrite関数何度も呼び出すよりも一回だけの方がいい!!!!!
}
//ft_strlenはsize_tだから、SIZE_MAX超えた時はどうするのか？


int main(void)
{
	int fd;
	char *str = "Hello, World!";

	fd = open("output_putstr.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	ft_putstr_fd(str, fd);
	close(fd);
	return (0);
}
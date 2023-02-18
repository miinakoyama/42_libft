/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miina <miina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:14:02 by miina             #+#    #+#             */
/*   Updated: 2023/02/15 12:34:56 by miina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;
	long	num[11];
	size_t	i;

	i = 0;
	ln = (long)n;
	if (ln < 0)
	{
		ln *= -1;
		ft_putchar_fd('-', fd);
	}
	while (ln != 0 || i == 0)
	{
		num[i] = ln % 10;
		ln /= 10;
		i++;
	}
	while (i-- != 0)
		ft_putchar_fd('0' + num[i], fd);
}

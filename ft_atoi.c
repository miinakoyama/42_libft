/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miina <miina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:49:12 by miina             #+#    #+#             */
/*   Updated: 2023/02/15 11:56:24 by miina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_ov(long ans, char str, int sign)
{
	long	ov_div;
	long	ov_mod;

	ov_div = LONG_MAX / 10;
	ov_mod = LONG_MAX % 10;
	if (sign == -1)
		ov_mod++;
	if (ans > ov_div)
		return (1);
	else if (ans == ov_div && ov_mod < str - '0')
		return (1);
	else
		return (0);
}

static int	setsign(const char *str)
{
	if (*str == '+' || *str == '-')
		return (44 - *str);
	else
		return (2);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	ans;

	ans = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || \
		*str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (!(ft_isdigit(*str)))
	{
		sign = setsign(str);
		if (sign == 2)
			return (0);
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (sign == 1 && check_ov(ans, *str, sign))
			return ((int)LONG_MAX);
		if (sign == -1 && check_ov(ans, *str, sign))
			return ((int)LONG_MIN);
		ans = 10 * ans + (*str - '0');
		str++;
	}
	return ((int)(ans * sign));
}

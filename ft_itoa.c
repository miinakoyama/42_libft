/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miina <miina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:45:23 by miina             #+#    #+#             */
/*   Updated: 2023/02/15 12:04:52 by miina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getlen(long ln)
{
	size_t	count;

	if (ln == 0)
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

char	*ft_itoa(int n)
{
	char	*ans;
	long	ln;
	int		sign;
	size_t	len;

	sign = 0;
	ln = (long)n;
	if (ln < 0)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:36:28 by miina             #+#    #+#             */
/*   Updated: 2023/02/16 17:56:12 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	count;

	count = 1;
	while (*s != '\0')
	{
		s++;
		count++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	while (count--)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (count != 0)
			s--;
	}
	return (NULL);
}

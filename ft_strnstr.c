/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miina <miina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 02:42:25 by miina             #+#    #+#             */
/*   Updated: 2023/02/14 21:39:14 by miina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cmp_str(const char *haystack, const char *needle, size_t len)
{
	while (*needle != '\0')
	{
		if (len-- <= 0 || *haystack != *needle)
			return (0);
		haystack++;
		needle++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (i < len && *haystack != '\0')
	{
		if (*haystack == *needle && cmp_str(haystack, needle, len - i))
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}

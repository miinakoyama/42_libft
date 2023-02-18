/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:26:06 by miina             #+#    #+#             */
/*   Updated: 2023/02/16 17:58:10 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncat(char *dest, const char *src, unsigned int nb)
{
	char	*destcp;

	destcp = dest;
	while (*destcp != '\0')
		destcp++;
	while (*src != '\0' && nb > 0)
	{
		*destcp++ = *src++;
		nb--;
	}
	*destcp = '\0';
	return (dest);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;

	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize <= 0)
		return (srclen);
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	ft_strncat(dst, src, dstsize - dstlen - 1);
	return (dstlen + srclen);
}

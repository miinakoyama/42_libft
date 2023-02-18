/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:27:09 by miina             #+#    #+#             */
/*   Updated: 2023/02/16 20:10:14 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dstcpy;
	const unsigned char	*srccpy;

	if (dst == NULL && src == NULL)
		return (NULL);
	dstcpy = (unsigned char *)dst;
	srccpy = (const unsigned char *)src;
	while (n-- > 0)
		*dstcpy++ = *srccpy++;
	return (dst);
}

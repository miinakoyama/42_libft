/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:27:29 by miina             #+#    #+#             */
/*   Updated: 2023/02/16 19:38:34 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destcpy;
	const unsigned char	*srccpy;
	size_t				i;

	destcpy = (unsigned char *)dest;
	srccpy = (const unsigned char *)src;
	if (srccpy == destcpy || n == 0)
		return (dest);
	if (srccpy < destcpy)
	{
		i = n;
		while (i-- > 0)
			destcpy[i] = srccpy[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			destcpy[i] = srccpy[i];
			i++;
		}
	}
	return (dest);
}

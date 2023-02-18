/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:36:54 by miina             #+#    #+#             */
/*   Updated: 2023/02/16 19:33:45 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ns;
	unsigned char	nc;

	ns = (unsigned char *)s;
	nc = (unsigned char)c;
	while (n--)
	{
		if (*ns == nc)
			return ((void *)ns);
		ns++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:27:32 by miina             #+#    #+#             */
/*   Updated: 2023/02/17 14:57:51 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*newbuf;
	unsigned char	nch;

	nch = (unsigned char)ch;
	newbuf = (unsigned char *)buf;
	while (n-- > 0)
		*newbuf++ = nch;
	return (buf);
}

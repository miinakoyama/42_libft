/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miina <miina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:37:17 by miina             #+#    #+#             */
/*   Updated: 2023/02/14 20:50:06 by miina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ns;
	size_t			slen;
	unsigned int	start2;

	start2 = start;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < start)
		len = 0;
	while (start--)
		s++;
	if (slen - start2 + 1 < len)
		len = slen - start2 + 1;
	ns = (char *)malloc(sizeof(char) * (len + 1));
	if (!ns)
		return (NULL);
	ft_strlcpy(ns, s, len + 1);
	return (ns);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:36:22 by miina             #+#    #+#             */
/*   Updated: 2023/02/17 14:48:22 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*ns1;
	const unsigned char	*ns2;

	if (n == 0)
		return (0);
	ns1 = (const unsigned char *)s1;
	ns2 = (const unsigned char *)s2;
	while ((*ns1 != '\0' || *ns2 != '\0') && n--)
	{
		if (*ns1 != *ns2)
			return ((int)(*ns1 - *ns2));
		ns1++;
		ns2++;
	}
	return (0);
}

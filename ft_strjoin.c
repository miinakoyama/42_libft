/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:20:48 by miina             #+#    #+#             */
/*   Updated: 2023/02/17 14:40:48 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joinedstr;
	size_t	len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		len = ft_strlen(s2) + 1;
	if (s1 && !s2)
		len = ft_strlen(s1) + 1;
	if (s1 && s2)
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joinedstr = (char *)ft_calloc(len, sizeof(char));
	if (!joinedstr)
		return (NULL);
	if (s1 && *s1 != '\0')
		ft_strlcat(joinedstr, s1, len);
	if (s2 && *s2 != '\0')
		ft_strlcat(joinedstr, s2, len);
	return (joinedstr);
}

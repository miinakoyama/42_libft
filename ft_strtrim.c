/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miina <miina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:53:47 by miina             #+#    #+#             */
/*   Updated: 2023/02/14 20:49:54 by miina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_search(char s1, char const *set)
{
	while (*set != '\0')
	{
		if (*set != s1)
			set++;
		else
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*ans;
	const char	*s1back;
	size_t		s1len;

	s1back = s1;
	if (s1 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s1back += s1len - 1;
	if (set == NULL)
		return (ft_strdup(s1));
	while (s1 && ft_search(*s1, set))
		s1++;
	while (s1len-- && ft_search(*s1back, set))
		s1back--;
	ans = ft_substr(s1, 0, s1back - s1 + 1);
	return (ans);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:09:29 by miina             #+#    #+#             */
/*   Updated: 2023/02/17 15:10:40 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
			count++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, size_t len)
{
	char	*ans;
	size_t	i;

	i = 0;
	ans = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ans)
		return (NULL);
	while (len)
	{
		ans[i] = s[i];
		len--;
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

static size_t	ft_wordlen(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != c && *s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

static char	**ft_free(char **str)
{
	char	**head;

	head = str;
	if (!str)
		return (NULL);
	while (*str)
	{
		free(*str);
		str++;
	}
	free(head);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	char	**anscpy;
	size_t	wordcount;
	size_t	wordlen;

	wordcount = ft_wordcount(s, c);
	ans = (char **)ft_calloc(wordcount + 1, sizeof(char *));
	if (!ans || !s)
		return (ft_free(ans));
	anscpy = ans;
	while (wordcount--)
	{
		while (*s == c)
			s++;
		wordlen = ft_wordlen(s, c);
		*ans = ft_strndup(s, wordlen);
		if (!*ans)
			return (ft_free(ans));
		while (*s != c && *s != '\0')
			s++;
		ans++;
	}
	*ans = NULL;
	return (anscpy);
}

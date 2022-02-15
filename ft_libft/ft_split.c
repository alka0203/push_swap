/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:20:47 by asanthos          #+#    #+#             */
/*   Updated: 2022/02/09 14:44:49 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static	size_t	count(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (j);
}

static	char	**boop(char const *s, char c, char	**mall, size_t k)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] == c && j < ft_strlen(s))
		{
			j++;
			i++;
		}
		while (s[j] != c && j < ft_strlen(s))
			j++;
		if (s[j] == c && j < ft_strlen(s))
		{
			mall[k] = ft_substr(s, i, j - i);
			i = j;
			k++;
		}
	}
	if (s[i] && s[j - 1] != c)
		mall[k] = ft_substr(s, i, j - i);
	mall[++k] = 0;
	return (mall);
}

char	**ft_split(char const *s, char c)
{
	size_t	k;
	char	**mall;

	k = 0;
	if (!s)
		return (NULL);
	mall = (char **)malloc((count(s, c) + 1) * sizeof(char *));
	if (!mall)
		return (0);
	mall = boop(s, c, mall, k);
	return (mall);
}

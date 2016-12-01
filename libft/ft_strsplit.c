/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 18:50:11 by reasaw            #+#    #+#             */
/*   Updated: 2016/09/26 18:50:12 by reasaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		wordcnt(char const *str, char x)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == x)
			i++;
		if (str[i] != x && str[i] != '\0')
			count++;
		while (str[i] != x && str[i] != '\0')
			i++;
	}
	return (count);
}

static int		wordlen(char const *str, char x)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i] == x)
		i++;
	while (str[i] != x && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void		free_loop(char **s, int index)
{
	int i;

	i = 0;
	while (i < index)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	if (!s || (str = (char**)malloc(sizeof(char*) * (wordcnt(s, c) + 1))) == 0)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < wordcnt(s, c))
	{
		k = 0;
		if ((str[i] = (char*)malloc(sizeof(char) * wordlen(&s[j], c) + 1)) == 0)
		{
			free_loop(str, i);
			return (NULL);
		}
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j] != '\0')
			str[i][k++] = s[j++];
		str[i][k] = '\0';
	}
	str[i] = NULL;
	return (str);
}

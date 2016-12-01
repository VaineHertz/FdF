/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:56:57 by reasaw            #+#    #+#             */
/*   Updated: 2016/09/26 14:56:59 by reasaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*a;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = -1;
	j = -1;
	len = ft_strlen(s1) + ft_strlen(s2);
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (a == NULL)
		return (0);
	while (s1[++i])
		a[i] = s1[i];
	while (s2[++j])
		a[i + j] = s2[j];
	a[i + j] = '\0';
	return (a);
}

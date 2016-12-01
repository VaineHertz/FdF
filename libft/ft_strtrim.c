/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 15:03:21 by reasaw            #+#    #+#             */
/*   Updated: 2016/09/26 15:03:24 by reasaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	lg_str;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	lg_str = 0;
	while (s[i] && (s[i] == '\t' || s[i] == '\n' || s[i] == ' '))
		i++;
	lg_str = ft_strlen(s + i) - 1;
	while (s[i] && (s[lg_str + i] == '\t' || s[lg_str + i] == '\n'
		|| s[lg_str + i] == ' '))
		lg_str--;
	str = ft_strnew(lg_str + 1);
	if (!str)
		return (NULL);
	ft_strncpy(str, (char *)s + i, lg_str + 1);
	return (str);
}

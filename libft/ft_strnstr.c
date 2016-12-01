/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 11:51:43 by reasaw            #+#    #+#             */
/*   Updated: 2016/09/23 13:00:45 by reasaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, unsigned int n)
{
	unsigned int	i;
	unsigned int	pos;
	unsigned int	len;

	i = 0;
	pos = 0;
	len = 0;
	while (to_find[len])
		len++;
	if (len == 0)
		return (str);
	while (str[i])
	{
		while (to_find[pos] == str[i + pos] && (i + pos) < n)
		{
			if (pos == len - 1)
				return (str + i);
			pos++;
		}
		pos = 0;
		i++;
	}
	return (0);
}

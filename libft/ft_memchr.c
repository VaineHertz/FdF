/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:06:49 by reasaw            #+#    #+#             */
/*   Updated: 2016/09/22 18:06:51 by reasaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	size_t			i;
	unsigned char	*str1;

	i = 0;
	str1 = (unsigned char *)str;
	while (i < len)
	{
		if (str1[i] == (unsigned char)c)
			return (&str1[i]);
		i++;
	}
	return (NULL);
}

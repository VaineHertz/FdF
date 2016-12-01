/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 11:14:27 by reasaw            #+#    #+#             */
/*   Updated: 2016/09/23 13:07:35 by reasaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	long dest_length;
	long i;
	long src_length;
	long s;

	s = size;
	i = 0;
	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	while ((i < size - dest_length - 1) && i < src_length)
	{
		dest[i + dest_length] = src[i];
		i++;
	}
	if (size - dest_length - 1 > 0)
		dest[i + dest_length] = '\0';
	if (s < dest_length)
		return (s + src_length);
	else
		return (dest_length + src_length);
}

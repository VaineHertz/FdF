/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:09:09 by reasaw            #+#    #+#             */
/*   Updated: 2016/09/22 18:09:12 by reasaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;

	i = len;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
		while (i-- > 0)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	return (dst);
}

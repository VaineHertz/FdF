/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 11:06:05 by reasaw            #+#    #+#             */
/*   Updated: 2016/09/23 13:50:06 by reasaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *str, int c, size_t len)
{
	int					i;
	unsigned char		*p;

	p = (unsigned char *)str;
	i = 0;
	while (len > 0)
	{
		*p = c;
		p++;
		len--;
	}
	return (str);
}

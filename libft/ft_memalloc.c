/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 12:07:00 by reasaw            #+#    #+#             */
/*   Updated: 2016/09/26 12:07:01 by reasaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*a;

	if (size == 0)
		return (NULL);
	a = (void *)malloc(size);
	if (a == NULL)
		return (NULL);
	ft_bzero(a, size);
	return (a);
}

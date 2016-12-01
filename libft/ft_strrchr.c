/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 12:47:17 by reasaw            #+#    #+#             */
/*   Updated: 2016/09/23 12:49:03 by reasaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int len;

	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == c)
			return (str + len);
		len--;
	}
	return (0);
}

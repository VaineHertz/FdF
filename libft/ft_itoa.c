/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 17:30:50 by tpadilla          #+#    #+#             */
/*   Updated: 2016/09/26 17:30:51 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(int n)
{
	int len;

	len = 0;
	if (n <= 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char			*a;
	int				len;

	len = get_length(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	a = ft_strnew(len);
	if (a == NULL)
		return (0);
	if (n < 0)
	{
		n *= -1;
		a[0] = '-';
	}
	a[len] = '\0';
	if (n == 0)
		a[--len] = '0';
	while (n > 0)
	{
		a[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:46:01 by tpadilla          #+#    #+#             */
/*   Updated: 2016/09/26 14:46:03 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*a;

	if (s == NULL)
		return (0);
	i = -1;
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (a == NULL)
		return (0);
	while (++i < len)
		a[i] = s[start + i];
	a[i] = '\0';
	return (a);
}

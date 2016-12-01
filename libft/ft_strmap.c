/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 13:10:48 by tpadilla          #+#    #+#             */
/*   Updated: 2016/09/26 13:10:49 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	char	*a;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = -1;
	a = malloc(sizeof(char) * (len + 1));
	if (a == NULL)
		return (0);
	while (s[++i])
		a[i] = f(s[i]);
	a[i] = '\0';
	return (a);
}

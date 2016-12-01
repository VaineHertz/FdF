/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 13:44:32 by tpadilla          #+#    #+#             */
/*   Updated: 2016/09/26 13:44:33 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*a;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	a = malloc(sizeof(char) * (len + 1));
	i = -1;
	if (a == NULL)
		return (0);
	while (s[++i])
		a[i] = f(i, s[i]);
	a[i] = '\0';
	return (a);
}

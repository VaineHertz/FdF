/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:35:19 by tpadilla          #+#    #+#             */
/*   Updated: 2016/09/30 17:36:10 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *rs1;
	char *rs2;

	rs1 = s1;
	rs2 = (char *)s2;
	while (*rs1)
		rs1++;
	while (*rs2 && n--)
	{
		*rs1 = *rs2;
		rs1++;
		rs2++;
	}
	*rs1 = '\0';
	return (s1);
}

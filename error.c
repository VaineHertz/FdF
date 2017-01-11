/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 04:15:15 by tpadilla          #+#    #+#             */
/*   Updated: 2017/01/11 04:35:18 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	is_number(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
		{
			ft_putendl("error: invalid map (map should have numbers only)");
			exit(0);
		}
}

int		check_format(fdf *master)
{
	if ((int)TOTAL % (int)YVALUE != 0)
	{
		ft_putendl("error: invalid map (map should be a rectangle)");
		return (0);
	}
	return (1);
}

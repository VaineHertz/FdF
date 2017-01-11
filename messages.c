/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 03:39:27 by tpadilla          #+#    #+#             */
/*   Updated: 2017/01/11 03:39:41 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ommit_directories(char *str)
{
	int		i;
	int		a;
	int		no_slash;
	char	*mapname;

	no_slash = 0;
	i = -1;
	while (str[++i])
		if (str[i] == '/')
			no_slash = i;
	mapname = (char*)malloc(sizeof(char) * (i - no_slash + 1));
	a = 0;
	if (str[no_slash + 1] && str[no_slash] == '/')
		no_slash++;
	while (no_slash < i)
	{
		mapname[a] = str[no_slash];
		no_slash++;
		a++;
	}
	mapname[a] = '\0';
	return (mapname);
}

void	intro_message(char *mapname)
{
	ft_putstr("\nMap name: ");
	mapname = ommit_directories(mapname);
	ft_putendl(mapname);
	ft_putendl("\nDirectional keys to pan\n+ and - to Zoom");
	ft_putendl("4-9 Numpad to rotate (keys paired for an axis vertically)\n");
	ft_putendl("PG UP and PG down to set Pan & Zoom speed");
	ft_putendl("Home and End to set Rotation Speed");
	ft_putendl("\nPan & Zoom acceleration is medium");
	ft_putendl("Rotate acceleration is slow");
	ft_putendl("\nPress esc to quit");
}

void	key_message(int keycode, t_fdf *master)
{
	if (keycode == 116 || keycode == 121)
	{
		if (PAN_ACCEL == 40)
			ft_putendl("\nPan & Zoom acceleration is fast");
		else if (PAN_ACCEL == 20)
			ft_putendl("\nPan & Zoom acceleration is medium");
		else if (PAN_ACCEL == 5)
			ft_putendl("\nPan & Zoom acceleration is slow");
	}
	else if (keycode == 119 || keycode == 115)
	{
		if (PHI_M == 0.1)
			ft_putendl("\nRotation acceleration is slow");
		else if (PHI_M == 0.3)
			ft_putendl("\nRotation acceleration is medium");
		else if (PHI_M == 0.5)
			ft_putendl("\nRotation acceleration is fast");
	}
}

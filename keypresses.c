/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypresses.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 21:16:59 by tpadilla          #+#    #+#             */
/*   Updated: 2016/12/16 21:07:47 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_message(int keycode, map *cds)
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
}

int		key_event(int keycode, map *cds)
{
	if (keycode == 121)
	{
		if (PAN_ACCEL == 20)
			PAN_ACCEL = 5;
		else if (PAN_ACCEL == 40)
			PAN_ACCEL = 20;
		else
			keycode = -1;
	}
	else if (keycode == 116)
	{
		if (PAN_ACCEL == 5)
			PAN_ACCEL = 20;
		else if (PAN_ACCEL == 20)
			PAN_ACCEL = 40;
		else
			keycode = -1;
	}
	else if (keycode == 92)
	{
		OPTION = 0;
		PHI[2] = 0.1;
	}
	else if (keycode == 88)
	{
		OPTION = 0;
		PHI[2] = -0.1;
	}
	else if (keycode == 89)
	{
		OPTION = 1;
		PHI[0] = 0.1;
	}
	else if (keycode == 86)
	{
		OPTION = 1;
		PHI[0] = -0.1;
	}
	else if (keycode == 91)
	{
		OPTION = 2;
		PHI[1] = 0.1;
	}
	else if (keycode == 87)
	{
		OPTION = 2;
		PHI[1] = -0.1;
	}
	else if (keycode == 69)
		ZOOM += PAN_ACCEL / 2;
	else if (keycode == 78 && ZOOM > 1)
		ZOOM -= PAN_ACCEL / 2;
	else if (keycode == 123)
		ORIGIN_X -= PAN_ACCEL;
	else if (keycode == 124)
		ORIGIN_X += PAN_ACCEL;
	else if (keycode == 125)
		ORIGIN_Y += PAN_ACCEL;
	else if (keycode == 126)
		ORIGIN_Y -= PAN_ACCEL;
	else if (keycode == 53)
		exit(0);
	key_message(keycode, cds);
	render_image(cds);
	return (0);
}


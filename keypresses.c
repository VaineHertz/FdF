/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypresses.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 21:16:59 by tpadilla          #+#    #+#             */
/*   Updated: 2016/12/20 15:24:58 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_rotate(int keycode, t_fdf *master)
{
	if (keycode != 90)
		PHI = PHI_M;
	if (keycode == 92 || keycode == 88)
	{
		OPTION = 0;
		PHI = ABS(PHI);
		if (keycode == 88)
			PHI = ABS(PHI) * -1;
	}
	else if (keycode == 89 || keycode == 86)
	{
		OPTION = 1;
		PHI = ABS(PHI);
		if (keycode == 89)
			PHI = ABS(PHI) * -1;
	}
	else if (keycode == 91 || keycode == 87)
	{
		OPTION = 2;
		PHI = ABS(PHI);
		if (keycode == 87)
			PHI = ABS(PHI) * -1;
	}
}

void	key_transform(int keycode, t_fdf *master)
{
	if (keycode > 85 && keycode < 93)
		key_rotate(keycode, master);
	else if (keycode == 123)
		ORIGIN_X -= PAN_ACCEL;
	else if (keycode == 124)
		ORIGIN_X += PAN_ACCEL;
	else if (keycode == 125)
		ORIGIN_Y += PAN_ACCEL;
	else if (keycode == 126)
		ORIGIN_Y -= PAN_ACCEL;
	else if (keycode == 69)
		ZOOM += PAN_ACCEL / 2;
	else if (keycode == 78 && ZOOM - PAN_ACCEL > 0)
		ZOOM -= PAN_ACCEL / 2;
}

void	set_pan_accel(int keycode, t_fdf *master)
{
	if (keycode == 121)
	{
		if (PAN_ACCEL == 20)
			PAN_ACCEL = 5;
		else if (PAN_ACCEL == 40)
			PAN_ACCEL = 20;
	}
	else if (keycode == 116)
	{
		if (PAN_ACCEL == 5)
			PAN_ACCEL = 20;
		else if (PAN_ACCEL == 20)
			PAN_ACCEL = 40;
	}
}

int		key_speed(int keycode, t_fdf *master)
{
	int skip;

	skip = 0;
	if (keycode == 121 || keycode == 116)
		set_pan_accel(keycode, master);
	else if (keycode == 115)
	{
		if (ABS(PHI_M) == 0.1)
			PHI_M = 0.3;
		else if (ABS(PHI_M) == 0.3)
			PHI_M = 0.5;
		skip = 1;
	}
	else if (keycode == 119)
	{
		if (ABS(PHI_M) == 0.3)
			PHI_M = 0.1;
		else if (ABS(PHI_M) == 0.5)
			PHI_M = 0.3;
		skip = 1;
	}
	return (skip);
}

int		key_event(int keycode, t_fdf *master)
{
	int	skip;

	skip = 0;
	if (keycode > 114 && keycode < 122)
		skip = key_speed(keycode, master);
	else if ((keycode > 68 && keycode < 93) || (keycode > 122 && keycode < 127))
		key_transform(keycode, master);
	else if (keycode == 53)
		exit(0);
	key_message(keycode, master);
	if (!skip)
	{
		master->imge->image_p = mlx_new_image(master->mlx_w->mlx,
			master->mlx_w->window_width, master->mlx_w->window_length);
		master->imge->image_char_p = mlx_get_data_addr(master->imge->image_p,
			&master->imge->bpp, &master->imge->size_line,
			&master->imge->endian);
		render_image(master);
		mlx_put_image_to_window(MLX, WIN, master->imge->image_p, 0, 0);
		mlx_destroy_image(MLX, master->imge->image_p);
	}
	return (0);
}

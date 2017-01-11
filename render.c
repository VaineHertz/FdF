/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 03:49:16 by tpadilla          #+#    #+#             */
/*   Updated: 2017/01/11 03:49:19 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*get_color(double z, fdf *master)
{
	int	color;
	int	*rgb;

	rgb = (int*)malloc(sizeof(int) * 3);
	rgb[0] = 0x00FFFFFF - (z / (master->cds->max_height * 100000) * 100);
	rgb[1] = 0x00FFFFFF - (z / (master->cds->max_height * 100000) * 255);
	rgb[2] = 0x00FFFFFF - (z / (master->cds->max_height * 100000) * 255);
	if (!z)
	{
		rgb[0] = 255;
		rgb[1] = 255;
		rgb[2] = 255;
		return (rgb);
	}
	return (rgb);
}

void	pixel_to_image(fdf *master, int x, int y, int z)
{
	int		i;
	int		*color;

	if (x >= 0 && x < master->mlx_w->window_width && y >= 0
		&& y < master->mlx_w->window_length)
	{
		color = get_color(z, master);
		i = ((4 * x) + (y * master->imge->size_line));
		master->imge->image_char_p[i] = color[2];
		master->imge->image_char_p[i + 1] = color[1];
		master->imge->image_char_p[i + 2] = color[0];
		free(color);
	}
}

void	line(double *pt1, double *pt2, fdf *master)
{
	int		xyz_diff[3];
	int		length;
	int		max;
	int		xy[3];

	xy[0] = 100000 * pt1[0];
	xy[1] = 100000 * pt1[1];
	xy[2] = 100000 * pt1[3];
	xyz_diff[0] = pt1[0] - pt2[0];
	xyz_diff[1] = pt1[1] - pt2[1];
	xyz_diff[2] = pt1[3] - pt2[3];
	if (ABS(xyz_diff[0]) > ABS(xyz_diff[1]) ||
			ABS(xyz_diff[0]) == ABS(xyz_diff[1]))
		length = ABS(xyz_diff[0]);
	if (ABS(xyz_diff[0]) < ABS(xyz_diff[1]))
		length = ABS(xyz_diff[1]);
	max = length + 1;
	while (--max)
	{
		xy[0] -= (xyz_diff[0] * 100000) / length;
		xy[1] -= (xyz_diff[1] * 100000) / length;
		xy[2] -= (xyz_diff[2] * 100000) / length;
		pixel_to_image(master, (xy[0] / 100000) + TRANSLATE_X,
			(xy[1] / 100000) + TRANSLATE_Y, xy[2]);
	}
}

/*
** a[0] is the index of which point we are on, and a[1] is the index of
** the dot to the right or underneath a[0]
**
** c is the row count, we start on the first row
** we use c to check if our index a[0] is the last point of the row
** if it is, we do not draw to the right.
** if it attempted to it would be a line resembling a '/' going
** from the rightmost of its row for the first point to the
** leftmost of the next row underneath
*/

void	connect_line(fdf *master, int a, int *c)
{
	double	*temp_xy;
	double	*temp_xy2;
	int		b;

	temp_xy = ortho_proj(VALUE[a], master);
	if ((VALUE[a + 1] && (a != (*c * WIDTH - 1)))
			|| (a + WIDTH < TOTAL))
	{
		b = (a + WIDTH < TOTAL) ? WIDTH : 1;
		temp_xy2 = ortho_proj(VALUE[a + b], master);
		line(temp_xy, temp_xy2, master);
		if (b == WIDTH && VALUE[a + 1] && (a != (*c * WIDTH) - 1))
		{
			b = 1;
			temp_xy2 = ortho_proj(VALUE[a + b], master);
			line(temp_xy, temp_xy2, master);
		}
		free(temp_xy2);
	}
	if (a == *c * WIDTH - 1)
		(*c)++;
	free(temp_xy);
}

void	render_image(fdf *master)
{
	int		a;
	int		c;

	c = 1;
	a = -1;
	mlx_clear_window(MLX, WIN);
	while (++a < TOTAL)
		rotate_map(VALUE[a], master);
	OPTION = -1;
	PHI = 0;
	a = -1;
	while (++a < TOTAL)
		connect_line(master, a, &c);
}

/*
** Bresenham's Line algorithm
**
** void	line(double *p1, double *p2, fdf *master, int color, int a)
**{
**	double	*temp_p1;
**	double	dxy[2];
**	double	err;
**	double	e2;
**
**	temp_p1 = (double *)malloc(sizeof(double) * 2);
**	temp_p1[0] = p1[0];
**	temp_p1[1] = p1[1];
**	dxy[0] = ABS(p2[0] - p1[0]);
**	dxy[1] = ABS(p2[1] - p1[1]);
**	err = (dxy[0] > dxy[1] ? dxy[0] : -dxy[1]) / 2;
**	while (1)
**	{
**		mlx_pixel_put(MLX, WIN, temp_p1[0] + TRANSLATE_X,
**				temp_p1[1] + TRANSLATE_Y, color);
**		if ((int)temp_p1[0] == (int)p2[0] && (int)temp_p1[1] == (int)p2[1])
**			break ;
**		e2 = err;
**		if (e2 > -dxy[0])
**		{
**			err -= dxy[1];
**			if (temp_p1[0] < p2[0])
**				temp_p1[0] += 1;
**			else
**				temp_p1[0] -= 1;
**		}
**		if (e2 < dxy[1])
**		{
**			err += dxy[0];
**			if (temp_p1[1] < p2[1])
**				temp_p1[1] += 1;
**			else
**				temp_p1[1] -= 1;
**		}
**	}
**}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:48:46 by tpadilla          #+#    #+#             */
/*   Updated: 2016/12/20 15:11:54 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#	define FDF_H

#	include "libft/libft.h"
#	include "minilibx_macos/mlx.h"
#	include <fcntl.h>
#	include <math.h>
#	define X master->cds->x
#	define Y master->cds->y
#	define MLX master->mlx_w->mlx
#	define WIN master->mlx_w->window
#	define ZOOM master->m_cds->zoom
#	define ORIGIN_X master->cds->origin_x
#	define ORIGIN_Y master->cds->origin_y
#	define PAN_ACCEL master->m_cds->pan_accelaration
#	define VALUE master->cds->value
#	define TOTAL master->cds->total
#	define YVALUE master->cds->yvalue
#	define PHI master->m_cds->phi
#	define PHI_M master->m_cds->phi_mod
#	define OPTION master->m_cds->option
#	define TRANSLATE_X (ORIGIN_X + (master->mlx_w->window_width / 2))
#	define TRANSLATE_Y (ORIGIN_Y + (master->mlx_w->window_length / 2))
#	define RED 0x00FF0000
#	define BLUE 0x000000FF
#	define GREEN 0x0000FF00
#	define ABS(a) ((a)<0?(-(a)):(a))
#	include <stdio.h>
#	include <math.h>

typedef struct	twodee_map
{
	double	x;
	double	y;
	double	origin_x;
	double	origin_y;
	double	**value;
	double	total;
	double	yvalue;
}			map;

typedef struct	modify_map
{
	double	zoom;
	double	phi;
	double	phi_mod;
	double	pan_accelaration;
	double	option;
}			mod;

typedef struct	window_data
{
	void	*mlx;
	void	*window;
	double	window_width;
	double	window_length;
	char	*file;
}			w_data;

typedef struct	wireframe_data
{
	map		*cds;
	mod		*m_cds;
	w_data	*mlx_w;
}			fdf;

void	key_message(int keycode, fdf *master);
int		key_event(int keycode, fdf *master);
void	render_image(fdf *master);

#endif

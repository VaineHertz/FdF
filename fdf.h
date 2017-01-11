/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:48:46 by tpadilla          #+#    #+#             */
/*   Updated: 2017/01/11 04:09:19 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#	define FDF_H

#	include "libft/libft.h"
#	include "minilibx_macos/mlx.h"
#	include <fcntl.h>
#	include <math.h>
#	include <stdio.h>
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
#	define WIDTH (TOTAL / YVALUE)
#	define RED 0x00FF0000
#	define BLUE 0x000000FF
#	define GREEN 0x0000FF00
#	define ABS(a) ((a)<0?(-(a)):(a))

typedef struct	twodee_map
{
	double	x;
	double	y;
	double	max_height;
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

typedef struct	image_data
{
	void	*image_p;
	char	*image_char_p;
	int		bpp;
	int		size_line;
	int		endian;
}			img;


typedef struct	wireframe_data
{
	map		*cds;
	mod		*m_cds;
	w_data	*mlx_w;
	img		*imge;
}			fdf;

double	*ortho_proj(double *og_xyz, fdf *master);
double	*rotate_map(double *og_xyz, fdf *master);
void	window_handler(fdf *master);
int		key_event(int keycode, fdf *master);
void	key_message(int keycode, fdf *master);
void	key_rotate(int keycode, fdf *master);
void	key_transform(int keycode, fdf *master);
int		key_speed(int keycode, fdf *master);
void	set_pan_accel(int keycode, fdf *master);
void	intro_message(char *mapname);
int		*get_xy(char *file);
void	render_image(fdf *master);
char	*ommit_directories(char *str);
map		*init_map(char *file);
mod		*init_mod(void);
w_data	*init_window(map *cds, mod *m_cds, char *file);
img		*init_image(w_data *mlx_w);
fdf		*init_master(char *file);
void	get_cds(fdf *master);
void	assign_cds(fdf *master, char **nbrline, int *a);
int		check_format(fdf *master);
void	is_number(char *str);

#endif

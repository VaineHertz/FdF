/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:48:46 by tpadilla          #+#    #+#             */
/*   Updated: 2017/01/11 05:20:11 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# define X master->cds->x
# define Y master->cds->y
# define MLX master->mlx_w->mlx
# define WIN master->mlx_w->window
# define ZOOM master->m_cds->zoom
# define ORIGIN_X master->cds->origin_x
# define ORIGIN_Y master->cds->origin_y
# define PAN_ACCEL master->m_cds->pan_accelaration
# define VALUE master->cds->value
# define TOTAL master->cds->total
# define YVALUE master->cds->yvalue
# define PHI master->m_cds->phi
# define PHI_M master->m_cds->phi_mod
# define OPTION master->m_cds->option
# define TRANSLATE_X (ORIGIN_X + (master->mlx_w->window_width / 2))
# define TRANSLATE_Y (ORIGIN_Y + (master->mlx_w->window_length / 2))
# define WIDTH (TOTAL / YVALUE)
# define RED 0x00FF0000
# define BLUE 0x000000FF
# define GREEN 0x0000FF00
# define ABS(a) ((a)<0?(-(a)):(a))

typedef struct	s_twodee_map
{
	double		x;
	double		y;
	double		max_height;
	double		origin_x;
	double		origin_y;
	double		**value;
	double		total;
	double		yvalue;
}				t_map;

typedef struct	s_modify_map
{
	double		zoom;
	double		phi;
	double		phi_mod;
	double		pan_accelaration;
	double		option;
}				t_mod;

typedef struct	s_window_data
{
	void		*mlx;
	void		*window;
	double		window_width;
	double		window_length;
	char		*file;
}				t_w_data;

typedef struct	s_image_data
{
	void		*image_p;
	char		*image_char_p;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_wireframe_data
{
	t_map		*cds;
	t_mod		*m_cds;
	t_w_data	*mlx_w;
	t_img		*imge;
}				t_fdf;

double			*ortho_proj(double *og_xyz, t_fdf *master);
double			*rotate_map(double *og_xyz, t_fdf *master);
void			window_handler(t_fdf *master);
int				key_event(int keycode, t_fdf *master);
void			key_message(int keycode, t_fdf *master);
void			key_rotate(int keycode, t_fdf *master);
void			key_transform(int keycode, t_fdf *master);
int				key_speed(int keycode, t_fdf *master);
void			set_pan_accel(int keycode, t_fdf *master);
void			intro_message(char *mapname);
int				*get_xy(char *file);
void			render_image(t_fdf *master);
char			*ommit_directories(char *str);
t_map			*init_map(char *file);
t_mod			*init_mod(void);
t_w_data		*init_window(t_map *cds, t_mod *m_cds, char *file);
t_img			*init_image(t_w_data *mlx_w);
t_fdf			*init_master(char *file);
void			get_cds(t_fdf *master);
void			assign_cds(t_fdf *master, char **nbrline, int *a);
int				check_format(t_fdf *master);
void			is_number(char *str);
void			error(int message);

#endif

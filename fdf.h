/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:48:46 by tpadilla          #+#    #+#             */
/*   Updated: 2016/12/16 20:35:05 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#	define FDF_H

#	include "libft/libft.h"
#	include "minilibx_macos/mlx.h"
#	include <fcntl.h>
#	include <math.h>
#	define X cds->x
#	define Y cds->y
#	define MLX cds->mlx
#	define WIN cds->window
#	define ZOOM cds->zoom
#	define ORIGIN_X cds->origin_x
#	define ORIGIN_Y cds->origin_y
#	define PAN_ACCEL cds->pan_accelaration
#	define VALUE cds->value
#	define TOTAL cds->total
#	define XYVALUE cds->xyvalue
#	define PHI cds->phi
#	define OPTION cds->option
#	define RED 2
#	define BLUE 1
#	define GREEN 0
#	define ABS(a) ((a)<0?(-(a)):(a))
#	include <stdio.h>
#	include <math.h>

typedef struct	twodee_map
{
	char	*file;
	double	x;
	double	y;
	double	origin_x;
	double	origin_y;
	double	zoom;
	int		pan_accelaration;
	void	*mlx;
	void	*window;
	double	**value;
	int		total;
	int		*xyvalue;
	double	phi[3];
	int		option;
}			map;

void	key_message(int keycode, map *cds);
int		key_event(int keycode, map *cds);
void	render_image(map *cds);

#endif

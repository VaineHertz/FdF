/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:48:46 by tpadilla          #+#    #+#             */
/*   Updated: 2016/12/16 08:20:08 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#	define FDF_H

#	include "libft/libft.h"
#	include "minilibx_macos/mlx.h"
#	include <fcntl.h>
#	include <math.h>
#	define X cds->xwithz
#	define Y cds->ywithz
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
#	define W_SIZE 600
#	include <stdio.h>
#	include <math.h>

typedef struct	twodee_map
{
	char	*file;
	float	xwithz;
	float	ywithz;
	int		origin_x;
	int		origin_y;
	float	zoom;
	int		pan_accelaration;
	void	*mlx;
	void	*window;
	int		**value;
	int		total;
	int		*xyvalue;
	float	phi[3];
	int		option;
}			map;

void	key_message(int keycode, map *cds);
int		key_event(int keycode, map *cds);
void	render_image(map *cds);

#endif

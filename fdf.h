/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:48:46 by tpadilla          #+#    #+#             */
/*   Updated: 2016/12/04 16:37:23 by tpadilla         ###   ########.fr       */
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
#	define VALUE cds->data

typedef struct	twodee_map
{
	char	*file;
	int		xwithz;
	int		ywithz;
	int		origin_x;
	int		origin_y;
	int		zoom;
	int		pan_accelaration;
	void	*mlx;
	void	*window;
	int		**data;
}			map;

#endif

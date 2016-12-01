/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:03:34 by reasaw            #+#    #+#             */
/*   Updated: 2016/11/30 16:09:18 by reasaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#	define FDF_H

#	include "libft/libft.h"
#	include "minilibx_macos/mlx.h"
#	include <fcntl.h>
#	define X cds->x
#	define Y cds->y
#	define MLX cds->mlx
#	define WIN cds->window

typedef struct	twodee_map
{
	int		x;
	int 	y;
	void	*mlx;
	void	*window;
}			map;

#endif
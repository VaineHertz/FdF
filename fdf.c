/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:50:44 by tpadilla          #+#    #+#             */
/*   Updated: 2017/01/11 04:31:38 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	*ortho_proj(double *og_xyz, fdf *master)
{
	double	*temp_xy;
	double	temp_z;

	temp_xy = (double *)malloc(sizeof(double) * 4);
	temp_xy[3] = og_xyz[3];
	temp_z = og_xyz[2];
	temp_xy[0] = og_xyz[0];
	temp_xy[1] = og_xyz[1];
	temp_xy[0] = ZOOM / 64 * temp_xy[0];
	temp_xy[1] = ZOOM / 64 * temp_z;
	return (temp_xy);
}

double	*rotate_map(double *og_xyz, fdf *master)
{
	double	temp_xyz[3];

	temp_xyz[0] = og_xyz[0];
	temp_xyz[1] = og_xyz[1];
	temp_xyz[2] = og_xyz[2];
	if (OPTION == 0)
	{
		og_xyz[0] = temp_xyz[0] * cos(PHI) - temp_xyz[1] * sin(PHI);
		og_xyz[1] = temp_xyz[1] * cos(PHI) + temp_xyz[0] * sin(PHI);
	}
	else if (OPTION == 1)
	{
		og_xyz[1] = temp_xyz[1] * cos(PHI) - temp_xyz[2] * sin(PHI);
		og_xyz[2] = temp_xyz[2] * cos(PHI) + temp_xyz[1] * sin(PHI);
	}
	else if (OPTION == 2)
	{
		og_xyz[0] = temp_xyz[0] * cos(PHI) - temp_xyz[2] * sin(PHI);
		og_xyz[2] = temp_xyz[2] * cos(PHI) + temp_xyz[0] * sin(PHI);
	}
	return (og_xyz);
}

void	window_handler(fdf *master)
{
	render_image(master);
	mlx_put_image_to_window(MLX, WIN, master->imge->image_p, 0, 0);
	mlx_destroy_image(MLX, master->imge->image_p);
	mlx_key_hook(WIN, key_event, master);
	mlx_loop(MLX);
}

int		main(int argc, char **argv)
{
	fdf		*master;

	if (argc != 2)
	{
		ft_putendl("usage: ./fdf source_map");
		return (0);
	}
	master = init_master(argv[1]);
	get_cds(master);
	if (!check_format(master))
		return (0);
	intro_message(argv[1]);
	window_handler(master);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_master.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 03:50:05 by tpadilla          #+#    #+#             */
/*   Updated: 2017/01/11 03:50:07 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map		*init_map(char *file)
{
	t_map	*cds;
	int		*xy;

	cds = (t_map*)malloc(sizeof(t_map));
	xy = get_xy(file);
	if (!xy[0])
		error(1);
	cds->yvalue = xy[1];
	cds->total = xy[0];
	cds->max_height = 0;
	cds->x = 0;
	cds->y = 0;
	cds->origin_x = (cds->total / cds->yvalue) / 2;
	cds->origin_y = cds->yvalue / 2;
	return (cds);
}

t_mod		*init_mod(void)
{
	t_mod	*m_cds;

	m_cds = (t_mod*)malloc(sizeof(t_mod));
	m_cds->pan_accelaration = 20;
	m_cds->zoom = 20;
	m_cds->phi = 0.1;
	m_cds->option = 0;
	m_cds->phi_mod = 0.1;
	return (m_cds);
}

t_w_data	*init_window(t_map *cds, t_mod *m_cds, char *file)
{
	t_w_data	*mlx_w;
	char		*mapname;

	mlx_w = (t_w_data*)malloc(sizeof(t_w_data));
	mlx_w->mlx = mlx_init();
	mlx_w->window_width = (cds->total / cds->yvalue) * m_cds->zoom * 2.5 < 1000
		? ((cds->total / cds->yvalue) * m_cds->zoom * 2.5) : 1000;
	mlx_w->window_length = (cds->yvalue * m_cds->zoom) * 2.5 < 1000
		? ((cds->yvalue * m_cds->zoom) * 2.5) : 1000;
	mapname = ommit_directories(file);
	mlx_w->window = mlx_new_window(mlx_w->mlx, mlx_w->window_width,
			mlx_w->window_length, mapname);
	mlx_w->file = file;
	return (mlx_w);
}

t_img		*init_image(t_w_data *mlx_w)
{
	t_img *imge;

	imge = (t_img*)malloc(sizeof(t_img));
	imge->image_p = mlx_new_image(mlx_w->mlx,
			mlx_w->window_width, mlx_w->window_length);
	imge->image_char_p = mlx_get_data_addr(imge->image_p,
			&imge->bpp, &imge->size_line, &imge->endian);
	return (imge);
}

t_fdf		*init_master(char *file)
{
	t_fdf		*master;

	master = (t_fdf*)malloc(sizeof(t_fdf));
	master->cds = init_map(file);
	master->m_cds = init_mod();
	master->mlx_w = init_window(master->cds, master->m_cds, file);
	master->imge = init_image(master->mlx_w);
	return (master);
}

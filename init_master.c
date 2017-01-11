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

map		*init_map(char *file)
{
	map		*cds;
	int		*xy;

	cds = (map*)malloc(sizeof(map));
	xy = get_xy(file);
	cds->yvalue = xy[1];
	cds->total = xy[0];
	cds->max_height = 0;
	cds->x = 0;
	cds->y = 0;
	cds->origin_x = (cds->total / cds->yvalue) / 2;
	cds->origin_y = cds->yvalue / 2;
	return (cds);
}

mod		*init_mod(void)
{
	mod	*m_cds;

	m_cds = (mod*)malloc(sizeof(mod));
	m_cds->pan_accelaration = 20;
	m_cds->zoom = 20;
	m_cds->phi = 0.1;
	m_cds->option = 0;
	m_cds->phi_mod = 0.1;
	return (m_cds);
}

w_data	*init_window(map *cds, mod *m_cds, char *file)
{
	w_data	*mlx_w;
	char	*mapname;

	mlx_w = (w_data*)malloc(sizeof(w_data));
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

img		*init_image(w_data *mlx_w)
{
	img *imge;

	imge = (img*)malloc(sizeof(img));
	imge->image_p = mlx_new_image(mlx_w->mlx,
			mlx_w->window_width, mlx_w->window_length);
	imge->image_char_p = mlx_get_data_addr(imge->image_p,
			&imge->bpp, &imge->size_line, &imge->endian);
	return (imge);
}

fdf		*init_master(char *file)
{
	fdf		*master;

	master = (fdf*)malloc(sizeof(fdf));
	master->cds = init_map(file);
	master->m_cds = init_mod();
	master->mlx_w = init_window(master->cds, master->m_cds, file);
	master->imge = init_image(master->mlx_w);
	return (master);
}

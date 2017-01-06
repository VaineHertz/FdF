/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:50:44 by tpadilla          #+#    #+#             */
/*   Updated: 2016/12/20 21:42:41 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	*ortho_proj(double *og_xyz, fdf *master)
{
	double	*temp_xy;
	double	temp_z;

	temp_xy = (double *)malloc(sizeof(double) * 2);
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

void	print_cds(double *p, int option)
{
	if (option == 0)
		ft_putendl("\nFirst point: ");
	else
		ft_putendl("\nSecond point: ");
	ft_putstr("X: ");
	ft_putnbr(p[0]);
	ft_putstr("\nY: ");
	ft_putnbr(p[1]);
	if (option != 0)
		ft_putchar('\n');
}

void	line(double *p1, double *p2, fdf *master, int color, int a)
{
	double	*temp_p1;
	double	dxy[2];
	double	err;
	double	e2;

	temp_p1 = (double *)malloc(sizeof(double) * 2);
	temp_p1[0] = p1[0];
	temp_p1[1] = p1[1];
	dxy[0] = ABS(p2[0] - p1[0]);
	dxy[1] = ABS(p2[1] - p1[1]);
	err = (dxy[0] > dxy[1] ? dxy[0] : -dxy[1]) / 2;
	while (1)
	{
		mlx_pixel_put(MLX, WIN, temp_p1[0] + TRANSLATE_X,
				temp_p1[1] + TRANSLATE_Y, color);
		if ((int)temp_p1[0] == (int)p2[0] && (int)temp_p1[1] == (int)p2[1])
			break ;
		e2 = err;
		if (e2 > -dxy[0])
		{
			err -= dxy[1];
			if (temp_p1[0] < p2[0])
				temp_p1[0] += 1;
			else
				temp_p1[0] -= 1;
		}
		if (e2 < dxy[1])
		{
			err += dxy[0];
			if (temp_p1[1] < p2[1])
				temp_p1[1] += 1;
			else
				temp_p1[1] -= 1;
		}
	}
}

void	color_check(fdf *master, double *p1, double *p2, int a, int option)
{
	int		width;
	double	temp_p1[2];
	double	temp_p2[2];

	width = TOTAL / YVALUE;
	if (option == 1)
	{
		if (VALUE[a][3] > 0 && VALUE[a + 1][3] > 0)
			line(p1, p2, master, RED, a);
		else
			line(p1, p2, master, BLUE, a);
	}
	else if (option == 2)
	{
		if (VALUE[a][3] > 0 && VALUE[a + width][3] > 0)
			line(p1, p2, master, RED, a);
		else
			line(p1, p2, master, BLUE, a);
	}
}

void	render_image(fdf *master)
{
	int		width;
	int		c;
	int		a;
	double	*temp_xy;
	double	*temp_xy2;

	a = 0;
	c = 1;
	width = TOTAL / YVALUE;
	mlx_clear_window(MLX, WIN);
	while (a < TOTAL)
	{
		rotate_map(VALUE[a], master);
		a++;
	}
	OPTION = -1;
	PHI = 0;
	a = 0;
	while (a < TOTAL)
	{
		temp_xy = ortho_proj(VALUE[a], master);
		if (VALUE[a + 1] && (a != (c * width) - 1))
		{
			temp_xy2 = ortho_proj(VALUE[a + 1], master);
			color_check(master, temp_xy, temp_xy2, a, 1);
		}
		if (a == c * width - 1)
			c++;
		if (a + width < TOTAL)
		{
			temp_xy2 = ortho_proj(VALUE[a + width], master);
			color_check(master, temp_xy, temp_xy2, a, 2);
		}
		a++;
		free(temp_xy);
	}
}

int		*get_xy(char *file)
{
	int		*xy;
	int		fd;
	char	*line;
	int		i;
	char	**nbrline;

	xy = (int *)malloc(sizeof(int) * 2);
	xy[0] = 0;
	xy[1] = 0;
	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		nbrline = ft_strsplit(line, ' ');
		while (nbrline[i])
		{
			xy[0]++;
			i++;
		}
		i = 0;
		xy[1]++;
	}
	return (xy);
}

map		*init_map(char *file)
{
	map		*cds;
	int		*xy;

	cds = (map*)malloc(sizeof(map));
	xy = get_xy(file);
	cds->yvalue = xy[1];
	cds->total = xy[0];
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
	m_cds->phi = 0;
	m_cds->phi_mod = 0.1;
	return (m_cds);
}

w_data	*init_window(map *cds, mod *m_cds, char *file)
{
	w_data	*mlx_w;

	mlx_w = (w_data*)malloc(sizeof(w_data));
	mlx_w->mlx = mlx_init();
	mlx_w->window_width = (cds->total / cds->yvalue) * m_cds->zoom * 2.5 < 1000
		? ((cds->total / cds->yvalue) * m_cds->zoom * 2.5) : 1000;
	mlx_w->window_length = (cds->yvalue * m_cds->zoom) * 2.5 < 1000
		? ((cds->yvalue * m_cds->zoom) * 2.5) : 1000;
	mlx_w->window = mlx_new_window(mlx_w->mlx, mlx_w->window_width,
			mlx_w->window_length, file);
	mlx_w->file = file;
	return (mlx_w);
}

fdf		*init_master(char *file)
{
	fdf		*master;

	master = (fdf*)malloc(sizeof(fdf));
	master->cds = init_map(file);
	master->m_cds = init_mod();
	master->mlx_w = init_window(master->cds, master->m_cds, file);
	return (master);
}

void	get_cds(fdf *master)
{
	int		i;
	int		a;
	int		fd;
	char	*line;
	char	**nbrline;

	X = 0;
	Y = 0;
	fd = open(master->mlx_w->file, O_RDONLY);
	i = -1;
	a = 0;
	VALUE = (double **)malloc(sizeof(double *) * TOTAL);
	while (++i < TOTAL)
		VALUE[i] = (double *)malloc(sizeof(double) * 4);
	i = 0;
	while (get_next_line(fd, &line))
	{
		nbrline = ft_strsplit(line, ' ');
		while (nbrline[i])
		{
			VALUE[a][3] = ft_atoi(nbrline[i]);
			VALUE[a][2] = VALUE[a][3] * 60;
			VALUE[a][0] = X - ((TOTAL / YVALUE) * 40);
			VALUE[a][1] = Y - (YVALUE * 40);
			X += 80;
			i++;
			a++;
		}
		Y += 80;
		X = 0;
		i = 0;
	}
}

void	window_handler(fdf *master)
{
	render_image(master);
	mlx_key_hook(WIN, key_event, master);
	mlx_loop(MLX);
}

void	intro_message(char *mapname)
{
	ft_putstr("\nMap name: ");
	ft_putendl(mapname);
	ft_putendl("\nDirectional keys to pan\n+ and - to Zoom");
	ft_putendl("4-9 Numpad to rotate (keys paired for an axis vertically)\n");
	ft_putendl("PG UP and PG down to set Pan & Zoom speed");
	ft_putendl("Home and End to set Rotation Speed");
	ft_putendl("\nPan & Zoom acceleration is medium");
	ft_putendl("Rotate acceleration is slow");
	ft_putendl("\nPress esc to quit");
}

int		main(int argc, char **argv)
{
	fdf		*master;

	if (argc != 2)
	{
		ft_putendl("usage: ./fdf source_map");
		return (0);
	}
	intro_message(argv[1]);
	master = init_master(argv[1]);
	get_cds(master);
	window_handler(master);
	return (0);
}

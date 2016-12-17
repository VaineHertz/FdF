/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:50:44 by tpadilla          #+#    #+#             */
/*   Updated: 2016/12/16 21:19:26 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	*ortho_proj(double *og_xyz, map *cds)
{
	double *temp_xy;
	double	temp_z;

	temp_xy = (double *)malloc(sizeof(double) * 2);
	temp_z = og_xyz[2];
	temp_xy[0] = og_xyz[0];
	temp_xy[1] = og_xyz[1];
	temp_xy[0] = ZOOM / 64 * temp_xy[0] + 0;
	temp_xy[1] = ZOOM / 64 * temp_z + 0;
	return (temp_xy);
}

double	*rotate_map(double *og_xyz, map *cds)
{
	double temp_xyz[3];

	temp_xyz[0] = og_xyz[0];
	temp_xyz[1] = og_xyz[1];
	temp_xyz[2] = og_xyz[2];
	if (OPTION == 0)
	{
		og_xyz[0] = temp_xyz[0] * cos(PHI[2]) - temp_xyz[1] * sin(PHI[2]);
		og_xyz[1] = temp_xyz[1] * cos(PHI[2]) + temp_xyz[0] * sin(PHI[2]);
	}
	else if (OPTION == 1)
	{
		og_xyz[1] = temp_xyz[1] * cos(PHI[0]) - temp_xyz[2] * sin(PHI[0]);
		og_xyz[2] = temp_xyz[2] * cos(PHI[0]) + temp_xyz[1] * sin(PHI[0]);
	}
	else if (OPTION == 2)
	{
		og_xyz[0] = temp_xyz[0] * cos(PHI[1]) - temp_xyz[2] * sin(PHI[1]);
		og_xyz[2] = temp_xyz[2] * cos(PHI[1]) + temp_xyz[0] * sin(PHI[1]);
	}
	return (og_xyz);
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

void	line(int x0, int y0, int x1, int y1, map *cds, int color) 
{
	int		dx = ABS(x1-x0);
	int		sx = x0<x1 ? 1 : -1;
	int		 dy = ABS(y1-y0);
	int		sy = y0<y1 ? 1 : -1;
	int		err = (dx>dy ? dx : -dy)/2, e2;
	int		hex;

	if (color == RED)
		hex = 0x00FF0000;
	else if (color == BLUE)
		hex = 0x000000FF;
	else if (color == GREEN)
		hex = 0x0000FF00;
 	while(1)
	{
		mlx_pixel_put(MLX, WIN, (int)x0, (int)y0, hex);
		if ((int)x0==(int)x1 && (int)y0==(int)y1)
			break;
    	e2 = err;
		if (e2 >-dx)
		{ 
			err -= dy; 
			x0 += sx;
		}
	    if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	draw_everything(map *cds, int color)
{
	int width;
	int c;
	int	a;
	double	*temp_xy;
	double	*temp_xy_right;
	double	*temp_xy_under;

	a = 0;
	c = 1;
	width = TOTAL / XYVALUE[1];
	while (a < TOTAL)
	{
		rotate_map(VALUE[a], cds);
		a++;
	}
	PHI[0] = 0;
	PHI[1] = 0;
	PHI[2] = 0;
	a = 0;
	while(a < TOTAL)
	{
		temp_xy = ortho_proj(VALUE[a], cds);
		if (VALUE[a + 1] && (a != (c * width) - 1)) //this if statement handles drawing to the right
		{
			temp_xy_right = ortho_proj(VALUE[a + 1], cds);
			if (VALUE[a][3] > 0 && VALUE[a + 1][3] > 0) //colors red if both points are greater than 0
				line(temp_xy[0] + ORIGIN_X, temp_xy[1] + ORIGIN_Y, temp_xy_right[0] + ORIGIN_X, temp_xy_right[1] + ORIGIN_Y, cds, RED);
			else
				line(temp_xy[0] + ORIGIN_X, temp_xy[1] + ORIGIN_Y, temp_xy_right[0] + ORIGIN_X, temp_xy_right[1] + ORIGIN_Y, cds, BLUE);
		}
		if (a == c * width - 1)
			c++;
		if (a + width < TOTAL) //this if statement checks one under
		{
			temp_xy_under = ortho_proj(VALUE[a + width], cds);
			if (VALUE[a][3] > 0 && VALUE[a + width][3] > 0) // colors red if both points are greater than 0
				line(temp_xy[0] + ORIGIN_X, temp_xy[1] + ORIGIN_Y, temp_xy_under[0] + ORIGIN_X, temp_xy_under[1] + ORIGIN_Y, cds, RED);
			else
				line(temp_xy[0] + ORIGIN_X, temp_xy[1] + ORIGIN_Y, temp_xy_under[0] + ORIGIN_X, temp_xy_under[1] + ORIGIN_Y, cds, BLUE);
		}
		a++;
	}
}

map		*init_window(int startpoint, int width, int length, char *windowtitle, char *file)
{
	map		*cds;

	cds = (map*)malloc(sizeof(map));
	cds->file = file;
	X = 0;
	Y = 0;
	ORIGIN_X = 500;
	ORIGIN_Y = 500;
	PAN_ACCEL = 20;
	ZOOM = 20;
	TOTAL = 0;
	PHI[0] = 0;
	PHI[1] = 0;
	PHI[2] = 0;
	MLX = mlx_init();
//	WIN = mlx_new_window(MLX, (width) * ZOOM + startpoint * 2,
//		(length * ZOOM) + startpoint * 2, windowtitle);
	WIN = mlx_new_window(MLX, width, length, windowtitle);
	return (cds);
}

void	render_image(map *cds)
{
	mlx_clear_window(MLX, WIN);
	draw_everything(cds, RED);
}

void	get_cds(map *cds)
{
	int		i;
	int		a;
	int		fd;
	char	*line;
	char	**nbrline;
	int		currentvalue;

	X = 0;
	Y = 0;
	fd = open(cds->file, O_RDONLY);
	i = -1;
	a = 0;
	VALUE = (double **)malloc(sizeof(double *) * TOTAL);
	while(++i < TOTAL)
		VALUE[i] = (double *)malloc(sizeof(double) * 4);
	i = 0;
	while (get_next_line(fd, &line))
	{
		nbrline = ft_strsplit(line, ' ');
		while (nbrline[i])
		{
			currentvalue = ft_atoi(nbrline[i]);
			VALUE[a][0] = X - ((XYVALUE[0] / XYVALUE[1]) * 40);
			VALUE[a][1] = Y - (XYVALUE[1] * 40);
			VALUE[a][2] = currentvalue * 4;
			VALUE[a][3] = currentvalue;
			X += 80;
			i++;
			a++;
		}
		Y += 80;
		X = 0;
		i = 0;
	}
}

void	window_handler(map *cds)
{
	OPTION = -1;
	render_image(cds); //renders the first frame
	mlx_key_hook(WIN, key_event, cds)	// watches for a keypress and renders a new frame.
	mlx_loop(MLX); //loops.
}

void	intro_message(char *mapname)
{
	ft_putstr("\nMap name: ");
	ft_putendl(mapname);
	ft_putendl("\nDirectional keys to pan\n+ and - to Zoom\n");
	ft_putendl("PG UP and PG down to set acceleration");
	ft_putendl("\nPan & Zoom acceleration is medium");
	ft_putendl("\nPress esc to quit");
}

int		main(int argc, char **argv)
{
	map		*cds;

	if (argc != 2)
	{
		ft_putendl("usage: ./fdf source_map");
		return (0);
	}
	intro_message(argv[1]);
	cds = init_window(0, 1000, 1000, argv[1], argv[1]); //initializes the window
	XYVALUE = get_xy(argv[1]); //gets the width and length of the map
	TOTAL = XYVALUE[0]; //sets total to the total amount of points
	get_cds(cds);
	window_handler(cds);
	return (0);
}

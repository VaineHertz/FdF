/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:50:44 by tpadilla          #+#    #+#             */
/*   Updated: 2016/12/08 15:51:34 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define RED 2
#define BLUE 1
#define GREEN 0
#define W_SIZE 600
#include "stdio.h"

int		total;
int		**value;
int		*xyvalue;

int		*get_xy(char *file)
{
	int		*xy;
	int		fd;
	char	*line;
	int		i;
	int		max;

	xy = (int *)malloc(sizeof(int) * 2);
	xy[0] = 0;
	xy[1] = 0;
	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		while (line[i])
		{
			if (line[i] != ' ')
				xy[0]++;
			i++;
		}
		i = 0;
		xy[1]++;
	}
	return (xy);
}

void	draw_line(map *cds, int color)
{
	int		c;
	int		hex;

	c = 0;
	if (color == RED)
		hex = 0x00FF0000;
	else if (color == BLUE)
		hex = 0x000000FF;
	else if (color == GREEN)
		hex = 0x0000FF00;
	while (c <= 2)
	{
		mlx_pixel_put(MLX, WIN, X + c, Y, hex);
		mlx_pixel_put(MLX, WIN, X, Y + c, hex); 
		c++;
	}
}

void	line(int x0, int y0, int x1, int y1, map *cds, int color) {
 
	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
	int err = (dx>dy ? dx : -dy)/2, e2;
	int		c;
	int		hex;
	
	c = 0;
	if (color == RED)
		hex = 0x00FF0000;
	else if (color == BLUE)
		hex = 0x000000FF;
	else if (color == GREEN)
		hex = 0x0000FF00;
  for(;;){
    mlx_pixel_put(MLX, WIN, x0, y0, hex);
    if (x0==x1 && y0==y1) break;
    e2 = err;
    if (e2 >-dx) { err -= dy; x0 += sx; }
    if (e2 < dy) { err += dx; y0 += sy; }
  }
}

void	draw_everything(int **data, map *cds)
{
	int a;
	int width;
	int c;

	a = 0;
	c = 0;
	width = total / xyvalue[1];
	while(data[a])
	{
		if (data[a + 1]) //this if statement handles drawing to the right
		{
			if (data[a][2] > 0 && data[a + 1][2] > 0) //colors red if both points are greater than 0
				line(data[a][0], data[a][1], data[a + 1][0], data[a + 1][1], cds, RED);
			else
				line(data[a][0], data[a][1], data[a + 1][0], data[a + 1][1], cds, BLUE);
		}
		if (data[a + width]) //this if statement checks one under
		{
			if (data[a][2] > 0 && data[a + width][2] > 0) // colors red if both points are greater than 0
				line(data[a][0], data[a][1], data[a + width][0], data[a + width][1], cds, RED);
			else
				line(data[a][0], data[a][1], data[a + width][0], data[a + width][1], cds, BLUE);
		}
		a++;
		if ()
	}
}
	
map		*init_window(int startpoint, int width, int length, char *windowtitle, char *file)
{
	map		*cds;

	cds = (map*)malloc(sizeof(map));
	cds->file = file;
	X = startpoint;
	Y = startpoint;
	ORIGIN_X = startpoint;
	ORIGIN_Y = startpoint;
	PAN_ACCEL = 20;
	ZOOM = 20;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, (width) * ZOOM + startpoint * 2,
		(length * ZOOM) + startpoint * 2, windowtitle);
	return (cds);
}

void	render_image(map *cds)
{
	int		i;
	int		a;
	int		b;
	int		fd;
	char	*line;
	char	**nbrline;
	int		max;
	int		currentvalue;
	int		*random[total];
	mlx_clear_window(MLX, WIN);
	X = ORIGIN_X;
	Y = ORIGIN_Y;
	max = 0;
	fd = open(cds->file, O_RDONLY);
	i = 0;
	a = 0;
	b = 0;

	while(i < total)
	{
		random[i] = (int *)malloc(3 * sizeof(int));
		i++;
	}
	i = 0;
	while (get_next_line(fd, &line))
	{
		nbrline = ft_strsplit(line, ' ');
		while (nbrline[i])
		{
			currentvalue = ft_atoi(nbrline[i]);
			random[a][b] = X;
			b++;
			random[a][b] = Y;
			b++;
			random[a][b] = currentvalue;
			b = 0;
			//if (currentvalue > 0)
			//	draw_line(cds, GREEN);
			//else if (currentvalue == 0)
			//	draw_line(cds, BLUE);
			X += ZOOM;
			i++;
			a++;
		}
		Y += ZOOM;
		X = ORIGIN_X;
		i = 0;
	}
	VALUE = random;
	//print_array(VALUE);
	draw_everything(random, cds);
	//printf("a:%d\n", VALUE[0][0]);
	//printf("b:%d\n", VALUE[0][1]);
	//printf("c:%d\n", VALUE[0][2]);
}

void	key_message(int keycode, map *cds)
{
	if (keycode == 116 || keycode == 121)
	{
		if (PAN_ACCEL == 40)
			ft_putendl("\nPan & Zoom acceleration is fast");
		else if (PAN_ACCEL == 20)
			ft_putendl("\nPan & Zoom acceleration is medium");
		else if (PAN_ACCEL == 5)
			ft_putendl("\nPan & Zoom acceleration is slow");
	}
}

int		key_event(int keycode, map *cds)
{
	if (keycode == 121)
	{
		if (PAN_ACCEL == 20)
			PAN_ACCEL = 5;
		else if (PAN_ACCEL == 40)
			PAN_ACCEL = 20;
		else
			keycode = -1;
	}
	else if (keycode == 116)
	{
		if (PAN_ACCEL == 5)
			PAN_ACCEL = 20;
		else if (PAN_ACCEL == 20)
			PAN_ACCEL = 40;
		else
			keycode = -1;
	}
	else if (keycode == 69)
		ZOOM += PAN_ACCEL / 2;
	else if (keycode == 78 && ZOOM > 1)
		ZOOM -= PAN_ACCEL / 2;
	else if (keycode == 123)
		ORIGIN_X -= PAN_ACCEL;
	else if (keycode == 124 && ORIGIN_X + PAN_ACCEL < W_SIZE)
		ORIGIN_X += PAN_ACCEL;
	else if (keycode == 125 && ORIGIN_Y + PAN_ACCEL < W_SIZE)
		ORIGIN_Y += PAN_ACCEL;
	else if (keycode == 126)
		ORIGIN_Y -= PAN_ACCEL;
	else if (keycode == 53)
		exit(0);
	else if (keycode == 1)
		ft_putendl("i did a thing");
	key_message(keycode, cds);
	render_image(cds);
	return (0);
}

void	window_handler(char	*file)
{
	map		*cds;

	xyvalue = get_xy(file);
	total = xyvalue[0];
	VALUE[total][3];
	cds = init_window(30, xyvalue[0] / xyvalue[1], xyvalue[1], file, file);
	render_image(cds);
	mlx_key_hook(WIN, key_event, cds);
	//mlx_mouse_hook(WIN, key_event, cds);
	mlx_loop(MLX);
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
	if (argc != 2)
	{
		ft_putendl("usage: ./fdf source_map");
		return (0);
	}
	intro_message(argv[1]);
	window_handler(argv[1]);
	return (0);
}

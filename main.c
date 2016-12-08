/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:50:44 by tpadilla          #+#    #+#             */
/*   Updated: 2016/12/04 19:04:20 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define RED 2
#define BLUE 1
#define GREEN 0
#define W_SIZE 600

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
	while (c <= ZOOM) // 2)
	{
		//mlx_pixel_put(MLX, WIN, X - c, Y, hex);
		//mlx_pixel_put(MLX, WIN, X, Y - c, hex);
		mlx_pixel_put(MLX, WIN, X + c, Y, hex);
		mlx_pixel_put(MLX, WIN, X, Y + c, hex);
		c++;
	}
}

int		*get_xy(map *cds)
{
	int 	*xy;
	int		fd;
	char	*line;
	int		i;
	int		max;

	xy = (int *)malloc(sizeof(int) * 2);
	xy[0] = 0;
	xy[1] = 0;
	i = 0;
	max = 0;
	ft_putendl("TEST");
	fd = open(cds->file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		ft_putendl("TEST");
		ft_putendl(line);
		while (line[i])
		{
			if (line[i] != ' ')
				xy[0]++;
			if (max < xy[0])
				max = xy[0];
			i++;
		}
		i = 0;
		xy[1]++;
	}
	return (xy);
}	
/*
void	closer(int max, map *cds)
{
	int x;
	int y;
	int c;

	c = 0;
	x = ORIGIN_X;
	y = ORIGIN_Y;
	while (y < ORIGIN_Y + max)
	{
		x = ORIGIN_X;
		while(x < ORIGIN_X + max)
		{
			while (c < ZOOM / 2)
			{
				if (x + c < ORIGIN_X + max)
					mlx_pixel_put(MLX, WIN, x + c, y, 0x88FFFFFF);
				if (y + c < ORIGIN_Y + max)
					mlx_pixel_put(MLX, WIN, x, y + c, 0x88FFFFFF);
				if (x - c > ORIGIN_X)
					mlx_pixel_put(MLX, WIN, x - c, y, 0x88FFFFFF);
				if (y - c > ORIGIN_Y)
					mlx_pixel_put(MLX, WIN, x, y - c, 0x88FFFFFF);
				c++;
			}
			c = 0;
			x += ZOOM;
		}
		y += ZOOM;
	}
}
*/
/*
int		cd_counter(char *line)
{
	int	i;
	int c;

	i = 0;
	c = 0;
	while (line[i])
	{
		i++;
		c++;
	}
	return (c);
}
*/
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
	WIN = mlx_new_window(MLX, width, length, windowtitle);
	return (cds);
}

void	render_image(map *cds)
{
	int		i;
	int		fd;
	char	*line;
	char	**nbrline;
	int		max;
	int		currentvalue;
	int		nextvalue;

	mlx_clear_window(MLX, WIN);
	X = ORIGIN_X;
	Y = ORIGIN_Y;
	max = 0;
	fd = open(cds->file, O_RDONLY);
	i = 0;
	nextvalue = 0;
	while (get_next_line(fd, &line))
	{
		nbrline = ft_strsplit(line, ' ');
		ft_putendl(line);
		while (nbrline[i])
		{
			currentvalue = ft_atoi(nbrline[i]);
			if (nbrline[i + 1])
				nextvalue = ft_atoi(nbrline[i + 1]);	
			if (currentvalue > 0 && nextvalue > 0)
				draw_line(cds, GREEN);
			else if (currentvalue == 0)	
				draw_line(cds, BLUE);
			X += ZOOM;
			i++;
			//x++;
			//if (max < x)
			//	max = x;
		}
		Y += ZOOM;
		X = ORIGIN_X;
		i = 0;
	//	y++;
	}
	//ft_putnbr(max/y);
	//ft_putchar('\n');
	//ft_putnbr(y);
	//	X = max;
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
	int *xy;
	map		*cds;
	xy = get_xy(cds);
	ft_putnbr(xy[0]);
	ft_putnbr(xy[1]);
	cds = init_window(30, 50, 50, file, file);
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
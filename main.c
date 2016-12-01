/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:50:44 by tpadilla          #+#    #+#             */
/*   Updated: 2016/11/30 21:24:13 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function for storing coordinates for printing
**
 map		*map_parser(char *line)
{
	map		*cds;
	int		i;

	i = 0;
	cds = (map*)malloc(sizeof(map));
	while (line[i])
	{
		if (line[i])
	}
	return (cds)
} */

void	white_line(map	*cds)
{
	int	c;

	c = 0;
	while (c < 50)
	{
		mlx_pixel_put(MLX, WIN, X + c, Y, 0x88FFFFFF);
		c++;
	}
	c = 0;
	while (c < 50)
	{
		mlx_pixel_put(MLX, WIN, X, Y + c, 0x88FFFFFF);
		c++;
	}
}

void	green_line(map	*cds)
{
	int	c;

	c = 0;
	while (c < 50)
	{
		mlx_pixel_put(MLX, WIN, X + c, Y, 0x0000FF00);
		c++;
	}
	c = 0;
	while (c < 50)
	{
		mlx_pixel_put(MLX, WIN, X, Y + c, 0x0000FF00);
		c++;
	}
}

void	closer(map *cds)
{
	int x2;
	int y2;

	x2 = 50;
	while (x2 < X)
	{
		mlx_pixel_put(MLX, WIN, x2, Y, 0x88FFFFFF);
		x2++;
	}
	y2 = 50;
	while (y2 < Y)
	{
		mlx_pixel_put(MLX, WIN, X, y2, 0x88FFFFFF);
		y2++;
	}
}

void	window_handler(char	*file)
{
	map		*cds;
	int		i;
	int		fd;
	char	*line;
	int		max;

	fd = open(file, O_RDONLY);
	i = 0;
	cds = (map*)malloc(sizeof(map));
	X = 50;
	Y = 50;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, 1300, 1300, "FUCKING SHIT");
	get_next_line(fd, &line);
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		if (line[i] == '0')
		{
			if (line[i - 1] != '1')
			{
				white_line(cds);
				X += 50;
			}
			i++;
		}
		if (line[i] == '1')
		{
			green_line(cds);
			mlx_pixel_put(MLX, WIN, X, Y, 0x0000FF00);
			i++;
			X += 50;
		
		}
		if (line[i] != '1' && line[i] != '0' && line[i] != ' ')
		{
			Y += 50;
			max = X;
			X = 50;
			get_next_line(fd, &line);
			i = 0;
		}
	}
	X = max;
	closer(cds);
	mlx_loop(MLX);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("usage: ./fdf source_map");
		return (0);
	}
	window_handler(argv[1]);
	return (0);
}

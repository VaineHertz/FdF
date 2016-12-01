/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:17 by reasaw            #+#    #+#             */
/*   Updated: 2016/11/30 21:03:58 by reasaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void white_line(map *cds, int dir)
{
	int c;

	c = 0;
	if (dir == 0)
	{
		while (c < 10)
		{
			mlx_pixel_put(MLX, WIN, X + c, Y, 0x88FFFFFF);
			c++;
		}
	}
	else
	{
		while (c < 10)
		{
			mlx_pixel_put(MLX, WIN, X, Y + c, 0x88FFFFFF);
			c++;
		}
	}
}

void green_line(map *cds, int dir)
{
	int c;

	c = 0;
	if (dir == 0)
	{
		while (c < 10)
		{
			mlx_pixel_put(MLX, WIN, X + c, Y, 0x8800FF00);
			c++;
		}
	}
	else
	{
		while (c < 10)
		{
			mlx_pixel_put(MLX, WIN, X, Y + c, 0x8800FF00);
			c++;
		}
	}
}


void	window_handler(char	*file)
{
	map		*cds;
	int		i;
	int		fd;
	char	*line;
	int 	max;

	fd = open(file, O_RDONLY);
	i = 0;
	cds = (map*)malloc(sizeof(map));
	X = 100;
	Y = 100;
	max = 0;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, 800, 800, "FUCKING SHIT");
	get_next_line(fd, &line);
	while (line[i])
	{
		if (line[i] == ' ')
		{
			i++;
		}
		if (line[i] == '0')
		{
			if (line[i - 1] != '1')
			{
				white_line(cds, 0);
				white_line(cds, 1);
				X += 10;
			}
			i++;
		}
		if (line[i] == '1')
		{
			green_line(cds, 0);
			green_line(cds, 1);
			mlx_pixel_put(MLX, WIN, X, Y, 0x0055FF55);
			i++;
			X += 10;
		
		}
		if (line[i] != '1' && line[i] != '0' && line[i] != ' ')
		{
			white_line(cds, 1);
			max = X;
			Y += 10;
			X = 100;
			white_line(cds, 0);
			get_next_line(fd, &line);
			white_line(cds, 0);
			i = 0;
		}
	}
	while(X < max)
	{
		mlx_pixel_put(MLX, WIN, X++, Y, 0x88FFFFFF);
	}

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

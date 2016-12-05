/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   othermain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:45:40 by reasaw            #+#    #+#             */
/*   Updated: 2016/12/01 16:24:39 by reasaw           ###   ########.fr       */
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
			mlx_pixel_put(MLX, WIN, X + c, Y, 0xFFFFFFFF);
			c++;
		}
	}
	else
	{
		while (c < 10)
		{
			mlx_pixel_put(MLX, WIN, X, Y + c, 0xFFFFFFFF);
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
			mlx_pixel_put(MLX, WIN, X + c, Y, 0x0000FF00);
			c++;
		}
	}
	else
	{
		while (c < 10)
		{
			mlx_pixel_put(MLX, WIN, X, Y + c, 0x0000FF00);
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
	char 	**holder;

	fd = open(file, O_RDONLY);
	i = 0;
	cds = (map*)malloc(sizeof(map));
	X = 100;
	Y = 100;
	max = 0;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, 800, 800, "ice ice baby");

	 holder = ft_strsplit(file, ' ');
	 while(holder[i])
	 {
		 if (ft_atoi(holder[i]) == 0)
		 {
			 white_line(cds, 0);
			 white_line(cds, 1);
			 i++;
		 }
		 else if (ft_strcmp(holder[i], "\n"))
		 {
			 max = X;
			 Y += 10;
			 X = 100;
			 white_line(cds, 0);
			 white_line(cds, 0);
			 i++;
		 }
		 else
		 {
			 green_line(cds, 0);
			 green_line(cds, 1);
			 mlx_pixel_put(MLX, WIN, X, Y, 0x0055FF55);
			 i++;
			 X+= 10;
		 }
	 }
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 03:49:23 by tpadilla          #+#    #+#             */
/*   Updated: 2017/01/11 05:40:53 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(int message)
{
	if (message == 0)
		ft_putendl("error: invalid map (file not accessible)");
	else if (message == 1)
		ft_putendl("error: invalid map (file is empty)");
	exit(0);
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
	if ((fd = open(file, O_RDONLY)) < 0)
		error(0);
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

void	assign_cds(t_fdf *master, char **nbrline, int *a)
{
	int		i;

	i = 0;
	while (nbrline[i])
	{
		VALUE[*a][3] = ft_atoi(nbrline[i]);
		if (VALUE[*a][3] > master->cds->max_height)
			master->cds->max_height = VALUE[*a][3];
		VALUE[*a][2] = VALUE[*a][3] * 60;
		VALUE[*a][0] = X - (WIDTH * 40);
		VALUE[*a][1] = Y - (YVALUE * 40);
		X += 80;
		i++;
		(*a)++;
	}
	Y += 80;
	X = 0;
}

void	get_cds(t_fdf *master)
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
	VALUE = (double **)malloc(sizeof(double *) * TOTAL);
	while (++i < TOTAL)
		VALUE[i] = (double *)malloc(sizeof(double) * 4);
	i = 0;
	while (get_next_line(fd, &line))
	{
		nbrline = ft_strsplit(line, ' ');
		assign_cds(master, nbrline, &i);
	}
}

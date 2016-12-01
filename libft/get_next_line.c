/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasaw   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:07:47 by reasaw            #+#    #+#             */
/*   Updated: 2016/11/19 19:30:23 by reasaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

size_t	end_of_line(char *str)
{
	int		index;

	index = -1;
	if (!str)
		return (0);
	while (str[++index] != '\0')
	{
		if (str[index] == '\n')
			return (index + 1);
	}
	return (0);
}


int		read_fd(int fd, char *buff)
{
	int		r;

	if ((r = read(fd, buff, BUFF_SIZE)) != -1)
		buff[r] = '\0';
	return (r);
}


t_fd	*get_fd(t_fd *lst_fd, int fd)
{
	t_fd	*l_tmp;

	l_tmp = lst_fd;
	if (l_tmp)
	{
		while (l_tmp->next)
		{
			if (l_tmp->fd == fd)
				return (l_tmp);
			l_tmp = l_tmp->next;
		}
		if (l_tmp->fd == fd)
			return (l_tmp);
		if (!(l_tmp->next = (t_fd *)malloc(sizeof(t_fd))))
			return (NULL);
		l_tmp = l_tmp->next;
	}
	else if (!(l_tmp = (t_fd *)malloc(sizeof(t_fd))))
		return (NULL);
	l_tmp->fd = fd;
	l_tmp->t_line = ft_strdup("");
	l_tmp->next = NULL;
	l_tmp->sort = (!lst_fd) ? l_tmp : lst_fd;
	return (l_tmp);
}

char	*join_del(char *s1, char *s2, int n)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (s1 && (n == 3 || n == 2))
		ft_memdel((void **)&s1);
	if (s2 && (n == 3 || n == 1))
		ft_memdel((void **)&s2);
	return (tmp);
}

int		get_next_line(int const fd, char **line)
{
	static t_fd		*tmp_fd = NULL;
	char			buff[BUFF_SIZE + 1];
	char			*str;
	int				l;
	int				r;

	r = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	tmp_fd = get_fd(tmp_fd, fd);
	while (fd >= 0 && ((l = end_of_line(tmp_fd->t_line)) ||
				(r = read_fd(fd, buff)) > 0) && l <= 0)
		tmp_fd->t_line = join_del(tmp_fd->t_line, buff, 2);
	if (r == -1)
		return (-1);
	if (l > 0)
		tmp_fd->t_line[l - 1] = '\0';
	*line = ft_strdup(tmp_fd->t_line);
	str = tmp_fd->t_line;
	tmp_fd->t_line = ((l > 0) ? ft_strdup(tmp_fd->t_line + l) : ft_strdup(""));
	free(str);
	tmp_fd = tmp_fd->sort;
	return ((l || **line) ? 1 : 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:07:47 by tpadilla          #+#    #+#             */
/*   Updated: 2016/11/19 19:30:23 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

/*
** read_fd simply reads BUFF_SIZE bytes from the file and stores
** it into buff which is joined onto our struct to form the next line.
*/

int		read_fd(int fd, char *buff)
{
	int		r;

	if ((r = read(fd, buff, BUFF_SIZE)) != -1)
		buff[r] = '\0';
	return (r);
}

/*
** If our static struct is already instanced and exists we cycle through
** nodes of our struct looking to see if we have already stored our
** particular file in a node.
** If we haven't then we create a new node and allocate for it.
** Since we haven't hit a return
** (They happen when we find our file in a node)
** we'll reach the bottom of the function where we assign values to the node
** and allocate for our string. We set sort to the address of the first node
** so when we are
** done we can set it to sort. So next time we call it. We'll be able to
** traverse the whole list.
*/

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

/*
** We store the whole of our "got" next line in one node which
** is appropiate to the file. We do this with join_del in a while loop
** the loop breaks when there's nothing left to read or the end of line
** is detected with end_of_line. s1 is what is already stored in the node
** and s2 is the buffer which just read BUFF_SIZE bytes from the file.
*/

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

/*
** tmp_fd is our static struct used to track our progress for multiple
** file descriptors We pass it to get_fd to find the appropiate node in
** the list that contains the fd passed.
** If it doesn't exist it is made.
** After looping through the file, reading it, and joining those strings
** from the buffer, we set the newline character to '\0' and modify the
** string passed to equal the "got" line we then set the string in our
** struct to be indexed past the line we just "got" by being 1 byte
** past the newline. Otherwise we set it to nothing.
** We free what our t_line used to be.
*/

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

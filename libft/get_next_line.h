/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:07:54 by tpadilla          #+#    #+#             */
/*   Updated: 2016/12/16 07:01:25 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

int					get_next_line(const int fd, char **line);

typedef	struct		s_fd
{
	int				fd;
	char			*t_line;
	struct s_fd		*next;
	struct s_fd		*sort;
}					t_fd;

#endif

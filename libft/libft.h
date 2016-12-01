/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 14:32:48 by reasaw            #+#    #+#             */
/*   Updated: 2016/09/23 14:32:57 by reasaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line.h"

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_putchar(char c);
void			ft_putnbr(int n);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putnbr_fd(int n, int fd);
char			*ft_itoa(int n);
char			**ft_strsplit(char const *s, char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(char const *s);
void			*ft_memset(void *str, int c, size_t len);
void			ft_bzero(void *str, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t len);
void			*ft_memccpy(void *dst, const void *src, int c, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *str, int c, size_t len);
int				ft_memcmp(const void *str1, const void *str2, size_t len);
void			*ft_memalloc(size_t size);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
void			ft_memdel(void **ap);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
char			*ft_strcat(char *dest, char *src);
char			*ft_strncat(char *dest, char *src, int nb);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(char *str, int c);
char			*ft_strstr(char *str, char *to_find);
char			*ft_strnstr(char *str, char *to_find, unsigned int n);
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
int				ft_atoi(char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				get_next_line(int const fd, char **line);
#endif

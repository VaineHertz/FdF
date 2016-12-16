# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/26 12:53:00 by tpadilla          #+#    #+#              #
#    Updated: 2016/11/08 21:49:40 by tpadilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILENAMES += ft_putchar.c ft_putstr.c ft_strcpy.c ft_strdup.c ft_strlen.c\
			 ft_strncpy.c ft_strnew.c ft_strstr.c ft_atoi.c ft_memset.c\
			 ft_bzero.c ft_memalloc.c ft_memdel.c ft_strdel.c ft_strclr.c\
			 ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
			 ft_isprint.c ft_toupper.c ft_tolower.c ft_striter.c\
			 ft_striteri.c ft_strcmp.c ft_strncmp.c ft_strnstr.c\
			 ft_memcpy.c ft_strequ.c ft_strnequ.c ft_strchr.c\
			 ft_memccpy.c ft_memmove.c ft_strsplit.c ft_strmap.c\
			 ft_putendl.c ft_strmapi.c ft_strsub.c ft_strjoin.c\
			 ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
			 ft_putnbr_fd.c ft_memchr.c ft_memcmp.c ft_strcat.c\
			 ft_strncat.c ft_strlcat.c ft_strrchr.c ft_intlen.c\
			 ft_itoa.c ft_strtrim.c ft_lstnew.c ft_lstdelone.c\
			 ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c\
			 ft_isupper.c ft_islower.c ft_isspace.c ft_swap.c\
			 ft_lstadd_end.c ft_flip_list.c ft_put2str.c\
			 get_next_line.c

NAME = libft.a
HEADER = ./includes/
CC = gcc
CFLAGS += -Wall -Wextra -Werror
OPTION = -c -I $(HEADER)
SRCS	= $(FILENAMES)
OBJS	= $(FILENAMES:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(OPTION) $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)

re: fclean all

NAME = fdf
SRC = main.c
OBJ = $(SRC:.c=.o)
MLX = minilibx_macos/libmlx.a
LIBFT = libft/libft.a
FRAMEWORKS = -framework OpenGL -framework AppKit
all: $(NAME)

$(NAME): $(OBJ)
	make -C minilibx_macos/
	make -C libft/
	gcc -o $(NAME) $(OBJ) $(MLX) $(LIBFT) $(FRAMEWORKS)

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C minilibx_macos/ clean

cc: $(OBJ)
	gcc -o $(NAME) $(OBJ) $(MLX) $(LIBFT) $(FRAMEWORKS)
	rm -f $(OBJ)

re: clean all
	make -C minilibx_macos/ re
	make -C libft/ re

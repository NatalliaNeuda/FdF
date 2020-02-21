NAME = fdf

FRAEMWORKS = -framework OpenGL -framework AppKit
FLAGS = -Werror -Wextra -Wall
SOURCES=./*.c
LIBRARIES=libft/libft.a minilibx_macos/libmlx.a

all:
	@make -C libft/ all
	@make -C minilibx_macos/
	gcc $(SOURCES) -o $(NAME) $(LIBRARIES) $(FLAGS) $(FRAEMWORKS)

run42:
	./fdf maps/42.fdf

clean:
	@make -C libft/ clean
	@make -C minilibx_macos/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
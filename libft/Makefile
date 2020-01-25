NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRC = *.c
OBJ = *.o
HEADERS = -I libft.h

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(HEADERS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all


	
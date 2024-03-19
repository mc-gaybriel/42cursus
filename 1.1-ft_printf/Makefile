NAME	= libftprintf.a

SRC		= ./src/ft_printf.c ./libft/Makefile

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
OBJ		= $(SRC:.c=.o)

.PHONY: all clean fclean re

all: libft $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

libft:
    @$(MAKE) -C libft -f Makefile

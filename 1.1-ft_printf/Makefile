NAME		=	libftprintf.a

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
AR			=	ar
ARFLAGS		=	rcs
RM			=	rm -rf

SRCS		=	$(wildcard ./src/*.c)

OBJ_DIR		=	obj
OBJS		=	$(SRC:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a

.PHONY: all clean fclean re

all:			$(NAME)

$(OBJ_DIR)/%.o:	%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(LIBFT) $(OBJ_DIR) $(OBJS)
			cp	$(LIBFT) $(NAME)
				$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT):
				make -C $(LIBFT_PATH) all

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

clean:
				make -C $(LIBFT_PATH) clean
				$(RM) $(OBJ_DIR)

fclean:		clean
				make -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)

re:			fclean all
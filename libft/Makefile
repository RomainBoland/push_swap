NAME = libft.a

SRC_LIBFT = src/libft/*.c
SRC_PRINTF = src/ft_printf/*.c
SRC_GNL = src/get_next_line/*.c
SRC = $(SRC_LIBFT) $(SRC_PRINTF) $(SRC_GNL)

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
#- Makefile -#

NAME=push_swap

CC=cc
CFLAGS= -Wall -Wextra -Werror

# Source files
SRC:=$(wildcard *.c) $(wildcard */*.c)

# Object files
OBJ:=$(SRC:.c=.o)

#Rules

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all

.PHONY: all clean fclean re



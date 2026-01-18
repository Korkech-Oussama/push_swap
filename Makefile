#- Makefile -#

NAME=push_swap
NAME_BONUS = checker

CC=cc
CFLAGS= -Wall -Wextra -Werror

# Source files
ALL_FILES = $(wildcard *.c) $(wildcard */*.c)
SRC = $(filter-out checker_src/%, $(ALL_FILES))
# bonus src
BONUS_SRC = $(wildcard checker_src/*.c) $(wildcard checker_src/*/*.c)

# Object files
OBJ:=$(SRC:.c=.o)  
#object bonus
OBJ_BONUS = $(BONUS_SRC:.c=.o)

#Rules

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean:clean
	rm -f $(NAME) $(NAME_BONUS)

re:fclean all

.PHONY: all clean fclean re bonus

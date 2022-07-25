SRC = main.c ft_realloc.c lexer/lexer.c lexer/token.c utils/istext.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

NAME = minishell

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -lreadline $(OBJ) -o $(NAME)

all : $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all


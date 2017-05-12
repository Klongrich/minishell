NAME = minishell
OBJ = main.o get_next_line.o run_builtins.o parse_input.o manage_env.o run_cd.o
INC = inc/minishell.h
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
LIBH = libft/libft.h

all: $(NAME)

%.o: $(addprefix ./src/,%.c)
	@gcc $(CFLAGS) $(INC) -c $< $(LIBH)

$(NAME): $(OBJ)
	@gcc -g $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all

#ifndef MINISHELL_H
# define MINISHELL_H
# include "get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <sys/stat.h>
# include <dirent.h>

void	run_builtin(char *str, char *command);
void	run_cd(char *input);
void	run_unsetenv(char *input);
void	run_setenv(char *input);
void	print_env();
void	init_env(char **input);
int		parse_input(char *input);

#endif
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

void	run_cd(char *input);
void	run_unsetenv(char *input);
void	run_setenv(char *input);
void	print_env();
void	init_env(char **input);
void	run_echo(char *input);
void	run_ls(char *input);
void	run_pwd();
int		parse_input(char *input);
int		ft_env_len(char **str);
void	run_setenv(char *input);
int		check_name(char *user_input, int delete_or_update);
#endif
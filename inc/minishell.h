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

void	run_fork(char *str, char *command);
void	parse_input(char *input);

#endif
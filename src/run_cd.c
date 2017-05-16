#include "../inc/minishell.h"

int		update_pwd(char *path)
{
	path = NULL;
	return (1);
}

int		check_path(char *path)
{
	if (opendir(path))
		return (update_pwd(path));
	else
		return (0);
}

void	run_cd(char *input)
{
	char **parsed_input;
	parsed_input = ft_strsplit(input, ' ');

	if (check_path(parsed_input[1]))
		chdir(parsed_input[1]);
	else
		printf("cd: no such file or directory: %s\n", parsed_input[1]);
}
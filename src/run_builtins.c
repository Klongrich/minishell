#include "../inc/minishell.h"

/*
void	run_echo(char **input)
{	

}

void	run_pwd(char **input)
{

}

void	run_ls(char **input)
{

}

char	**parse_user_input(char *str)
{

	return (0);
}
*/

void run_builtin(char *input, char *command)
{
	pid_t pid;
	char **user_input;
	char *bin_path;

	input = NULL;
	bin_path = ft_strjoin("/bin/", command);
	//Use ft_strsplit to parse input

	user_input = (char **)malloc(sizeof(user_input) * 4);
	user_input[0] = command;
	user_input[1] = NULL;
	pid = fork();

	if (pid > 0)
		wait(0);
	else if (!pid)
	{
		execv(bin_path, user_input);
	}
	//printf("Fork: %d\n", pid);
}
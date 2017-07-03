#include "../inc/minishell.h"


void run_builtin(char **user_input, char *bin_path)
{
	pid_t pid;

	pid = fork();
	if (pid > 0)
		wait(0);
	else if (!pid)
		execv(bin_path, user_input);
	free(user_input);
}


char	*trim_string(char *str)
{
	char *answer;
	int i;
	int j;

	i = 0;
	j = 0;
	answer = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		if (str[i] != '"')
		{
			answer[j] = str[i];
			j++;
		}
		i++;
	}
	answer[j] = '\0';
	return (answer);
}

void	check_env(char *str)
{
	int	i;
	char	**names;

	i = 0;
	str++;
	while (env[i])
	{
		names = ft_strsplit(env[i], '=');
		if (!ft_strcmp(str, names[0]))
			ft_putstr(names[1]);
		i++;
		free (names);
	}
	ft_putchar('\n');
}


int		run_echo(char *input)
{
	char **user_input;
	//char *tmp;
	int i;
	int j;

	//printf("INPUT: %s\n", input);
	i = 0;
	j = 0;
	user_input = ft_strsplit(input, ' ');
	while (user_input[i])
	{
		j = 0;
		while (user_input[i][j])
		{
			if (user_input[i][j] == '"')
			{
				user_input[i] = trim_string(user_input[i]);
				break ;
			}
			else if (user_input[i][j] == '$' && user_input[i][j + 1])
			{
				check_env(user_input[i]);
				return (0);
			}
			j++;
		}
		i++;
	}
	user_input[i] = NULL;
	run_builtin(user_input, "/bin/echo");
	return (0);
}

void	run_pwd()
{
	char	**user_input;

	user_input = (char **)malloc(sizeof(char) * 2);
	user_input[0] = "pwd";
	user_input[1] = NULL;
	run_builtin(user_input, "/bin/pwd");

}

void	run_ls(char *input)
{
	run_builtin(ft_strsplit(input, ' '), "/bin/ls");
}

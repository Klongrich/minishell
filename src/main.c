#include "../inc/minishell.h"

void	print_env(char **env)
{
	int i;

	i = 0;
	while(env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}

int		main(int ac, char **av, char **env)
{
	char *line;
	char **cmd;

	if (ac != 1)
		return (0);
	cmd = NULL;
	line = NULL;
	signal(SIGINT, SIG_IGN);

	av = 0;
	/*
	printf("%s\n", *av);
	while (*env++)
	{
		printf("%s\n", *env);
	}
	*/

	while (1)
	{
		write(1, "$> ", 3);
		if (get_next_line(0, &line) > 0)
		{
			parse_input(line);
			if (!ft_strcmp(line, "exit"))
				break ;
			if (!ft_strcmp(line , "env"))
				print_env(env);
		}
		
	}
	return (0);
}

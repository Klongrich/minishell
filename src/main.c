#include "../inc/minishell.h"

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
	env = 0;

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
			if (line[0] == '3')
				break ;
		}
		
	}
	return (0);
}

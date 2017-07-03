#include "../inc/minishell.h"

int		main(int ac, char **av, char **env)
{
	char *line;

	if (ac != 1)
		return (0);
	line = NULL;
	init_env(env);
	av = 0;
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

#include "../inc/minishell.h"

int		is_builtin(char *input)
{
	char str[ft_strlen(input)];
	int i;

	i = 0;
	while (input[i] != ' ' && input[i] != ';' && input[i])
	{
		str[i] = input[i];
		i++;
	}
	str[i] = '\0';
	if (!ft_strcmp(str, "echo"))
		run_fork(input, "echo");
	else if (!ft_strcmp(str, "pwd"))
		run_fork(input, "pwd");
	else if (!ft_strcmp(str, "ls"))
		run_fork(input, "ls");
	return(1);
}

void	run_builtin(char *str)
{
	str = NULL;
	printf("");
}

void	parse_input(char *input)
{
	if (is_builtin(input))
		run_builtin(input);
	else
	{
		printf("wtf");
	}

}
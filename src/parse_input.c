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
		run_echo(input);
	else if (!ft_strcmp(str, "pwd"))
		run_pwd();
	else if (!ft_strcmp(str, "ls"))
		run_ls(input);
	else
		return(0);
	return(1);
}


int		is_other(char *input)
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
	if (!ft_strcmp(str, "cd"))
		run_cd(input);
	else if (!ft_strcmp(str, "setenv"))
		run_setenv(input);
	else if (!ft_strcmp(str, "unsetenv"))
		run_unsetenv(input);
	else
		return(0);
	return(1);

}

int		parse_input(char *input)
{
	if (is_builtin(input))
		return(1);
	else if (is_other(input))
		return(1);
	else
		printf("command not found: %s\n", input);
	return (0);

}
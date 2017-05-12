#include "../inc/minishell.h"

char	**env;

int		ft_len(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	init_env(char **input)
{
	env = input;
}

/*
int		check_name(char *user_input)
{
	char **current_names;
	int i;

	i = 0;
	current_names = ft_strsplit(env, '=');
	while (i < 10)
	{
		if (i % 2 == 0)
			printf("%s\n", current_names[i]);
		i++;
	}
	return (0);
}
*/

void	run_setenv(char *input)
{
	char	**new_env;
	
	int i;

	i = 0;
	new_env = (char **)malloc(sizeof(new_env) * ft_len(env) + 1);
	//if (check_name(input))
	//{
		while (env[i])
		{
			new_env[i] = env[i];
			i++;
		}
		new_env[i] = input;
	//}
	env = new_env;
	printf("setenv: %s\n", input);
}

void	run_unsetenv(char *input)
{
	char	**new_env;
	int i;

	i = 0;
	new_env = (char **)malloc(sizeof(new_env) * ft_len(env) + 1);
	//if (check_name(input))
	//{
		while (env[i])
		{
			if (ft_strcmp(input, env[i]))
				new_env[i] = env[i];
			i++;
		}
		new_env[i] = input;
	//}
	env = new_env;
	printf("setenv: %s\n", input);
	printf("unsetenv: %s\n", input);
}

void	print_env()
{
	int i;

	i = 0;
	while(env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}
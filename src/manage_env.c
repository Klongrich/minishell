#include "../inc/minishell.h"

char	**env;

int		ft_env_len(char **str)
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

int		update_info(char *str, int delete_or_update, int spot, char *user_input)
{
	int i;
	int j;
	char	**new_env;
	char	**env_name;
	char	**tmp;
	char	**tmptwo;

	i = 0;
	j = 0;
	tmp = env;
	new_env = (char **)malloc(sizeof(new_env) * ft_env_len(env) + 1);
	if (delete_or_update)
	{
		printf("spot: %s\ninput: %s\n", env[spot], user_input);
	}
	else
	{
		while (env[i])
		{
			tmptwo = env_name;
			env_name = ft_strsplit(env[i], '=');
			if (ft_strcmp(str, env_name[0]))
			{
				new_env[j] = env[j];
				printf("WORKING");
				j++;
			}
			printf("STR: %s\n ENV_NAME: %s\n", str, env_name[0]);
			i++;
		}
		new_env[j] = NULL;
		env = new_env;
		free (tmp);
	}
	return (0);
}

int		check_name(char *user_input, int delete_or_update)
{
	char **current_names;
	char **varible_name;
	int i;

	i = 0;
	varible_name = ft_strsplit(user_input, ' ');
	if (!varible_name[1])
		return (0);
	while (i < ft_env_len(env))
	{
		current_names = ft_strsplit(env[i], '=');
		if (!ft_strcmp(current_names[0], varible_name[1]))
			return (update_info(current_names[0], delete_or_update, i, user_input));
		i++;
	}
	return (1);
}

void	run_setenv(char *input)
{
	char	**new_env;
	char	**tmp;
	char	*tmptwo;
	int i;

	i = 0;
	new_env = (char **)malloc(sizeof(new_env) * ft_env_len(env) + 2);
	if (check_name(input, 1))
	{
		while (env[i])
		{
			new_env[i] = env[i];
			i++;
		}
		tmp = ft_strsplit(input, ' ');
		tmptwo = ft_strjoin(tmp[1], "=");
		new_env[i++] = ft_strjoin(tmptwo, tmp[2]);
		new_env[i] = NULL;
		env = new_env;
		free (tmp);
		free (tmptwo);
	}
}

void	run_unsetenv(char *input)
{
	check_name(input, 0);
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
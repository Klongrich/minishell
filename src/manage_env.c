#include "../inc/minishell.h"

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

void	update_env(char *user_input, int spot)
{
	char	**parsed_data;
	char	*tmp;
	char	*dup;

	parsed_data = ft_strsplit(user_input, ' ');
	dup = ft_strjoin(parsed_data[1], "=");
	tmp = ft_strjoin(dup, parsed_data[2]);
	env[spot] = tmp;
	free (parsed_data);
	free (dup);
}

void	delete_env(char *str)
{
	int i;
	int j;
	char	**new_env;
	char	**env_name;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = env;
	new_env = (char **)malloc(sizeof(new_env) * ft_env_len(env) + 1);
	while (env[i])
	{
		env_name = ft_strsplit(env[i], '=');
		if (ft_strcmp(str, env_name[0]))
		{
			new_env[j] = env[i];
			j++;
		}
		i++;
	}
	new_env[j] = NULL;
	env = new_env;
	free (tmp);
	free (env_name);
}


int		update_info(char *str, int delete_or_update, int spot, char *user_input)
{
	if (delete_or_update)
		update_env(user_input, spot);
	else
		delete_env(str);	
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

void    check_env(char *str) {
	int     i;
        char    **names;
  
	i = 0;
        str++;
        while (env[i]) {
		names = ft_strsplit(env[i], '=');
                if (!ft_strcmp(str, names[0]))
                        ft_putstr(names[1]);
                i++;
                free (names);
        }
        ft_putchar('\n');
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

int     check_for_path(char *str) {
          if ((str[0] == 'P' &&
               str[1] == 'A' &&
               str[2] == 'T' &&
               str[3] == 'H' &&
               str[4] == '=')) {
               return (1);
        }
         return (0);
}

char	*check_env_path(char *command) {
	int i;
	int j;
	char **temp;
	char *temp2;
	char *temp3;
	char **temp4;

	i = 0;
	j = 0;
	while (env[i]) {
		if (check_for_path(env[i])) {
			temp = ft_strsplit(env[i], ':');
			temp4 = ft_strsplit(temp[0], '=');
			temp[0] = temp4[1];
			while (temp[j]) {
				temp2 = ft_strjoin(temp[j], "/");
				temp3 = ft_strjoin(temp2, command);
				if(!access(temp3, X_OK)) {
					free(temp[j]);
					free(temp2);
					return (temp3);
				}
				free(temp[j]);
				free(temp2);
				free(temp3);
				j++;
			}
			break;		
		}
		i++;
	}
	return (NULL);
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

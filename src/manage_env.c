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
	char	**env_name;
	char	*temp;

	i = 0;
	j = 0;
	while (env[i])
	{
		temp = env[i];
		env_name = ft_strsplit(env[i], '=');
		if (ft_strcmp(str, env_name[0]))
		{
			env[j] = temp;
			j++;
		}
		i++;
	}
	env[j] = NULL;
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

char	*get_env(char *str) {
	int i;
	char **names;
	char *res;

	i = 0;
	str++;
	res = "no_env_found";
	while (env[i]) {
		names = ft_strsplit(env[i], '=');
		if (!ft_strcmp(str, names[0])) {
			res = names[1];
			break ;
		}
		i++;
		free(names);
	}
	return (res);
}


void	run_setenv(char *input)
{
	char	**new_env;
	char	**tmp;
	char	*tmptwo;
	char	*temp3;
	int i;

	i = 0;
	new_env = (char **)malloc(sizeof(new_env) * ft_env_len(env) + 2);
	if (check_name(input, 1))
	{
		while (env[i])
			i++;
		tmp = ft_strsplit(input, ' ');
		tmptwo = ft_strjoin(tmp[1], "=");
		temp3  = ft_strjoin(tmptwo, tmp[2]);
		env[i] = temp3;
		env[i + 1] = NULL;
		free (tmp);
		free (tmptwo);
	}
}

void	run_unsetenv(char *input)
{
	check_name(input, 0);
}

int     is_PATH(char *str) {
          if ((str[0] == 'P' &&
               str[1] == 'A' &&
               str[2] == 'T' &&
               str[3] == 'H' &&
               str[4] == '=')) {
               return (1);
        }
         return (0);
}


int	is_home(char *str) {
	if((str[0] == 'H' 
	&& str[1] == 'O' 
	&& str[2] == 'M' 
	&& str[3] == 'E'
	&& str[4] == '=')) {
		return (1);
	} else {
		return (0);
	}
}

char	*get_env_home() {
	int i;

	i = 0;

	while (env[i]) {
		if(is_home(env[i])) {
			return(env[i]);
		}
		i++;
	}
	return(NULL);
}

char	*check_and_create_bin_path(char *PATH, char *command) {
	int j;
        char **paths_parsed;
        char *parsed_path_appened;
        char *full_path_with_command;
        char **cut_PATH_from_path;

	j = 0;
	paths_parsed = ft_strsplit(PATH, ':');
        cut_PATH_from_path = ft_strsplit(paths_parsed[0], '=');
        paths_parsed[0] = cut_PATH_from_path[1];
        while (paths_parsed[j]) {
		parsed_path_appened = ft_strjoin(paths_parsed[j], "/");
              	full_path_with_command = ft_strjoin(parsed_path_appened, command);
		if(!access(full_path_with_command, X_OK)) {
			free(paths_parsed[j]);
                        free(parsed_path_appened);
                         return (full_path_with_command);
                }
		free(paths_parsed[j]);
		free(parsed_path_appened);
		free(full_path_with_command);
		j++;
	}
	return(NULL);
}

char	*check_env_path(char *command) {
	int i;

	i = 0;
	while (env[i]) {
		if (is_PATH(env[i])) {
			return (check_and_create_bin_path(env[i], command));
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

#include "../inc/minishell.h"

int		update_pwd(int old_or_new)
{
	char	*answer;
	char	*cwd;
	char	buff[247];

	cwd = getcwd(buff, 247);
	if (!old_or_new)
		answer = ft_strjoin("setenv PWD ", cwd);
	else
		answer = ft_strjoin("setenv OLDPWD ", cwd);
	run_setenv(answer);
	return (1);
}

int		check_path(char *path)
{
	if (opendir(path))
		return (update_pwd(1));
	else
		return (0);
}

int	get_number_of_args(char **parse_input) {
	int i;

	i = 0;
	while (parse_input[i]) {
		i++;
	}
	return (i);
}


char	*create_path(char *home_path, char *user_input) {
	char *res;
	int i;
	int j;

	i = 0;
	j = 0;
	res = (char *)malloc(sizeof(char) * ft_strlen(home_path) + ft_strlen(user_input));
	while (home_path[i]) {
		res[j] = home_path[i];
		j++;
		i++;
	}
	i = 1;
	while (user_input[i]) {
		res[j] = user_input[i];
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}

void	check_path_then_update(char *path) {
	if (check_path(path)) {
		chdir(path);
		update_pwd(0);
	} else {
		printf("cd: no such file or directory: %s\n", path);
	}
}

void	cd_to_HOME() {
	char **home_path;
	
	home_path = ft_strsplit(get_env_home(), '=');
	if(check_path(home_path[1])) {
		chdir(home_path[1]);
		update_pwd(0);
	} else {
		printf("cd: no such file or directory: %s\n", home_path[1]);
	}
	free(home_path);
}

void	run_cd(char *input)
{
	char **parsed_input;
	char	**home_path;
	char	*temp;
	int number_of_args;

	parsed_input = ft_strsplit(input, ' ');
	number_of_args = get_number_of_args(parsed_input);
	if (number_of_args > 2) {
		printf("cd: too many arguments\n");
	} else {
		if (!parsed_input[1]) {
			cd_to_HOME();
		} else if (parsed_input[1][0] == '~') {
			home_path = ft_strsplit(get_env_home(), '=');
			temp = create_path(home_path[1], parsed_input[1]);
			check_path_then_update(temp);
			free(home_path);
			free(temp);
		} else if (parsed_input[1][0] == '$' && parsed_input[1][1]) {
			temp = get_env(parsed_input[1]);
			if (!ft_strcmp(temp, "no_env_found")) {
				cd_to_HOME();
			} else {
				check_path_then_update(temp);
			}
		} 
		else  {
			check_path_then_update(parsed_input[1]);
		}
	}
}

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

void	run_cd(char *input)
{
	char **parsed_input;
	char	**home_path;
	int number_of_args;

	parsed_input = ft_strsplit(input, ' ');
	number_of_args = get_number_of_args(parsed_input);
	if (number_of_args > 2) {
		printf("cd: too many arguments\n");
	} else {
		if (!parsed_input[1]) {
			home_path = ft_strsplit(get_env_home(), '=');
			check_path(home_path[1]);
			chdir(home_path[1]);
			update_pwd(0);
		} else if (check_path(parsed_input[1]))
		{
			chdir(parsed_input[1]);
			update_pwd(0);
		}
		else
			printf("cd: no such file or directory: %s\n", parsed_input[1]);
	}
}

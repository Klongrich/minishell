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

void	run_cd(char *input)
{
	char **parsed_input;
	parsed_input = ft_strsplit(input, ' ');

	if (check_path(parsed_input[1]))
	{
		chdir(parsed_input[1]);
		update_pwd(0);
	}
	else
		printf("cd: no such file or directory: %s\n", parsed_input[1]);
}
#include "../inc/minishell.h"

int	is_builtin(char *input) {
	char str[ft_strlen(input)];
	int i;
	char *bin_path;
	char **user_input;

	i = 0;
	while (input[i] != ' ' && input[i] != ';' && input[i]) {
		str[i] = input[i];
		i++;
	}
	str[i] = '\0';

	bin_path = check_env_path(str);	
	if (bin_path) {
		user_input = ft_strsplit(input, ' ');
		run_builtin(user_input, bin_path);
		free(bin_path);
		return (1);
	} else {
		return (0);
	}		
}


int	is_other(char *input) {
	char str[ft_strlen(input)];
	int i;

	i = 0;
	while (input[i] != ' ' && input[i] != ';' && input[i]) {
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
	else if (!ft_strcmp(str, "echo"))
		run_echo(input);
	else if (!ft_strcmp(str, "exit"))
		return (1);
	else
		return(0);
	return(1);

}

int	parse_input(char *input) {

	if (!input[0]) {	
	} else if (is_other(input))
		return(1);
	else if (is_builtin(input))
		return(1);
	else
		printf("command not found: %s\n", input);
	return (0);
}

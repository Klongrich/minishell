#include "libft.h"

void	sformatdot(char **str, int num, char *arg)
{
	(*str)++;
	(*str)++;
	while (num && *arg)
	{
		ft_putchar(*arg);
		arg++;
		num--;
	}
}

void	dformatstar(char **str, int num, int arg)
{
	int i;

	i = num - ft_numlen(arg);
	(*str)++;
	if (ft_numlen(arg) > num)
		ft_putnbr(arg);
	else
	{
		while (i)
		{
			ft_putchar(' ');
			i--;
		}
		ft_putnbr(arg);
	}
}

void	sformatstar(char **str, int num, char *arg)
{
	int i;

	i = num - ft_strlen(arg);
	(*str)++;
	if (ft_strlen(arg) > num)
		ft_putstr(arg);
	else
	{
		ft_putstr(arg);
		while (i)
		{
			ft_putchar(' ');
			i--;
		}
	}
}

void        skipthree(char *str)
{
   int i;

   i = 3;
   while (str[i])
   {
	   ft_putchar(str[i]);
	   i++;
   }
}

void	ft_printf(char *str, ...)
{
	va_list list;

	va_start(list, str);
	while (*str)
	{
		while (*str != '%' && *str)
		{
			ft_putchar(*str);
			str++;
		}
		if (!*str)
			break ;
		str++;
		if ((*str == '*' && *(str + 1) == 's'))
			sformatstar(&str, va_arg(list, int), va_arg(list, char *));
		else if ((*str == '*' && *(str + 1) == 'd'))
			dformatstar(&str, va_arg(list, int), va_arg(list, int));
		else if (*str == '.')
			sformatdot(&str, va_arg(list, int), va_arg(list, char *));
		else if (*str == 'd')
			ft_putnbr(va_arg(list, int));
		else if (*str == 's')
			ft_putstr(va_arg(list, char*));
        else if (*str == '~')
            skipthree(va_arg(list, char*));
		str++;
	}
}

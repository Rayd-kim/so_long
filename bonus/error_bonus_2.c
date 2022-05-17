#include "so_long_bonus.h"

void	error_stdin(t_param *param)
{
	write (2, "Error\n", 6);
	write (2, strerror(errno), ft_strlen(strerror(errno)));
	free_param(param);
	exit (errno);
}

void	first_error(void)
{
	write (2, "Error\n", 6);
	write (2, strerror(errno), ft_strlen(strerror(errno)));
	exit (errno);
}

void	error_message(char *str, t_param *param)
{
	int	i;

	i = ft_strlen(str);
	write (2, "Error\n", 6);
	write (2, str, i);
	free_param (param);
	exit (1);
}

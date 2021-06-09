#include "minitalk.h"

int	error(char *error_mesage)
{
	write(2, error_mesage, ft_strlen(error_mesage));
	write(2, "\n", 1);
	exit(1);
	return (-1);
}

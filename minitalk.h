#ifndef MINITALK_H
# define MINITALK_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include "libft/libft.h"
typedef struct s_global_crutch
{
	int i;
	int chr;
	int **str;
	char *str_final;
}				t_global_crutch;
int	error(char *error_mesage);
#endif

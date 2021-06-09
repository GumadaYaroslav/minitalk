#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "minitalk.h"

void	pid_validater(char *pid)
{
	int	i;
	int	pid_num;

	i = 0;
	while (i != (int)ft_strlen(pid))
	{
		if (!ft_isdigit(pid[i]))
			error("clinet: not valid pid");
		i++;
	}
	if (i > 10)
		error("clinet: not valid pid");
	pid_num = ft_atoi(pid);
	if (pid_num < 0 || pid_num >= 99999)
		error("clinet: not valid pid");
	if (pid_num == 0)
		error("clinet: you are not authorized to send\
		anything to this address");
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc == 1 || argc == 2)
		error("clinet: you need to enter PID and string");
	if (argc > 3)
		error("clinet: too many arguments");
	pid_validater(argv[1]);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (i != (int)ft_strlen(argv[2]) + 1)
	{
		argc = 128;
		while (argc != 0)
		{
			usleep(15);
			if (argc & argv[2][i])
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			argc = argc >> 1;
		}
		i++;
	}
	ft_putstr_fd("message has been sent\n", 1);
}

#include "minitalk.h"

int	pov_of_two(int num, int s)
{
	while (s != 0)
	{
		num *= 2;
		s--;
	}
	return (num);
}

void	handl_sig(int sig)
{
	static int	s;
	static int	count = 7;
	static int	j;
	static char	buf[1000];

	if (sig == SIGUSR1)
		s = s | (1 << count);
	count--;
	if (count == -1)
	{
		count = 7;
		buf[j] = s;
		j++;
		if (s == '\0')
		{
			write(1, buf, ft_strlen(buf));
			j = 0;
		}
		s = 0;
	}
	if (j == 999)
	{
		write(1, buf, ft_strlen(buf));
		j = 0;
	}
}

int	main(void)
{
	int	i;

	i = (int)getpid();
	ft_putstr_fd("this is PID of server - ", 1);
	ft_putnbr_fd(i, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, handl_sig);
	signal(SIGUSR2, handl_sig);
	while (1)
	{
	}
	return (0);
}

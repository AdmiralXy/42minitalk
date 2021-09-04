#include "ft_minitalk.h"

void	ft_send_message(int pid, char *message)
{
	int		i;
	int		shift;
	int		result;

	i = 0;
	while (message[i] != '\0')
	{
		shift = 0;
		while (shift < 8)
		{
			printf("message[i] >> shift 1: %d            ", message[i] >> shift);
			printf("message[i] >> shift & 1: %d \n", (message[i] >> shift) & 1);
			if ((message[i] >> shift) & 1)
				result = kill(pid, SIGUSR2);
			else
				result = kill(pid, SIGUSR1);
			shift++;
			usleep(100);
		}
		i++;
	}
	if (result == -1)
	{
		ft_putendl_fd("Server PID is invalid!", 1);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;

	server_pid = atoi(argv[1]);
	if (argc != 3)
	{
		if (argc < 3)
			ft_putendl_fd("Please specify server PID and message.", 1);
		if (argc > 3)
			ft_putendl_fd("Please remove unnecessary parameters.", 1);
		return (EXIT_FAILURE);
	}
	if (server_pid < 0)
	{
		ft_putendl_fd("Please enter the PID of the server correctly.", 1);
	}
	ft_send_message(server_pid, argv[2]);
	return (EXIT_SUCCESS);
}
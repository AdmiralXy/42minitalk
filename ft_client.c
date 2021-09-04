#include "ft_minitalk.h"

//void ft_print_byte(int b)
//{
//	for (int i = 0; i < 8; i++) {
//		printf("%c", (b & 0x80) ? '1' : '0');
//		b <<= 1;
//	}
//}

void	ft_message_handler(int bit)
{
	(void)bit;
	ft_putendl_fd("Message successfully delivered.", 1);
}

void	ft_send_byte(int pid, char byte)
{
	int		shift;
	int		result;
	int 	bit;

	shift = 0;
	while (shift < 8)
	{
		bit = (byte >> shift) & 1;
		if (bit == 0)
			result = kill(pid, SIGUSR1);
		else
			result = kill(pid, SIGUSR2);
		shift++;
		usleep(25);
	}
	if (result == -1)
	{
		ft_putendl_fd("Server PID is invalid!", 1);
		exit(EXIT_FAILURE);
	}
}

void	ft_send_message(int pid, char *message)
{
	int		i;

	i = 0;
	while (message[i] != '\0')
	{
		ft_send_byte(pid, message[i]);
		i++;
	}
	ft_send_byte(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc != 3)
	{
		if (argc < 3)
			ft_putendl_fd("Please specify server PID and message.", 1);
		if (argc > 3)
			ft_putendl_fd("Please remove unnecessary parameters.", 1);
		return (EXIT_FAILURE);
	}
	server_pid = atoi(argv[1]);
	if (server_pid < 0)
	{
		ft_putendl_fd("Please enter the PID of the server correctly.", 1);
	}
	ft_send_message(server_pid, argv[2]);
	while (TRUE)
	{
		signal(SIGUSR2, ft_message_handler);
		pause();
	}
	return (EXIT_SUCCESS);
}
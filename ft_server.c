#include "ft_minitalk.h"

t_char_handler	g_char_handler;

void	ft_build_message(int bit, t_char_handler *char_handler)
{
	if (bit == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	char_handler->byte += (bit << char_handler->size);
	char_handler->size++;
	if (char_handler->size == 8)
	{
		ft_putchar_fd(char_handler->byte, 1);
		if (!char_handler->byte)
			ft_putchar_fd('\n', 1);
		char_handler->byte = 0;
		char_handler->size = 0;
	}
}

void	ft_message_handler(int bit)
{
	ft_build_message(bit, &g_char_handler);
}

int	main(void)
{
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putendl_fd("", 1);
	while (TRUE)
	{
		signal(SIGUSR2, ft_message_handler);
		signal(SIGUSR1, ft_message_handler);
		pause();
	}
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 20:40:32 by                   #+#    #+#             */
/*   Updated: 2021/09/07 20:40:32 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

t_char_handler	g_char_handler;

void	ft_build_message(int bit, t_char_handler *char_handler)
{
	if (bit == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	char_handler->byte += bit << char_handler->size;
	char_handler->size++;
	if (char_handler->size == 8)
	{
		ft_putchar_fd(char_handler->byte, 1);
		if (!char_handler->byte)
		{
			ft_putchar_fd('\n', 1);
			kill(char_handler->client_pid, SIGUSR1);
		}
		char_handler->byte = 0;
		char_handler->size = 0;
	}
	kill(char_handler->client_pid, SIGUSR2);
}

void	ft_message_handler(int bit, siginfo_t *info, void *context)
{
	(void)context;
	g_char_handler.client_pid = info->si_pid;
	ft_build_message(bit, &g_char_handler);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_message_handler;
	g_char_handler.byte = 0;
	g_char_handler.size = 0;
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putendl_fd("", 1);
	while (1)
	{
		sigaction(SIGUSR2, &sa, NULL);
		sigaction(SIGUSR1, &sa, NULL);
		pause();
	}
	return (0);
}

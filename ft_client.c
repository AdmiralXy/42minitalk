/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 20:40:23 by                   #+#    #+#             */
/*   Updated: 2021/09/07 20:40:28 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	ft_bit_handler(int bit)
{
	(void)bit;
}

void	ft_send_byte(int pid, char byte)
{
	int		shift;
	int		result;
	int		bit;

	shift = 0;
	while (shift < 8)
	{
		bit = (byte >> shift) & 1;
		if (bit == 0)
			result = kill(pid, SIGUSR1);
		else
			result = kill(pid, SIGUSR2);
		shift++;
		if (result == -1)
		{
			ft_putendl_fd("Server PID is invalid or doesn't exist!", 1);
			exit(1);
		}
		usleep(100);
	}
}

void	ft_send_message(int pid, char *message)
{
	int		i;

	i = 0;
	usleep(50);
	while (message[i] != '\0')
	{
		ft_send_byte(pid, message[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int					server_pid;
	if (argc != 3)
	{
		if (argc < 3)
			ft_putendl_fd("Please specify server PID and message.", 1);
		if (argc > 3)
			ft_putendl_fd("Please remove unnecessary parameters.", 1);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid < 0)
		ft_putendl_fd("Please enter the PID of the server correctly.", 1);
	ft_putendl_fd("Trying to send...", 1);
	ft_send_message(server_pid, argv[2]);
	ft_putendl_fd("Message successfully delivered!", 1);
	return (0);
}

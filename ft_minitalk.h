/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:28:42 by                   #+#    #+#             */
/*   Updated: 2021/09/06 20:17:24 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_char_handler
{
	char			byte;
	unsigned int	size;
	size_t 			client_pid;
}				t_char_handler;

void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

#endif

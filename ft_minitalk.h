/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:28:42 by                   #+#    #+#             */
/*   Updated: 2021/09/04 14:34:31 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# include "libft/libft.h"
# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>

# define TRUE 1

typedef struct s_char_handler
{
	char			byte;
	unsigned int	size;
	size_t 			client_pid;
}				t_char_handler;

#endif

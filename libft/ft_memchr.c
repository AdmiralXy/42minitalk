/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricky <kricky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 10:35:56 by kricky            #+#    #+#             */
/*   Updated: 2021/09/01 10:35:57 by kricky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr_str;

	ptr_str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr_str[i] == (unsigned char)c)
			return (ptr_str + i);
		i++;
	}
	return (NULL);
}

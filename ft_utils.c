#include "ft_minitalk.h"

static	int	ft_ilen(int n)
{
	int			i;
	int long	number;

	i = 0;
	number = n;
	if (number < 0)
	{
		number *= -1;
		i++;
	}
	else if (number == 0)
		i++;
	while (number > 0)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	int			i;
	int long	number;
	int			size;
	char		nbr[10000];

	i = 0;
	size = ft_ilen(n);
	number = n;
	nbr[size--] = '\0';
	if (number < 0)
	{
		nbr[0] = '-';
		number *= -1;
	}
	else if (number == 0)
		nbr[size] = '0';
	while (number > 0)
	{
		nbr[size--] = '0' + (number % 10);
		number = number / 10;
	}
	i = 0;
	while (nbr[i] != '\0')
		write(fd, &nbr[i++], 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
		write(fd, "\n", 1);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

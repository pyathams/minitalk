/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:17:45 by pyathams          #+#    #+#             */
/*   Updated: 2024/05/05 22:05:31 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	long	nb;
	int		len;
	int		i;

	len = 0;
	while (str && str[len])
		len++;
	i = 0;
	nb = 0;
	while (i < len)
	{
		nb = (nb * 10) + str[i] - 48;
		i++;
	}
	return (nb);
}

void	send_bits(int pid, char c)
{
	int		i;
	int		bit;
	char	cha;

	i = 7;
	cha = c;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit)
		{
			kill(pid, SIGUSR2);
		}
		else
		{
			kill(pid, SIGUSR1);
		}
		i--;
		usleep(160);
	}
	if (cha)
		usleep(320);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		write(1, "Please Enter valid args\n", 24);
	else
	{
		pid = ft_atoi(argv[1]);
		while (argv[2] && *argv[2])
			send_bits(pid, *argv[2]++);
		send_bits(pid, '\n');
	}
	return (0);
}

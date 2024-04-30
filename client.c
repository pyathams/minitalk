/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:17:45 by pyathams          #+#    #+#             */
/*   Updated: 2024/04/30 14:47:49 by pyathams         ###   ########.fr       */
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

void	send_bits(int pid, char *message)
{
	int		letter;
	int		i;

	letter = 0;
	while (message[letter])
	{
		i = -1;
		while (++i < 8)
		{
			if (((unsigned char)(message[letter] >> (7 - i)) & 1) == 0)
				kill(pid, SIGUSR1);
			else if (((unsigned char)(message[letter] >> (7 - i)) & 1) == 1)
				kill(pid, SIGUSR2);
			usleep(50);
		}
		letter++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR1);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (!pid)
		{
			write(1,"Enter correct sever id", 23);
			return (0);
		}
		str = argv[2];
		if (str[0] == 0)
		{
			write(1, "Please give a message to server !!", 35);
			return (0);
		}
		send_bits(pid, str);
	}
	else
	{
		write(1, "Error Too much or few arguments. \nmake sure\n", 45);
		write(1, "you enter arguments as follows: ", 33);
		write(1, "./client <pid> <message>", 25);
	}
}

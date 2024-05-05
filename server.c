/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:17:42 by pyathams          #+#    #+#             */
/*   Updated: 2024/05/05 22:04:48 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	ft_putnbr(long nbr)
{
	char	temp;

	if (nbr / 10 > 0)
		ft_putnbr (nbr / 10);
	temp = nbr % 10 + '0';
	write(1, &temp, 1);
}

void	sig_handle(int signal)
{
	static int	i;
	static char	n;
	int			nb;

	if (signal == SIGUSR1)
		nb = 0;
	else
		nb = 1;
	n = (n << 1) + nb;
	i++;
	if (i == 8)
	{
		write(1, &n, 1);
		i = 0;
		n = 0;
	}
	usleep(50);
}

int	main(void)
{
	struct sigaction	sigact;

	sigact.sa_handler = &sig_handle;
	sigact.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	write(1, "Server PID = ", 14);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		usleep(1);
	}
	return (0);
}

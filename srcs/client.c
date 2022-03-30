/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:09:07 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/28 10:47:31 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_nbr_bin(int n, int pid)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		if (n % 2)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		n = n / 2;
		i--;
		usleep(120);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		pid;

	i = 0;
	if (argc < 3)
		exit(1);
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
		ft_nbr_bin(argv[2][i++], pid);
	ft_nbr_bin('\n', pid);
	return (0);
}

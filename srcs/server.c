/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:21:23 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/28 10:58:15 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_data	g_data;

void	put_zero(int signum)
{
	(void) signum;
	g_data.buff[g_data.index] = 0;
	g_data.index++;
}

void	put_one(int signum)
{
	(void) signum;
	g_data.buff[g_data.index] = 1;
	g_data.index++;
}

int	twopow(int i)
{
	int	pow;

	pow = 1;
	while (i)
	{
		pow *= 2;
		i--;
	}
	return (pow);
}

void	putchar_b(char *buff)
{
	int		i;
	char	character;

	i = 7;
	character = 0;
	while (i >= 0)
	{
		character += buff[i] * twopow(i);
		i--;
	}
	write(1, &character, 1);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Awaiting message... PID: %d\n", pid);
	signal(SIGUSR1, &put_zero);
	signal(SIGUSR2, &put_one);
	g_data.index = 0;
	while (1)
	{
		if (g_data.index == 7)
		{
			putchar_b(g_data.buff);
			g_data.index = -1;
		}
		pause();
	}
}

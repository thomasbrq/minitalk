/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:21:49 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/28 10:54:36 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "../printf/includes/ft_printf.h"

typedef struct s_data
{
	char	buff[8];
	int		index;
}				t_data;

void	put_zero(int signum);
void	put_one(int signum);
void	putchar_b(char *buff);
int		twopow(int i);
void	ft_nbr_bin(int n, int pid);

#endif

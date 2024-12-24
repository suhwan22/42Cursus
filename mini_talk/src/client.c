/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 01:56:50 by suhkim            #+#    #+#             */
/*   Updated: 2022/09/30 02:49:20 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	send_character(int pid, int c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (c % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c /= 2;
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;

	server_pid = ft_atoi(argv[1]);
	if (argc != 3)
		return (0);
	else
	{
		while (*argv[2])
		{
			send_character(server_pid, *argv[2]);
			argv[2]++;
		}
	}
	return (0);
}

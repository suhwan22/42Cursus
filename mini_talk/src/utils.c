/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 02:17:34 by suhkim            #+#    #+#             */
/*   Updated: 2024/12/25 02:32:51 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_pid(int pid)
{
	char	tmp;

	if (pid / 10 == 0)
	{
		tmp = pid + '0';
		write(1, &tmp, 1);
		return ;
	}
	print_pid(pid / 10);
	tmp = pid % 10 + '0';
	write(1, &tmp, 1);
}

int	is_space(char c)
{
	if (c == '\n' || c == '\t' || c == '\r'
		|| c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	int		minus;
	int		ans;

	minus = 1;
	ans = 0;
	i = 0;
	while (is_space(*(str + i)))
		i++;
	while (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			minus *= -1;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		ans = ans * 10 + *(str + i) - '0';
		i++;
	}
	return (ans * minus);
}

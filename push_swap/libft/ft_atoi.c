/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:43:41 by suhkim            #+#    #+#             */
/*   Updated: 2022/11/12 01:39:34 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long long	ans;
	int			sign;
	int			count;

	count = 0;
	ans = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\r'
		|| *str == '\n' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign = -1;
	while (++count && *str && *str >= '0' && *str <= '9')
	{
		ans = 10 * ans + (*str++ - '0');
		if ((count > 19 && sign == -1) || (ans < 0 && sign == -1))
			return ((int)(-9223372036854775807 - 1));
		else if ((count > 19 && sign == 1) || (ans < 0 && sign == 1))
			return ((int)9223372036854775807);
	}
	return (sign * (int)ans);
}

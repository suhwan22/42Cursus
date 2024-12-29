/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 05:27:07 by suhkim            #+#    #+#             */
/*   Updated: 2022/11/13 21:35:00 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_strcpycat(char *dest, char *src1, char *src2)
{
	while (*src1)
	{
		*dest = *src1;
		dest++;
		src1++;
	}
	while (*src2)
	{
		*dest = *src2;
		dest++;
		src2++;
	}
}

void	check_input(t_info *info)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (!valid_input(str))
			put_error_bonus();
		exe_str_op(info, str);
		str = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc == 1)
		return (1);
	if (check_error_bonus(argc, argv))
		return (put_error_bonus());
	if (!init_info_bonus(&info))
		return (0);
	get_parameters_bonus(info.a_stack, argv, argc);
	check_input(&info);
	if (check_ans_bonus(&info))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

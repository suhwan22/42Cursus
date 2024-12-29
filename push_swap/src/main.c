/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:07:07 by suhkim            #+#    #+#             */
/*   Updated: 2022/11/13 21:35:00 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc == 1)
		return (0);
	if (check_error(argc, argv))
		return (put_error());
	if (already_sort(argc, argv))
		return (0);
	if (!init_info(&info))
		return (0);
	get_parameters(info.a_stack, argv, argc);
	if (argc == 2)
		return (0);
	if (argc == 3)
		return (sort_two(&info));
	if (argc == 4)
		return (sort_three(&info));
	divide(&info, argv, argc);
	greedy_sort(&info);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:12:45 by suhkim            #+#    #+#             */
/*   Updated: 2022/11/13 21:35:00 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	*malloc_arr(char **argv, int len)
{
	int	i;
	int *arr;

	i = 0;
	arr = malloc(sizeof(int) * (len - 1));
	if (!arr)
		return (0);
	while (++i < len)
		*(arr + i - 1) = ft_atoi(argv[i]);
	return (arr);
}

static int	get_point(t_info *info, char **argv, int len)
{
	int	*arr;

	arr = malloc_arr(argv, len);
	if (!arr)
		return (0);
	arr_sort(arr, len - 1);
	info->min = arr[0];
	info->max = arr[len - 2];
	info->p1 = arr[(len - 1) / 3];
	info->p2 = arr[2 * ((len - 1) / 3)];
	free(arr);
	return (1);
}

static void	only_three_a_stack(t_info *info)
{
	while (info->a_stack->size > 3)
	{
		if (info->a_stack->head.next->data != info->max)
			exe_n_cmd(info, 1, &pb, "pb");
		else
			exe_n_cmd(info, 1, &ra, "ra");
	}
}

void	divide(t_info *info, char **argv, int len)
{
	int	r;

	get_point(info, argv, len);
	r = info->a_stack->size;
	while (info->a_stack->size >= 4 && r--)
	{
		if (info->a_stack->head.next->data < info->p1)
		{
			exe_n_cmd(info, 1, &pb, "pb");
			exe_n_cmd(info, 1, &rb, "rb");
		}
		else if (info->a_stack->head.next->data >= info->p2)
			exe_n_cmd(info, 1, &ra, "ra");
		else
			exe_n_cmd(info, 1, &pb, "pb");
	}
	only_three_a_stack(info);
	sort_three(info);
}

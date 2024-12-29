/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 05:27:52 by suhkim            #+#    #+#             */
/*   Updated: 2022/11/13 21:35:00 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	get_min_t(t_info *info, int	*min, int min_t, int t)
{
	int	num;

	num = get_num_of_commands(info, t);
	if (t <= info->a_stack->size / 2 && t <= info->b_stack->size)
	{
		if (*min >= num)
		{
			*min = num;
			min_t = t;
		}
	}
	if (info->b_stack->size - t + 1 <= info->a_stack->size / 2 && \
			info->b_stack->size - t + 1 <= info->b_stack->size)
	{
		if (*min >= num)
		{
			*min = num;
			min_t = t;
		}
	}
	return (min_t);
}

void	set_triangle(t_info *info)
{
	t_node	*temp;
	int		cnt;

	cnt = 0;
	temp = info->a_stack->head.next;
	if (temp->data == info->min)
		return ;
	while (temp->data != info->min)
	{
		temp = temp->next;
		cnt++;
	}
	if (cnt > info->a_stack->size / 2)
		exe_n_cmd(info, info->a_stack->size - cnt, &rra, "rra");
	else
		exe_n_cmd(info, cnt, &ra, "ra");
}

void	greedy_sort(t_info *info)
{
	int	t;
	int	min_t;
	int	min;

	while (info->b_stack->size)
	{
		min_t = 1;
		min = get_num_of_commands(info, 1);
		t = 1;
		while (t <= info->b_stack->size)
		{
			min_t = get_min_t(info, &min, min_t, t);
			t++;
		}
		exe_t_index(info, min_t);
	}
	set_triangle(info);
}

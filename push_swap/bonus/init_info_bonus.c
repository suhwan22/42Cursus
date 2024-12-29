/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 01:54:27 by suhkim            #+#    #+#             */
/*   Updated: 2022/11/13 21:35:00 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker_bonus.h"

static void	init_stack_bonus(t_stack *stack)
{
	stack->head.next = &stack->tail;
	stack->tail.pre = &stack->head;
	stack->size = 0;
}

int	init_info_bonus(t_info *info)
{
	info->a_stack = malloc(sizeof(t_stack));
	if (!info->a_stack)
		return (0);
	info->b_stack = malloc(sizeof(t_stack));
	if (!info->b_stack)
	{
		free(info->a_stack);
		return (0);
	}
	init_stack_bonus(info->a_stack);
	init_stack_bonus(info->b_stack);
	return (1);
}

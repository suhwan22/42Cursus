#include "./checker_bonus.h"

void	pa_bonus(t_info *info)
{
	int	data;

	if (!info->b_stack->size)
		return ;
	data = pop_front_bonus(info->b_stack);
	push_front_bonus(info->a_stack, data);
}

void	pb_bonus(t_info *info)
{
	int	data;

	if (!info->a_stack->size)
		return ;
	data = pop_front_bonus(info->a_stack);
	push_front_bonus(info->b_stack, data);
}

void	ra_bonus(t_info *info)
{
	int	data;

	if (info->a_stack->size <= 1)
		return ;
	data = pop_front_bonus(info->a_stack);
	push_back_bonus(info->a_stack, data);
}

void	rb_bonus(t_info *info)
{
	int	data;

	if (info->b_stack->size <= 1)
		return ;
	data = pop_front_bonus(info->b_stack);
	push_back_bonus(info->b_stack, data);
}

void	rr_bonus(t_info *info)
{
	ra_bonus(info);
	rb_bonus(info);
}

void	rra_bonus(t_info *info)
{
	int	data;

	if (info->a_stack->size <= 1)
		return ;
	data = pop_back_bonus(info->a_stack);
	push_front_bonus(info->a_stack, data);
}

void	rrb_bonus(t_info *info)
{
	int	data;

	if (info->b_stack->size <= 1)
		return ;
	data = pop_back_bonus(info->b_stack);
	push_front_bonus(info->b_stack, data);
}

void	rrr_bonus(t_info *info)
{
	rra_bonus(info);
	rrb_bonus(info);
}

void	sa_bonus(t_info *info)
{
	int	data;

	if (info->a_stack->size < 2)
		return ;
	data = info->a_stack->head.next->data;
	info->a_stack->head.next->data = info->a_stack->head.next->next->data;
	info->a_stack->head.next->next->data = data;
}

void	sb_bonus(t_info *info)
{
	int	data;

	if (info->b_stack->size < 2)
		return ;
	data = info->b_stack->head.next->data;
	info->b_stack->head.next->data = info->b_stack->head.next->next->data;
	info->b_stack->head.next->next->data = data;
}

void	ss_bonus(t_info *info)
{
	sa_bonus(info);
	sb_bonus(info);
}

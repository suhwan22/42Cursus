#include "./push_swap.h"

void	pa(t_info *info, char *str)
{
	int	data;

	if (!info->b_stack->size)
		return ;
	if (!ft_strncmp(str, "pa", 2))
		ft_printf("pa\n");
	data = pop_front(info->b_stack);
	push_front(info->a_stack, data);
}

void	pb(t_info *info, char *str)
{
	int	data;

	if (!info->a_stack->size)
		return ;
	if (!ft_strncmp(str, "pb", 2))
		ft_printf("pb\n");
	data = pop_front(info->a_stack);
	push_front(info->b_stack, data);
}

void	sa(t_info *info, char *str)
{
	int	data;

	if (info->a_stack->size < 2)
		return ;
	if (!ft_strncmp(str, "sa", 2))
		ft_printf("sa\n");
	data = info->a_stack->head.next->data;
	info->a_stack->head.next->data = info->a_stack->head.next->next->data;
	info->a_stack->head.next->next->data = data;
}

void	sb(t_info *info, char *str)
{
	int	data;

	if (info->b_stack->size < 2)
		return ;
	if (!ft_strncmp(str, "sb", 2))
		ft_printf("sb\n");
	data = info->b_stack->head.next->data;
	info->b_stack->head.next->data = info->b_stack->head.next->next->data;
	info->b_stack->head.next->next->data = data;
}

void	ss(t_info *info, char *str)
{
	if (!ft_strncmp(str, "ss", 2))
		ft_printf("ss\n");
	sa(info, str);
	sb(info, str);
}

void	ra(t_info *info, char *str)
{
	int	data;

	if (info->a_stack->size <= 1)
		return ;
	if (!ft_strncmp(str, "ra", 2))
		ft_printf("ra\n");
	data = pop_front(info->a_stack);
	push_back(info->a_stack, data);
}

void	rb(t_info *info, char *str)
{
	int	data;

	if (info->b_stack->size <= 1)
		return ;
	if (!ft_strncmp(str, "rb", 2))
		ft_printf("rb\n");
	data = pop_front(info->b_stack);
	push_back(info->b_stack, data);
}

void	rr(t_info *info, char *str)
{
	if (!ft_strncmp(str, "rr", 2))
		ft_printf("rr\n");
	ra(info, str);
	rb(info, str);
}

void	rra(t_info *info, char *str)
{
	int	data;

	if (info->a_stack->size <= 1)
		return ;
	if (!ft_strncmp(str, "rra", 3))
		ft_printf("rra\n");
	data = pop_back(info->a_stack);
	push_front(info->a_stack, data);
}

void	rrb(t_info *info, char *str)
{
	int	data;

	if (info->b_stack->size <= 1)
		return ;
	if (!ft_strncmp(str, "rrb", 3))
		ft_printf("rrb\n");
	data = pop_back(info->b_stack);
	push_front(info->b_stack, data);
}

void	rrr(t_info *info, char *str)
{
	if (!ft_strncmp(str, "rrr", 3))
		ft_printf("rrr\n");
	rra(info, str);
	rrb(info, str);
}

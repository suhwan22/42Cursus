#include "./checker_bonus.h"

int	valid_input(char *str)
{
	if (!ft_strncmp_bonus(str, "sa\n", 3) || \
			!ft_strncmp_bonus(str, "sb\n", 3) || \
			!ft_strncmp_bonus(str, "pa\n", 3) || \
			!ft_strncmp_bonus(str, "pb\n", 3) || \
			!ft_strncmp_bonus(str, "ra\n", 3) || \
			!ft_strncmp_bonus(str, "rb\n", 3) || \
			!ft_strncmp_bonus(str, "rr\n", 3) || \
			!ft_strncmp_bonus(str, "rrr\n", 4) || \
			!ft_strncmp_bonus(str, "rra\n", 4) || \
			!ft_strncmp_bonus(str, "rrb\n", 4) || \
			!ft_strncmp_bonus(str, "ss\n", 3))
		return (1);
	else
		return (0);
}

int	check_ans_bonus(t_info *info)
{
	t_node	*temp;

	temp = info->a_stack->head.next;
	while (temp->next != &info->a_stack->tail)
	{
		if (!(temp->data < temp->next->data))
			return (0);
		temp = temp->next;
	}
	if (info->b_stack->size == 0)
		return (1);
	else
		return (0);
}

#include "./push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	already_sort(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc - 1)
	{
		if (!(ft_atoi(*(argv + i)) < ft_atoi(*(argv + i + 1))))
			return (0);
	}
	return (1);
}

int	get_pos(t_info *info, int target_index)
{
	t_node	*temp;
	int		target;
	int		pos_index;
	int		min_index;
	int		min;

	pos_index = 0;
	temp = info->b_stack->head.next;
	while (--target_index)
		temp = temp->next;
	target = temp->data;
	temp = info->a_stack->head.next;
	min_index = 0;
	min = info->max;
	while (pos_index < info->a_stack->size)
	{
		if (target < temp->data && min >= temp->data)
		{
			min_index = pos_index;
			min = temp->data;
		}
		pos_index++;
		temp = temp->next;
	}
	return (min_index);
}

int	get_num_of_commands(t_info *info, int target_index)
{
	int	t;
	int	n;

	t = target_index;
	n = get_pos(info, t);
	if (t <= info->b_stack->size / 2)
	{
		if (n <= info->a_stack->size / 2)
			return (cal_t_upper_n_upper(t, n));
		else
			return (cal_t_upper_n_lower(info, t, n));
	}
	else
	{
		if (n <= info->a_stack->size / 2)
			return (cal_t_lower_n_upper(info, t, n));
		else
			return (cal_t_lower_n_lower(info, t, n));
	}
}

int	get_parameters(t_stack *a_stack, char **param, int len)
{
	int		i;

	i = 1;
	while (i < len)
	{
		push_back(a_stack, ft_atoi(*(param + i)));
		i++;
	}
	return (1);
}

void	get_arr(t_info *info, int *arr)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = info->a_stack->head.next;
	while (temp != &info->a_stack->head && i < 3)
	{
		*(arr + i++) = temp->data;
		temp = temp->next;
	}
}

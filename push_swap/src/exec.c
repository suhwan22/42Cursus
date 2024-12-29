#include "./push_swap.h"

void	exe_n_cmd(t_info *info, int n, void (*f)(t_info *, char *), char *str)
{
	while (n > 0)
	{
		f(info, str);
		n--;
	}
}

void	exe_t_lower_n_lower(t_info *info, int t, int n)
{
	if (info->b_stack->size - t + 1 > info->a_stack->size - n)
	{
		exe_n_cmd(info, info->a_stack->size - n, &rrr, "rrr");
		exe_n_cmd(info, (info->b_stack->size - t + 1) - \
			(info->a_stack->size - n), &rrb, "rrb");
		exe_n_cmd(info, 1, &pa, "pa");
	}
	else
	{
		exe_n_cmd(info, info->b_stack->size - t + 1, &rrr, "rrr");
		exe_n_cmd(info, (info->a_stack->size - n) - \
			(info->b_stack->size - t + 1), &rra, "rra");
		exe_n_cmd(info, 1, &pa, "pa");
	}
}

void	exe_t_lower_n_upper(t_info *info, int t, int n)
{
	exe_n_cmd(info, info->b_stack->size - t + 1, &rrb, "rrb");
	exe_n_cmd(info, n, &ra, "ra");
	exe_n_cmd(info, 1, &pa, "pa");
}

void	exe_t_upper_n_lower(t_info *info, int t, int n)
{
	exe_n_cmd(info, info->a_stack->size - n, &rra, "rra");
	exe_n_cmd(info, t - 1, &rb, "rb");
	exe_n_cmd(info, 1, &pa, "pa");
}

void	exe_t_upper_n_upper(t_info *info, int t, int n)
{
	if (n >= t)
	{
		exe_n_cmd(info, t - 1, &rr, "rr");
		exe_n_cmd(info, n - t + 1, &ra, "ra");
		exe_n_cmd(info, 1, &pa, "pa");
	}
	else
	{
		exe_n_cmd(info, n, &rr, "rr");
		exe_n_cmd(info, t - n - 1, &rb, "rb");
		exe_n_cmd(info, 1, &pa, "pa");
	}
}

void	exe_t_index(t_info *info, int target_index)
{
	int	t;
	int	n;

	t = target_index;
	n = get_pos(info, t);
	if (t <= info->b_stack->size / 2)
	{
		if (n <= info->a_stack->size / 2)
			exe_t_upper_n_upper(info, t, n);
		else
			exe_t_upper_n_lower(info, t, n);
	}
	else
	{
		if (n <= info->a_stack->size / 2)
			exe_t_lower_n_upper(info, t, n);
		else
			exe_t_lower_n_lower(info, t, n);
	}
}

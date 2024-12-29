#include "./push_swap.h"

int	cal_t_lower_n_lower(t_info *info, int t, int n)
{
	int	count;

	count = 0;
	if (info->b_stack->size - t + 1 > info->a_stack->size - n)
	{
		count += info->a_stack->size - n;
		count += (info->b_stack->size - t + 1) - (info->a_stack->size - n);
		count += 1;
	}
	else
	{
		count += info->b_stack->size - t + 1;
		count += (info->a_stack->size - n) - (info->b_stack->size - t + 1);
		count += 1;
	}
	return (count);
}

int	cal_t_lower_n_upper(t_info *info, int t, int n)
{
	int	count;

	count = 0;
	count += info->b_stack->size - t + 1;
	count += n;
	count += 1;
	return (count);
}

int	cal_t_upper_n_lower(t_info *info, int t, int n)
{
	int	count;

	count = 0;
	count += info->a_stack->size - n;
	count += t - 1;
	count += 1;
	return (count);
}

int	cal_t_upper_n_upper(int t, int n)
{
	int	count;

	count = 0;
	if (n >= t)
	{
		count += t - 1;
		count += n - t + 1;
		count += 1;
	}
	else
	{
		count += n;
		count += t - n - 1;
		count += 1;
	}
	return (count);
}

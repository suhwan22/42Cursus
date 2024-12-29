#include "./push_swap.h"

void	arr_sort(int *arr, int len)
{
	int	i;
	int	j;
	int	min;
	int	minidx;

	i = 0;
	while (i < len - 1)
	{
		min = *(arr + i);
		minidx = i;
		j = i;
		while (++j < len)
		{
			if (min > *(arr + j))
			{
				min = *(arr + j);
				minidx = j;
			}
		}
		swap(arr + minidx, arr + i++);
	}
}

int	sort_two(t_info *info)
{
	t_node	*temp;

	temp = info->a_stack->head.next;
	if (temp->data > temp->next->data)
		exe_n_cmd(info, 1, &sa, "sa");
	return (0);
}

int	sort_three(t_info *info)
{
	int	*arr;

	arr = malloc(sizeof(int) * 3);
	if (!arr)
		return (-1);
	get_arr(info, arr);
	if (arr[0] < arr[1] && arr[0] < arr[2] && arr[1] > arr[2])
	{
		exe_n_cmd(info, 1, &rra, "rra");
		exe_n_cmd(info, 1, &sa, "sa");
	}
	else if (arr[0] > arr[1] && arr[0] < arr[2] && arr[1] < arr[2])
		exe_n_cmd(info, 1, &sa, "sa");
	else if (arr[0] < arr[1] && arr[0] > arr[2] && arr[1] > arr[2])
		exe_n_cmd(info, 1, &rra, "rra");
	else if (arr[0] > arr[2] && arr[1] < arr[2] && arr[0] > arr[2])
		exe_n_cmd(info, 1, &ra, "ra");
	else if (arr[0] > arr[1] && arr[1] > arr[2])
	{
		exe_n_cmd(info, 1, &sa, "sa");
		exe_n_cmd(info, 1, &rra, "rra");
	}
	free (arr);
	return (0);
}

#include "./checker_bonus.h"
#include <string.h>

int	get_parameters_bonus(t_stack *a_stack, char **param, int len)
{
	int		i;

	i = 1;
	while (i < len)
	{
		push_back_bonus(a_stack, ft_atoi_bonus(*(param + i)));
		i++;
	}
	return (1);
}

int	ft_isdigit_bonus(int c)
{
	return (c >= '0' && c <= '9');
}

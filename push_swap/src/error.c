#include "./push_swap.h"

static int	check_target_int(char *target)
{
	long long	temp;

	if (!target || !(*target))
		return (0);
	temp = ft_strtol(target);
	if (temp < -2147483648 || temp > 2147483647)
		return (0);
	else
		return (1);
}

static int	check_dup(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc <= 2)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (!ft_strncmp(*(argv + i), *(argv + j), 11))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_error(int argc, char **argv)
{
	int	len;
	int	i;

	len = argc;
	while (--len)
	{
		i = 0;
		while (*(*(argv + len) + i))
		{
			if (i == 0 && (**(argv + len) == '+' || **(argv + len) == '-'))
				i++;
			if (!ft_isdigit(*(*(argv + len) + i)))
				return (1);
			i++;
		}
		if (!check_target_int(*(argv + len)))
			return (1);
	}
	if (check_dup(argc, argv))
		return (1);
	return (0);
}

int	put_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

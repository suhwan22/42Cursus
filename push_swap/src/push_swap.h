/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:29:02 by suhkim            #+#    #+#             */
/*   Updated: 2022/11/13 21:35:01 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	struct s_node	*pre;
	struct s_node	*next;
	int				data;
}	t_node;

typedef struct s_stack
{
	struct s_node	head;
	struct s_node	tail;
	int				size;
}	t_stack;

typedef struct s_info
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	int		p1;
	int		p2;
	int		max;
	int		min;
}	t_info;

void	divide(t_info *info, char **argv, int len);
void	greedy_sort(t_info *info);

int		init_info(t_info *info);

// utils.c
void	swap(int *a, int *b);
int		get_pos(t_info *info, int target_index);
int		get_num_of_commands(t_info *info, int target_index);
int		get_parameters(t_stack *a_stack, char **param, int len);
void	get_arr(t_info *info, int *arr);
int		already_sort(int argc, char **argv);

// error.c
int		check_error(int argc, char **argv);
int		put_error(void);


// sort.c
void	arr_sort(int *arr, int len);
int		sort_two(t_info *info);
int		sort_three(t_info *info);

// cal.c
int		cal_t_upper_n_upper(int t, int n);
int		cal_t_upper_n_lower(t_info *info, int t, int n);
int		cal_t_lower_n_upper(t_info *info, int t, int n);
int		cal_t_lower_n_lower(t_info *info, int t, int n);

// exec.c
void	exe_t_upper_n_upper(t_info *info, int t, int n);
void	exe_t_upper_n_lower(t_info *info, int t, int n);
void	exe_t_lower_n_upper(t_info *info, int t, int n);
void	exe_t_lower_n_lower(t_info *info, int t, int n);
void	exe_t_index(t_info *info, int target_index);
void	exe_n_cmd(t_info *info, int n, void (*f)(t_info *, char *), char *str);

// stack.c
int		push_back(t_stack *stack, int data);
int		push_front(t_stack *stack, int data);
int		pop_back(t_stack *stack);
int		pop_front(t_stack *stack);

// command.c
void	sa(t_info *info, char *str);
void	sb(t_info *info, char *str);
void	ss(t_info *info, char *str);
void	pa(t_info *info, char *str);
void	pb(t_info *info, char *str);
void	ra(t_info *info, char *str);
void	rb(t_info *info, char *str);
void	rr(t_info *info, char *str);
void	rra(t_info *info, char *str);
void	rrb(t_info *info, char *str);
void	rrr(t_info *info, char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:36:20 by suhkim            #+#    #+#             */
/*   Updated: 2024/12/30 02:45:42 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../gnl/get_next_line_bonus.h"
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

int		init_info_bonus(t_info *info);

void	exe_str_op(t_info *info, char *str);

// utils_bonus.c
int		ft_isdigit_bonus(int c);
int		get_parameters_bonus(t_stack *a_stack, char **param, int len);

// valid_bonus.c
int		check_ans_bonus(t_info *info);
int		valid_input(char *str);

// error_bonus.c
int		put_error_bonus(void);
int		check_error_bonus(int argc, char **argv);

// stack_bonus.c
int		push_back_bonus(t_stack *stack, int data);
int		push_front_bonus(t_stack *stack, int data);
int		pop_back_bonus(t_stack *stack);
int		pop_front_bonus(t_stack *stack);

// command_bonus.c
void	sa_bonus(t_info *info);
void	sb_bonus(t_info *info);
void	ss_bonus(t_info *info);
void	pa_bonus(t_info *info);
void	pb_bonus(t_info *info);
void	ra_bonus(t_info *info);
void	rb_bonus(t_info *info);
void	rr_bonus(t_info *info);
void	rra_bonus(t_info *info);
void	rrb_bonus(t_info *info);
void	rrr_bonus(t_info *info);

#endif

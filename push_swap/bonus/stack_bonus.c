#include "./checker_bonus.h"

int	pop_back_bonus(t_stack *stack)
{
	int		data;
	t_node	*temp;

	if (!stack || !stack->size)
		return (0);
	temp = stack->tail.pre;
	data = temp->data;
	temp->pre->next = &stack->tail;
	stack->tail.pre = temp->pre;
	stack->size -= 1;
	free(temp);
	return (data);
}

int	pop_front_bonus(t_stack *stack)
{
	t_node	*temp;
	int		data;

	if (!stack || !stack->head.next)
		return (0);
	temp = stack->head.next;
	data = temp->data;
	stack->head.next = temp->next;
	temp->next->pre = &stack->head;
	stack->size -= 1;
	free(temp);
	return (data);
}

static void	push_back_first(t_stack *stack, t_node *new_node)
{
	new_node->pre = &stack->head;
	new_node->next = &stack->tail;
	stack->head.next = new_node;
	stack->tail.pre = new_node;
}

static void	push_back_common(t_stack *stack, t_node *new_node)
{
	new_node->pre = stack->tail.pre;
	new_node->next = &stack->tail;
	stack->tail.pre->next = new_node;
	stack->tail.pre = new_node;
}

int	push_back_bonus(t_stack *stack, int data)
{
	t_node	*new_node;

	if (!stack)
		return (0);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->data = data;
	if (stack->tail.pre == &stack->head)
		push_back_first(stack, new_node);
	else
		push_back_common(stack, new_node);
	stack->size += 1;
	return (1);
}

static void	push_front_first(t_stack *stack, t_node *new_node)
{
	new_node->next = &stack->tail;
	stack->head.next = new_node;
	new_node->pre = &stack->head;
	stack->tail.pre = new_node;
}

static void	push_front_common(t_stack *stack, t_node *new_node)
{
	new_node->next = stack->head.next;
	stack->head.next->pre = new_node;
	new_node->pre = &stack->head;
	stack->head.next = new_node;
}

int	push_front_bonus(t_stack *stack, int data)
{
	t_node	*new_node;

	if (!stack)
		return (0);
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->data = data;
	if (!stack->head.next)
		push_front_first(stack, new_node);
	else
		push_front_common(stack, new_node);
	stack->size += 1;
	return (1);
}

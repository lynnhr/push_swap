/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchelde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:23:46 by atchelde          #+#    #+#             */
/*   Updated: 2026/01/12 10:23:48 by atchelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack		ft_stack_new(void)
{
	t_stack		rt_stack;

	rt_stack.head = NULL;
	rt_stack.tail = NULL;
	return (rt_stack);
}

int		ft_stack_push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)(malloc(sizeof(t_node)));
	new_node->value = value;
	new_node->next = NULL;
	if (! stack->head)
	{
		stack->head = new_node;
		stack->tail = new_node;
		new_node->previous = NULL;
	}
	else
	{
		stack->head->next = new_node;
		new_node->previous = stack->head;
		stack->head = new_node;
	}
	//free(new_node);
	new_node = NULL;
	return (value);
}

t_node	*ft_stack_pop(t_stack *stack)
{
	t_node	*rt_node;
	t_node	*new_head;

	rt_node = stack->head;
	new_head = rt_node->previous;
	new_head->next = NULL;
	stack->head = new_head;
	return (rt_node);
}

t_node	*ft_stack_peek_head_node(t_stack *stack)
{
	return (stack->head);
}

t_node	*ft_stack_peek_tail_node(t_stack *stack)
{
	return (stack->tail);
}

int		ft_stack_peek_head_value(t_stack *stack)
{
	int		rt_ans;

	if (stack->head != NULL)
		rt_ans = stack->head->value;
	else
		rt_ans = INT_MAX;
	return (rt_ans);
}

int		ft_stack_peek_tail_value(t_stack *stack)
{
	int		rt_ans;

	if (stack->tail != NULL)
		rt_ans = stack->tail->value;
	else
		rt_ans = INT_MAX;
	return (rt_ans);
}

int		ft_stack_size(t_stack *stack)
{
	t_node	*current;
	int		rt_length;

	current = stack->tail;
	rt_length = 0;
	while (current)
	{
		rt_length++;
		current = current->next;
	}
	return (rt_length);
}

void	ft_stack_print_bottom_up(t_stack *stack)
{
	t_node	*current;

	current = stack->tail;
	while (current)
	{
		printf("%d", current->value);
		current = current->next;
		if (current)
			printf("->");
	}
	printf("\n");
	free(current);
}

void	ft_stack_print_top_down(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		printf("%d", current->value);
		current = current->previous;
		if (current)
			printf("<-");
	}
	printf("\n");
	free(current);
}

void	ft_stack_free(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		current = current->previous;
		//ft_stack_print_bottom_up(stack);
		free(current->next);
		current->next = NULL;
		stack->head = current;
		printf("size %d\n", ft_stack_size(stack));
		if (stack->head == stack->tail)
		{
			free(stack->tail);
			stack->tail = NULL;
			printf("size %d\n", ft_stack_size(stack));
			break ;
		}
	}
}

int main()
{
	t_stack my_stack = ft_stack_new();
	// ft_stack_print_bottom_up(&my_stack);
	ft_stack_push(&my_stack, 1);
	// ft_stack_print_bottom_up(&my_stack);
	ft_stack_push(&my_stack, 4);
	ft_stack_push(&my_stack, 6);
	ft_stack_push(&my_stack, 8);
	ft_stack_push(&my_stack, 10);
	// ft_stack_print_bottom_up(&my_stack);
	// ft_stack_print_top_down(&my_stack);
	// printf("%d\n", ft_stack_size(&my_stack));
	//ft_stack_pop(&my_stack);
	ft_stack_print_bottom_up(&my_stack);
	// ft_stack_print_top_down(&my_stack);
	ft_stack_free(&my_stack);
	return (0);
}
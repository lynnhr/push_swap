/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchelde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:18:22 by atchelde          #+#    #+#             */
/*   Updated: 2026/01/12 15:18:23 by atchelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack	ft_stack_new(void)
{
	t_stack	rt_stack;

	rt_stack.head = NULL;
	return (rt_stack);
}

int	ft_stack_push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)(malloc(sizeof(t_node)));
	new_node->value = value;
	new_node->next = stack->head;
	stack->head = new_node;
	new_node = NULL;
	return (value);
}

t_node	*ft_stack_pop(t_stack *stack)
{
	t_node	*rt_node;

	if (! stack->head)
		rt_node = NULL;
	else
	{
		rt_node = stack->head;
		stack->head = rt_node->next;
	}
	return (rt_node);
}

t_node	*ft_stack_peek_head_node(t_stack *stack)
{
	return (stack->head);
}

int	ft_stack_peek_head_value(t_stack *stack)
{
	int		rt_ans;

	if (! stack->head)
		rt_ans = INT_MAX;
	else
		rt_ans = stack->head->value;
	return (rt_ans);
}

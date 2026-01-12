/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:18:32 by atchelde          #+#    #+#             */
/*   Updated: 2026/01/12 23:59:34 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_stack.h"

int	ft_stack_peek_head_value(t_stack *stack)
{
	int		rt_ans;

	if (stack->head != NULL)
		rt_ans = stack->head->value;
	else
		rt_ans = INT_MAX;
	return (rt_ans);
}

int	ft_stack_peek_tail_value(t_stack *stack)
{
	int		rt_ans;

	if (stack->tail != NULL)
		rt_ans = stack->tail->value;
	else
		rt_ans = INT_MAX;
	return (rt_ans);
}

int	ft_stack_size(t_stack *stack)
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
	//remove it cz current was never malloced
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
	//same here
	free(current);
}

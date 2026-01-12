/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchelde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:18:41 by atchelde          #+#    #+#             */
/*   Updated: 2026/01/12 15:18:42 by atchelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stack_free(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		current = current->previous;
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
	return ;
}

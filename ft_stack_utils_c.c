/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:18:41 by atchelde          #+#    #+#             */
/*   Updated: 2026/01/13 00:06:45 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_stack.h"

void	ft_stack_free(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		current = current->previous;
		free(current->next);
		//maybe current = NULL which will cause seg fault
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

//check this function
// void ft_stack_free(t_stack *stack)
// {
//     t_node *current;

//     while (stack->head)
//     {
//         current = stack->head;
//         stack->head = current->previous;
//         free(current);
//     }
//     stack->tail = NULL;
// }


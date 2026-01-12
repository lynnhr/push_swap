/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:18:22 by atchelde          #+#    #+#             */
/*   Updated: 2026/01/13 00:14:25 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_stack.h"

t_stack	ft_stack_new(void)
{
	t_stack	rt_stack;

	rt_stack.head = NULL;
	rt_stack.tail = NULL;
	return (rt_stack);
}

int	ft_stack_push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)(malloc(sizeof(t_node)));
	// i added a failure check
	if (! new_node)
		return (INT_MIN);
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
	new_node = NULL; 
	return (value);
}

t_node	*ft_stack_pop(t_stack *stack)
{
	t_node	*rt_node;
	t_node	*new_head;

    if (! stack->head)
        rt_node = NULL;
    else if (! stack->head->previous)
    {
        free(stack->head);
        stack->head = NULL;
        rt_node = NULL;
    }
    else
    {
        rt_node = stack->head;
        new_head = rt_node->previous;
        new_head->next = NULL;
        stack->head = new_head;
        new_head = NULL;
    }
	return (rt_node);
}

//check this 
// t_node	*ft_stack_pop(t_stack *stack)
// {
// 	t_node	*rt_node;
// 	t_node	*new_head;

// 	if (!stack || !stack->head)
// 		return (NULL);

// 	rt_node = stack->head;

// 	if (!stack->head->previous)
// 	{
// 		/* one element only */
// 		stack->head = NULL;
// 		stack->tail = NULL;
// 	}
// 	else
// 	{
// 		new_head = rt_node->previous;
// 		new_head->next = NULL;
// 		stack->head = new_head;
// 	}

// 	/* detach popped node */
// 	rt_node->previous = NULL;
// 	rt_node->next = NULL;

// 	return (rt_node);
// }
// use it this way since it no longer frees
// t_node *node = ft_stack_pop(&stack);
// if (node)
// {
//     printf("%d\n", node->value);
//     free(node);
// }

t_node	*ft_stack_peek_head_node(t_stack *stack)
{
	return (stack->head);
}

t_node	*ft_stack_peek_tail_node(t_stack *stack)
{
	return (stack->tail);
}

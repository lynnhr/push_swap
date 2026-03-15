/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_operations_a.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:43:38 by atchelde          #+#    #+#             */
/*   Updated: 2026/03/16 01:50:49 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_push_swap_operations.h"
#include "ft_stack.h"

// void	ft_sa(t_stack *stack)
// {
// 	t_node	*temp_1;
// 	t_node	*temp_2;

// 	if (ft_stack_size(stack) > 1)
// 	{
// 		temp_1 = ft_stack_pop(stack);
// 		temp_2 = ft_stack_pop(stack);
// 		ft_stack_push(stack, temp_1->value);
// 		ft_stack_push(stack, temp_2->value);
// 	}
// 	free(temp_1);
// 	free(temp_2);
// 	temp_1 = NULL;
// 	temp_2 = NULL;
// 	ft_printf("sa\n")
// 	return ;
// }

// void	ft_swap_push(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_node	*temp_b;

// 	if (ft_stack_size(stack_b) != 0)
// 	{
// 		temp_b = ft_stack_pop(stack_b);
// 		ft_stack_push(stack_a, temp_b->value);
// 	}
// 	free(temp_b);
// 	temp_b = NULL;
// 	return ;
// }

void ft_rotate(t_stack *stack)
{
	t_node	*current;
	t_node	*save;
	if (!stack || ft_stack_size(stack) <= 1)
		return ;
	save = stack -> head;
	stack -> head = stack -> head -> next;
	current = stack -> head;
	while (current -> next)
		current =  current -> next;
	current -> next = save;
	save -> next = NULL;
}

void	ft_ra(t_stack *a)
{
	ft_rotate(a);
	ft_printf("ra\n");
}

void	ft_rb(t_stack *b)
{
	ft_rotate(b);
	ft_printf("rb\n");
}
void	ft_rr(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}
void	ft_reverse_rotate(t_stack *stack)
{
	t_node	*save;
	t_node *current;
	if (!stack || ft_stack_size(stack) <= 1)
		return ;
	current = stack->head;
	while (current->next->next)
		current = current->next;
	save = current->next;
	current->next = NULL;
	save->next = stack->head;
	stack->head = save;
}

void	ft_rra(t_stack *a)
{
	ft_reverse_rotate(a);
	ft_printf("rra\n");
}


void	ft_rrb(t_stack *b)
{
	ft_reverse_rotate(b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_printf("rrr\n");
}

void ft_swap(t_stack *stack)
{
	t_node	*tmp1;
	t_node	*tmp2;
	
	if (!stack || ft_stack_size(stack) <= 1)
		return ;
	tmp1 = ft_stack_pop(stack);
	tmp2 = ft_stack_pop(stack);
	ft_stack_push(stack, tmp2->value);
	ft_stack_push(stack, tmp1->value);
	free(tmp1);
	free(tmp2);
}

void 	ft_sa(t_stack *a)
{
	ft_swap(a);
	ft_printf("sa\n");
}
void ft_sb(t_stack *b)
{
	ft_swap(b);
	ft_printf("sb\n");
}

void ft_ss(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss\n");
}

void ft_push(t_stack *src, t_stack *dest)
{
	t_node	*tmp;
	
	if (!src || !src->head)
	return ;
	tmp = ft_stack_pop(src);
	ft_stack_push(dest, tmp->value);
	free(tmp);
}

void ft_pa(t_stack *a, t_stack *b)
{
	ft_push(b, a);
	ft_printf("pa\n");
}

void ft_pb(t_stack *a, t_stack *b)
{
	ft_push(a, b);
	ft_printf("pb\n");
}
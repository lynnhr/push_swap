/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_populate_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 22:00:39 by marvin            #+#    #+#             */
/*   Updated: 2026/03/21 00:19:42 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_push_swap.h"

void	ft_populate_stack(t_stack *a, char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	i--;
	while (i >= 0)
	{
		ft_stack_push(a, ft_atoi(args[i]));
		i--;
	}
}
void	ft_assign_indices(t_stack *a)
{
	t_node	*current;
	t_node	*checker;
	int		count;

	current = a->head;
	while (current)
	{
		count = 0;
		checker = a->head;
		while (checker)
		{
			if (current->value > checker->value)
				count++;
			checker = checker->next;
		}
		current->index = count;
		current = current->next;
	}
}

void	ft_stack_print_indices(t_stack *stack)
{
	t_node	*current;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		ft_printf("%d", current->index);
		if (current->next)
			ft_printf("<-");
		current = current->next;
	}
	ft_printf("\n");
}

/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 02:30:36 by marvin            #+#    #+#             */
/*   Updated: 2026/03/16 02:31:51 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "header/ft_stack.h"
#include "header/ft_push_swap.h"

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

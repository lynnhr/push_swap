/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_populate_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 22:00:39 by marvin            #+#    #+#             */
/*   Updated: 2026/03/20 23:28:45 by marvin           ###   ########.fr       */
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

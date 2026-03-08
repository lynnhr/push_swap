/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_operations.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:42:08 by atchelde          #+#    #+#             */
/*   Updated: 2026/03/08 21:06:32 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FT_PUSH_SWAP_OPERATIONS_H
# define FT_PUSH_SWAP_OPERATIONS_H
# include <stdio.h>
# include <stdlib.h>
# include "ft_stack.h"

void	ft_sa(t_stack *stack);
void	ft_swap_swap(t_stack *stack);
void	ft_swap_push(t_stack *stack_a, t_stack *stack_b);
void	ft_ra(t_stack *stack);
void	ft_swap_reverse_rotate(t_stack *stack);


#endif

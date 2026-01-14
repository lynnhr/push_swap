/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_operations.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:42:08 by atchelde          #+#    #+#             */
/*   Updated: 2026/01/14 14:41:42 by marvin           ###   ########.fr       */
=======
/*   By: lhaydar <lhaydar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:42:08 by atchelde          #+#    #+#             */
/*   Updated: 2026/01/14 14:11:50 by lhaydar          ###   ########.fr       */
>>>>>>> 5b68c883698394b2949fe677a46babeb34e8164d
/*                                                                            */
/******************************************************************************/

#ifndef FT_PUSH_SWAP_OPERATIONS_H
# define FT_PUSH_SWAP_OPERATIONS_H
# include <stdio.h>
# include <stdlib.h>
# include "ft_stack.h"

void	ft_swap_stack(t_stack *stack);
void	ft_swap_swap(t_stack *stack);
void	ft_swap_push(t_stack *stack_a, t_stack *stack_b);
void	ft_swap_rotate(t_stack *stack);
void	ft_swap_reverse_rotate(t_stack *stack);


#endif

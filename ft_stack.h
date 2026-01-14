/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaydar <lhaydar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:32:33 by atchelde          #+#    #+#             */
/*   Updated: 2026/01/14 14:12:30 by lhaydar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
}	t_stack;

t_stack	ft_stack_new(void);
t_node	*ft_stack_pop(t_stack *stack);
t_node	*ft_stack_peek_head_node(t_stack *stack);
int		ft_stack_push(t_stack *stack, int value);
int		ft_stack_peek_head_value(t_stack *stack);
int		ft_stack_size(t_stack *stack);
void	ft_stack_print_bottom_up(t_stack *stack);
void	ft_stack_print_top_down(t_stack *stack);
void	ft_stack_free(t_stack *stack);
void	ft_swap_stack(t_stack *stack);

#endif

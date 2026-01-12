/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchelde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:32:33 by atchelde          #+#    #+#             */
/*   Updated: 2026/01/12 10:32:34 by atchelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node   *previous;
} t_node;

typedef struct s_stack
{
	t_node  *head; // top
	t_node  *tail; // bottom
} t_stack;

t_stack	ft_stack_new(void);
int		ft_stack_push(t_stack *stack, int value);
t_node	*ft_stack_pop(t_stack *stack);
t_node	*ft_stack_peek_head_node(t_stack *stack);
t_node	*ft_stack_peek_tail_node(t_stack *stack);
int		ft_stack_peek_head_value(t_stack *stack);
int		ft_stack_peek_tail_value(t_stack *stack);
int		ft_stack_size(t_stack *stack);
void	ft_stack_print_bottom_up(t_stack *stack);
void	ft_stack_print_top_down(t_stack *stack);

#endif

/*

#include <stdio.h>

void print_int(int x) { printf("Int: %d\n", x); }
void print_double(double x) { printf("Double: %f\n", x); }

#define print(X) _Generic((X), \
	int: print_int, \
	double: print_double \
)(X)

int main() {
	int i = 10;
	double d = 3.14;
	print(i);   // Calls print_int
	print(d);   // Calls print_double
	return 0;
}


*/
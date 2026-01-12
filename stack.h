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
	int		value;
	t_node	*next;
    t_node  *previous;
} t_node;

typedef struct s_stack
{
    t_node  *head; // top
    t_node  *tail; // bottom
} t_stack;

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
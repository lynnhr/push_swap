/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaydar <lhaydar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 00:00:00 by lhaydar           #+#    #+#             */
/*   Updated: 2026/05/12 00:00:00 by lhaydar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_print_strategy(t_strategy s, double disorder)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (s == COMPLEX)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else if (s == SIMPLE)
		ft_putstr_fd("Simple / O(n^2)\n", 2);
	else if (s == MEDIUM)
		ft_putstr_fd("Medium / O(n sqrt n)\n", 2);
	else if (disorder < 0.2)
		ft_putstr_fd("Adaptive / O(n)\n", 2);
	else if (disorder < 0.5)
		ft_putstr_fd("Adaptive / O(n sqrt n)\n", 2);
	else
		ft_putstr_fd("Adaptive / O(n log n)\n", 2);
}

static void	ft_print_ops_swap_push(t_bench *b)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(b->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(b->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(b->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(b->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(b->pb, 2);
	ft_putchar_fd('\n', 2);
}

static void	ft_print_ops_rotate(t_bench *b)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(b->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(b->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(b->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(b->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(b->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(b->rrr, 2);
	ft_putchar_fd('\n', 2);
}

void	ft_print_bench(t_bench *b, t_strategy s, double disorder)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putdouble(disorder * 100, 2, 2);
	ft_putstr_fd("%\n", 2);
	ft_print_strategy(s, disorder);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(b->total, 2);
	ft_putchar_fd('\n', 2);
	ft_print_ops_swap_push(b);
	ft_print_ops_rotate(b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:42:08 by atchelde          #+#    #+#             */
/*   Updated: 2026/04/12 17:16:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include "ft_stack.h"

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_bench;

void		ft_rotate(t_stack *stack);
void		ft_ra(t_stack *a, t_bench *bench);
void		ft_rb(t_stack *b, t_bench *bench);
void		ft_rr(t_stack *a, t_stack *b, t_bench *bench);

void		ft_reverse_rotate(t_stack *stack);
void		ft_rra(t_stack *a, t_bench *bench);
void		ft_rrb(t_stack *b, t_bench *bench);
void		ft_rrr(t_stack *a, t_stack *b, t_bench *bench);

void		ft_swap(t_stack *stack);
void		ft_sa(t_stack *a, t_bench *bench);
void		ft_sb(t_stack *b, t_bench *bench);
void		ft_ss(t_stack *a, t_stack *b, t_bench *bench);

void		ft_push(t_stack *src, t_stack *dst);
void		ft_pa(t_stack *a, t_stack *b, t_bench *bench);
void		ft_pb(t_stack *a, t_stack *b, t_bench *bench);

int			ft_check_duplicates(char **argv, int n);
long		ft_atol(char *str);
void		ft_free_split(char **split);

char		**ft_get_args(int argc, char **argv);
int			ft_valid_int(char *str);
int			ft_valid_input(char **arr);

void		ft_init_stacks(t_stack *a, t_stack *b, char **args);
void		ft_populate_stack(t_stack *a, char **args);
void		ft_assign_indices(t_stack *a);
void		ft_stack_print_indices(t_stack *stack);
void		ft_cleanup(t_stack *a, t_stack *b, char **args, int is_split);

int			ft_flag(char *str);
t_strategy	ft_get_strategy(char *flag);

int			ft_count_bits(int n);
void		ft_radix_sort(t_stack *a, t_stack *b, t_bench *bench);
int			ft_is_sorted(t_stack *a);

int			ft_find_min_pos(t_stack *a);
void		ft_bring_to_top(t_stack *a, int pos, t_bench *bench);
void		ft_selection_sort(t_stack *a, t_stack *b, t_bench *bench);

int			ft_squareroot(int n);
int			ft_find_max_index(t_stack *b);
void		ft_bring_max_to_top(t_stack *b, t_bench *bench);
void		ft_pull_back(t_stack *a, t_stack *b, t_bench *bench);
void		ft_push_chunks(t_stack *a, t_stack *b, t_bench *bench);
void		ft_chunk_sort(t_stack *a, t_stack *b, t_bench *bench);

double		ft_compute_disorder(t_stack *a);
void		ft_putdouble(double n, int decimals, int fd);
void		ft_adaptive_sort(t_stack *a, t_stack *b, t_bench *bench);

void		ft_print_bench(t_bench *b, t_strategy s, double disorder);

#endif
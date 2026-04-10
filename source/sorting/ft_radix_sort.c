/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 03:03:59 by marvin            #+#    #+#             */
/*   Updated: 2026/04/11 01:37:32 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_push_swap.h"

int	ft_count_bits(int n)
{
	int	bits;

	bits = 0;
	while (n >> bits)
		bits++;
	return (bits);
}

int	ft_is_sorted(t_stack *a)
{
    int n    = ft_stack_size(a);  // n = 5
    int bits = ft_count_bits(n);  // bits = 3 (need 3 bits for 5 elements)
    int bit  = 0;

    while (bit < bits)            // do 3 passes (bit=0, bit=1, bit=2)
    {
        int i = 0;
        while (i < n)             // go through ALL 5 elements
        {
            if ((a->head->index >> bit) & 1)  // check current top's bit
                ft_pb(a, b);      // bit=1 → send to b
            else
                ft_ra(a);         // bit=0 → rotate to bottom
            i++;                  // either way, processed one element
        }
        while (ft_stack_size(b) > 0)
            ft_pa(a, b);          // push everything back from b to a
        bit++;                    // next bit
    }
}


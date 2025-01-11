/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <romain.boland@hotmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:20:20 by rboland           #+#    #+#             */
/*   Updated: 2025/01/11 15:26:20 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void sort_large(t_stack **stack_a, t_stack **stack_b)
{
    int i;
    int j;
    int size;
    int max_bits;
    int num;
    
    size = stack_size(*stack_a);
    index_stack(stack_a);
    max_bits = 0;
    while (((size - 1) >> max_bits) != 0)
        ++max_bits;
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            num = (*stack_a)->index;
            if ((num >> i) & 1)
                rotate_a(stack_a);
            else
                push_b(stack_a, stack_b);
            j++;
        }
        while (*stack_b)
            push_a(stack_a, stack_b);
        i++;
    }
}

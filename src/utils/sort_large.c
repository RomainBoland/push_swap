/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <romain.boland@hotmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:20:20 by rboland           #+#    #+#             */
/*   Updated: 2025/01/13 14:13:21 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/push_swap.h"

// Finds the smallest value in the stack
static t_stack *find_smallest(t_stack *stack)
{
    t_stack *smallest_node;
    long smallest;

    if (!stack)
        return (NULL);
    smallest = LONG_MAX;
    while (stack)
    {
        if (stack->nb < smallest)
        {
            smallest = stack->nb;
            smallest_node = stack;
        }
        stack = stack->next;
    }
    return (smallest_node);
}

// Handle sorting for exactly 5 numbers
static void handle_five(t_stack **a, t_stack **b)
{
    int len_a;
    
    len_a = stack_size(*a);
    while (len_a-- > 3)
    {
        init_nodes(*a, *b);
        push_b(a, b);
    }
    sort_three(a);
    while (*b)
    {
        init_nodes(*a, *b);
        move_nodes(a, b);
    }
}

// Main sorting algorithm for large stacks
void sort_large(t_stack **a, t_stack **b)
{
    t_stack *smallest;
    int len_a;

    len_a = stack_size(*a);
    if (len_a == 5)
    {
        handle_five(a, b);
        return;
    }

    // Push everything except 3 numbers to stack b
    while (len_a > 3)
    {
        push_b(a, b);
        len_a--;
    }

    // Sort the remaining 3 numbers in stack a
    sort_three(a);

    // Start the main sorting process
    while (*b)
    {
        init_nodes(*a, *b);
        move_nodes(a, b);
    }

    // After all numbers are pushed back to a, rotate to put smallest at top
    set_current_position(*a);
    smallest = find_smallest(*a);
    if (smallest->above_medium)
    {
        while (*a != smallest)
            rotate_a(a);
    }
    else
    {
        while (*a != smallest)
            r_rotate_a(a);
    }
}

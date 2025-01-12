/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:20:20 by rboland           #+#    #+#             */
/*   Updated: 2025/01/12 16:50:35 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void push_all_save_three(t_stack **a, t_stack **b)
{
    int size;
    int pushed;
    int mid;

    size = stack_size(*a);
    pushed = 0;
    mid = size / 2;
    
    // Push smaller numbers to B, keeping the 3 largest in A
    while (stack_size(*a) > 3 && pushed < size - 3)
    {
        if ((*a)->index < size - 3)  // Changed condition
        {
            push_b(a, b);
            // Optimize B stack while pushing
            if ((*b)->index < mid && stack_size(*b) > 1)
                rotate_b(b);
            pushed++;
        }
        else
            rotate_a(a);
    }
}

static void set_target_positions(t_stack **a, t_stack **b)
{
    t_stack *tmp_b;

    tmp_b = *b;
    get_position(a);
    get_position(b);
    while (tmp_b)
    {
        tmp_b->target_pos = get_target_pos(a, tmp_b->index);
        tmp_b = tmp_b->next;
    }
}

static void final_rotate(t_stack **a)
{
    int size;
    int min_pos;
    
    size = stack_size(*a);
    get_position(a);
    min_pos = get_min_position(*a);
    
    // Optimize the rotation direction
    if (min_pos <= size / 2)
    {
        while (min_pos > 0)
        {
            rotate_a(a);
            min_pos--;
        }
    }
    else
    {
        while (min_pos < size)
        {
            r_rotate_a(a);
            min_pos++;
        }
    }
}

// Modify sort_large to use the new final_rotate:
void sort_large(t_stack **a, t_stack **b)
{
    index_stack(a);
    push_all_save_three(a, b);
    sort_three(a);
    
    while (*b)
    {
        set_target_positions(a, b);
        get_cost(a, b);
        do_move(a, b, get_cheapest(b)->cost_a, get_cheapest(b)->cost_b);
    }
    
    final_rotate(a);  // Replace the existing rotation logic with this call
}

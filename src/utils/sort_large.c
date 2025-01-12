/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:20:20 by rboland           #+#    #+#             */
/*   Updated: 2025/01/12 16:30:14 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void push_all_save_three(t_stack **a, t_stack **b)
{
    int size;
    int pushed;

    size = stack_size(*a);
    pushed = 0;
    while (stack_size(*a) > 3)
    {
        if ((*a)->index <= size / 2)
        {
            push_b(a, b);
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
    get_position(a);
    while ((*a)->index != 0)
    {
        if (get_min_position(*a) > stack_size(*a) / 2)
            r_rotate_a(a);
        else
            rotate_a(a);
    }
}

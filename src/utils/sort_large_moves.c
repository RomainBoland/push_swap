/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:30:54 by rboland           #+#    #+#             */
/*   Updated: 2025/01/12 16:30:54 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int get_total_cost(int cost_a, int cost_b)
{
    if (cost_a < 0)
        cost_a = -cost_a;
    if (cost_b < 0)
        cost_b = -cost_b;
    return (cost_a + cost_b);
}

t_stack *get_cheapest(t_stack **b)
{
    t_stack *tmp;
    t_stack *cheapest;
    int     min_cost;
    int     cost;

    tmp = *b;
    cheapest = tmp;
    min_cost = get_total_cost(tmp->cost_a, tmp->cost_b);
    while (tmp)
    {
        cost = get_total_cost(tmp->cost_a, tmp->cost_b);
        if (cost < min_cost)
        {
            min_cost = cost;
            cheapest = tmp;
        }
        tmp = tmp->next;
    }
    return (cheapest);
}

static void do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
    while (*cost_a > 0 && *cost_b > 0)
    {
        rotate_r(a, b);
        (*cost_a)--;
        (*cost_b)--;
    }
}

static void do_rev_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
    while (*cost_a < 0 && *cost_b < 0)
    {
        r_rotate_r(a, b);
        (*cost_a)++;
        (*cost_b)++;
    }
}

static void finish_rotation(t_stack **stack, int *cost, char stack_name)
{
    while (*cost)
    {
        if (*cost > 0)
        {
            if (stack_name == 'a')
                rotate_a(stack);
            else
                rotate_b(stack);
            (*cost)--;
        }
        else
        {
            if (stack_name == 'a')
                r_rotate_a(stack);
            else
                r_rotate_b(stack);
            (*cost)++;
        }
    }
}

void do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
    if (cost_a > 0 && cost_b > 0)
        do_rotate_both(a, b, &cost_a, &cost_b);
    else if (cost_a < 0 && cost_b < 0)
        do_rev_rotate_both(a, b, &cost_a, &cost_b);
    finish_rotation(a, &cost_a, 'a');
    finish_rotation(b, &cost_b, 'b');
    push_a(a, b);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:30:34 by rboland           #+#    #+#             */
/*   Updated: 2025/01/12 16:30:34 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void get_position(t_stack **stack)
{
    t_stack *tmp;
    int     i;

    tmp = *stack;
    i = 0;
    while (tmp)
    {
        tmp->pos = i;
        tmp = tmp->next;
        i++;
    }
}

static int find_closest_bigger(t_stack **a, int b_idx)
{
    t_stack *tmp;
    int     target_idx;
    int     target_pos;

    tmp = *a;
    target_idx = INT_MAX;
    target_pos = 0;
    while (tmp)
    {
        if (tmp->index > b_idx && tmp->index < target_idx)
        {
            target_idx = tmp->index;
            target_pos = tmp->pos;
        }
        tmp = tmp->next;
    }
    return (target_idx == INT_MAX ? -1 : target_pos);
}

static int find_smallest_pos(t_stack **a)
{
    t_stack *tmp;
    int     smallest_idx;
    int     smallest_pos;

    tmp = *a;
    smallest_idx = INT_MAX;
    smallest_pos = 0;
    while (tmp)
    {
        if (tmp->index < smallest_idx)
        {
            smallest_idx = tmp->index;
            smallest_pos = tmp->pos;
        }
        tmp = tmp->next;
    }
    return (smallest_pos);
}

int get_target_pos(t_stack **a, int b_idx)
{
    int target_pos;

    target_pos = find_closest_bigger(a, b_idx);
    if (target_pos == -1)
        target_pos = find_smallest_pos(a);
    return (target_pos);
}

static void calculate_stack_cost(int pos, int size, int *cost)
{
    *cost = pos;
    if (pos > size / 2)
        *cost = -(size - pos);
}

void get_cost(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    int     size_a;
    int     size_b;

    tmp = *b;
    size_a = stack_size(*a);
    size_b = stack_size(*b);
    while (tmp)
    {
        calculate_stack_cost(tmp->pos, size_b, &tmp->cost_b);
        calculate_stack_cost(tmp->target_pos, size_a, &tmp->cost_a);
        tmp = tmp->next;
    }
}

static int find_next_min(t_stack *stack, int previous_min)
{
    int     min;
    t_stack *tmp;
    int     found_min;

    tmp = stack;
    found_min = 0;
    min = INT_MAX;
    while (tmp)
    {
        if (tmp->nb < min && tmp->nb > previous_min)
        {
            min = tmp->nb;
            found_min = 1;
        }
        tmp = tmp->next;
    }
    if (!found_min)
        return (INT_MAX);
    return (min);
}

void index_stack(t_stack **stack)
{
    t_stack *tmp;
    int     index;
    int     previous_min;
    int     current_min;

    index = 0;
    previous_min = INT_MIN;
    tmp = *stack;
    while (tmp)
    {
        current_min = find_next_min(*stack, previous_min);
        if (current_min == INT_MAX)
            break;
        tmp = *stack;
        while (tmp)
        {
            if (tmp->nb == current_min)
                tmp->index = index;
            tmp = tmp->next;
        }
        previous_min = current_min;
        index++;
    }
}
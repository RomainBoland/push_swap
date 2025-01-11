/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <romain.boland@hotmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:03:36 by rboland           #+#    #+#             */
/*   Updated: 2025/01/11 10:32:00 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int first;
    int second;
    int third;

    first = (*stack_a)->nb;
    second = (*stack_a)->next->nb;
    third = (*stack_a)->next->next->nb;

    if (first > second && second < third && first < third)
        swap_a(stack_a);
    else if (first > second && second > third)
    {
        swap_a(stack_a);
        r_rotate_a(stack_a);
    }
    else if (first > second && second < third && first > third)
        rotate_a(stack_a);
    else if (first < second && second > third && first < third)
    {
        swap_a(stack_a);
        rotate_a(stack_a);
    }
    else if (first < second && second > third && first > third)
        r_rotate_a(stack_a);
}

void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->nb > (*stack_a)->next->nb)
		swap_a(stack_a);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int size;
	(void) stack_b;

	if (!stack_a || !*stack_a)
		return ;
	size = stack_size(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	if (size == 2)
		sort_two(stack_a);
	if (size == 3)
		sort_three(stack_a);
	// if (size <= 5)
	// 	sort_five(stack_a, stack_b);
	// else
	// 	sort_large(stack_a, stack_b);
}
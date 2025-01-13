/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <romain.boland@hotmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:13:28 by rboland           #+#    #+#             */
/*   Updated: 2025/01/13 15:18:05 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// rotate last element to first place

static void	r_rotate_stack(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev_last = NULL;
	last = *stack;
	while (last->next != NULL)
	{
		prev_last = last;
		last = last->next;
	}
	last->next = *stack;
	*stack = last;
	prev_last->next = NULL;
}

void	r_rotate_a(t_stack **stack_a)
{
	r_rotate_stack(stack_a);
	ft_printf("rra\n");
}

void	r_rotate_b(t_stack **stack_b)
{
	r_rotate_stack(stack_b);
	ft_printf("rrb\n");
}

void	r_rotate_r(t_stack **stack_a, t_stack **stack_b)
{
	r_rotate_stack(stack_a);
	r_rotate_stack(stack_b);
	ft_printf("rrr\n");
}
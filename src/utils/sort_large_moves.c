/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:39:08 by rboland           #+#    #+#             */
/*   Updated: 2025/01/13 20:39:08 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
	{
		rotate_r(a, b);
	}
	set_current_position(*a);
	set_current_position(*b);
}

static void	reverse_rotate_both(t_stack **a, t_stack **b,
		t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
	{
		r_rotate_r(a, b);
	}
	set_current_position(*a);
	set_current_position(*b);
}

void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_medium)
				rotate_a(stack);
			else
				r_rotate_a(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_medium)
				rotate_b(stack);
			else
				r_rotate_b(stack);
		}
	}
}

t_stack	*get_cheapest_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest_node(*b);
	if (cheapest_node->above_medium
		&& cheapest_node->target_node->above_medium)
		rotate_both(a, b, cheapest_node);
	else if (!cheapest_node->above_medium
		&& !cheapest_node->target_node->above_medium)
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	push_a(a, b);
}

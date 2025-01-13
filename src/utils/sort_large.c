/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:20:20 by rboland           #+#    #+#             */
/*   Updated: 2025/01/13 20:38:59 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*smallest_node;
	long	smallest;

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

static void	handle_five(t_stack **a, t_stack **b)
{
	int	len_a;

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

static void	sort_initial_large(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_size(*a);
	if (len_a == 5)
	{
		handle_five(a, b);
		return ;
	}
	while (len_a > 3)
	{
		push_b(a, b);
		len_a--;
	}
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
}

static void	position_smallest(t_stack **a)
{
	t_stack	*smallest;

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

void	sort_large(t_stack **a, t_stack **b)
{
	sort_initial_large(a, b);
	position_smallest(a);
}

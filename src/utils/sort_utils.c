/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:58:21 by rboland           #+#    #+#             */
/*   Updated: 2025/01/13 20:43:58 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (b)
	{
		b->push_price = b->current_pos;
		if (!b->above_medium)
			b->push_price = len_b - b->current_pos;
		if (b->target_node->above_medium)
			b->push_price += b->target_node->current_pos;
		else
			b->push_price += len_a - b->target_node->current_pos;
		b = b->next;
	}
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_min_position(t_stack *stack)
{
	int		min;
	int		pos;
	int		min_pos;
	t_stack	*current;

	if (!stack)
		return (-1);
	min = stack->nb;
	pos = 0;
	min_pos = 0;
	current = stack;
	while (current)
	{
		if (current->nb < min)
		{
			min = current->nb;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

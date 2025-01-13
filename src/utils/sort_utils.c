/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <romain.boland@hotmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:58:21 by rboland           #+#    #+#             */
/*   Updated: 2025/01/13 15:23:12 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
	int     min;
	int     pos;
	int     min_pos;
	t_stack *current;

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

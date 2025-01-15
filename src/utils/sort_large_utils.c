/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <romain.boland@hotmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:20:55 by rboland           #+#    #+#             */
/*   Updated: 2025/01/13 15:20:55 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*	initialize for each element of a stack
*	the current_pos in the stack and
*	a bool to know if it is above or below
*	the median
*/

void	set_current_position(t_stack *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (!stack)
		return ;
	centerline = stack_size(stack) / 2;
	while (stack)
	{
		stack->current_pos = i;
		stack->above_medium = (i <= centerline);
		stack = stack->next;
		i++;
	}
}

/*	Parse entire stack a to find the best_match for 
*	a given b node. The best match is the closest bigger nb
*/

static t_stack	*find_target_match(
		t_stack *a, t_stack *b, long *best_match_index)
{
	t_stack	*current_a;
	t_stack	*target_node;

	*best_match_index = LONG_MAX;
	current_a = a;
	while (current_a)
	{
		if (current_a->nb > b->nb && current_a->nb < *best_match_index)
		{
			*best_match_index = current_a->nb;
			target_node = current_a;
		}
		current_a = current_a->next;
	}
	return (target_node);
}

/*	Goes through each element in b and find the target node in a
*	First calls find_target_match() for a potential closest bigger
*	if none is found it means that b->nb is bigger than each a->nb.
*	It then search for the smallest a->nb wich will be the target_node
*/

static void	set_target_node(t_stack *a, t_stack *b)
{
	long	best_match_index;
	t_stack	*target_node;
	t_stack	*current_a;

	while (b)
	{
		target_node = find_target_match(a, b, &best_match_index);
		if (best_match_index == LONG_MAX)
		{
			b->target_node = a;
			current_a = a->next;
			while (current_a)
			{
				if (current_a->nb < b->target_node->nb)
					b->target_node = current_a;
				current_a = current_a->next;
			}
		}
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_cheapest(t_stack *b)
{
	t_stack	*current;
	long	min_price;

	if (!b)
		return ;
	current = b;
	min_price = LONG_MAX;
	while (current)
	{
		current->cheapest = false;
		if (current->push_price < min_price)
			min_price = current->push_price;
		current = current->next;
	}
	current = b;
	while (current)
	{
		if (current->push_price == min_price)
		{
			current->cheapest = true;
			break ;
		}
		current = current->next;
	}
}

void	init_nodes(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}

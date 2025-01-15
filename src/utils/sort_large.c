/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:20:20 by rboland           #+#    #+#             */
/*   Updated: 2025/01/15 11:43:14 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*	Simpple function to find the smallest 
*	nb variable in an entire stack, returns
*	a pointer to the node
*/

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

/*	Send all elements of stack a but 3
*	Sort the 3 remaining in stack a
*	Calls init_nodes and move an element with
*	move_nodes until nothing is left in 
*	stack b
*/

static void	sort_initial_large(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_size(*a);
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

/*	Since everything should be sorted at this point
*	We take note of every node's position and then
*	find the smallest and rotate it to the top
*/

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

/*	Calls main sorting function, sort_initial_large()
*	to sort the tab and position_smallest to rotate the 
*	smallest to the top
*/

void	sort_large(t_stack **a, t_stack **b)
{
	sort_initial_large(a, b);
	position_smallest(a);
}

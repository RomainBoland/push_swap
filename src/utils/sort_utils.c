/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <romain.boland@hotmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:58:21 by rboland           #+#    #+#             */
/*   Updated: 2025/01/11 15:21:53 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Get the maximum number in the stack
int get_max(t_stack *stack)
{
    int max;
    
    if (!stack)
        return (0);
    max = stack->nb;
    while (stack)
    {
        if (stack->nb > max)
            max = stack->nb;
        stack = stack->next;
    }
    return (max);
}

void index_stack(t_stack **stack)
{
    t_stack *current;
    t_stack *compare;
    int index;
    
    current = *stack;
    while (current)
    {
        index = 0;
        compare = *stack;
        while (compare)
        {
            if (compare->nb < current->nb)
                index++;
            compare = compare->next;
        }
        current->index = index;
        current = current->next;
    }
}

// returns the size of the stack

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
// returns 1 if sorted, 0 if not

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

// search for the smallest nb of the stack and returns a counter to his position

int get_min_position(t_stack *stack)
{
    int min;
    int pos;
    int min_pos;
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
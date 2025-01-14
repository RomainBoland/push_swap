/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <romain.boland@hotmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:17:31 by rboland           #+#    #+#             */
/*   Updated: 2025/01/14 13:08:13 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// search for the last node of a linked list and returns a pointer to it

t_stack	*stack_last(t_stack *stack)

{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

// adds a new node to the end of a linked list

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (stack == NULL || new == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = stack_last(*stack);
	last->next = new;
}

// Create a new node

t_stack	*stack_new_node(int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

int	check_duplicates(t_stack **stack)
{
	t_stack	*current;
	t_stack	*check;

	current = *stack;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->nb == check->nb)
				return (0);
			check = check->next;
		}
		current = current->next;
	}
	return (1);
}

// checks if args are correct and if so declare and initialize a stack list

int	stack_init(t_stack **stack_a, char **av)
{
	int		i;
	t_stack	*new_node;
	long	nb;

	i = 0;
	if (!input_checker(av))
		return (0);
	while (av[i])
	{
		nb = atoi_push_swap(av[i]);
		new_node = stack_new_node((int)nb);
		if (!new_node)
			return (0);
		if (*stack_a)
			stack_add_back(stack_a, new_node);
		else
			*stack_a = new_node;
		i++;
	}
	if (!check_duplicates(stack_a))
	{
		free_stack(stack_a);
		return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <romain.boland@hotmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:52:35 by rboland           #+#    #+#             */
/*   Updated: 2025/01/13 15:18:02 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
* Fonction generique pour rotate le premier element vers la fin de la pile
*/

static void	rotate_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*new_first;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	new_first = (*stack)->next;
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack)->next = NULL;
	*stack = new_first;
}

void	rotate_a(t_stack **stack_a)
{
	rotate_stack(stack_a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack **stack_b)
{
	rotate_stack(stack_b);
	ft_printf("rb\n");
}

void	rotate_r(t_stack **stack_a, t_stack **stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	ft_printf("rr\n");
}

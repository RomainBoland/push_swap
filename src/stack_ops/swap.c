/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <romain.boland@hotmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:49:47 by rboland           #+#    #+#             */
/*   Updated: 2025/01/10 13:01:52 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
* Fonction generique pour inverser les 2 premiers elements d une pile
*/
static void	stackswap(t_stack **stack)
{
	t_stack *tmp;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	swap_a(t_stack **stack_a)
{
	stackswap(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b)
{
	stackswap(stack_b);
	ft_printf("sb\n");
}

void	swap_s(t_stack **stack_a, t_stack **stack_b)
{
	stackswap(stack_a);
	stackswap(stack_b);
	ft_printf("ss\n");
}

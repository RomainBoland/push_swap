/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <romain.boland@hotmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:17:31 by rboland           #+#    #+#             */
/*   Updated: 2025/01/08 15:45:04 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	atoi_pushswap(const char *str)
{
	int	i;
	int	result;
	int	signe;

	result = 0;
	signe = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * signe);
}

int	stack_init(t_stack **stack_a, char **av)
{
	int		i;
	t_stack	*new_node;
	int		nb;

	i = 0;
	if (input_checker() == -1)
	{
		print_error();
		return ;
	}
	// while (av[i] != NULL)
	// {
	// 	nb = atoi_pushswap(av[i]);
	// 	new_node = stack_new_node(nb);
	// 	stack_add_back(stack_a, new_node);
	// 	i++;
	// }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_formater.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <romain.boland@hotmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:20:13 by rboland           #+#    #+#             */
/*   Updated: 2025/01/13 15:20:13 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	input_formater(int argc, char **argv, t_stack **stack_a)
{
	char	**av;

	if (argc == 2)
	{
		av = ft_split(argv[1], ' ');
		if (!stack_init(stack_a, av))
			return (0);
		free_tab(av);
	}
	else
	{
		av = argv + 1;
		if (!stack_init(stack_a, av))
			return (0);
	}
	return (1);
}

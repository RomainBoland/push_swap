/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_formater.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:29:29 by rboland           #+#    #+#             */
/*   Updated: 2025/01/09 20:29:29 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Format the 2 possibilities of args into a tab to make it easier to handle

void	input_format(int argc, char **argv, t_stack *stack_a)
{
	char	**av;

	if (argc == 2)
	{
		av = ft_split(argv[1], ' '); 
		stack_init(&stack_a, av);
		free_tab(av); // must be free bc split malloc the tab
	}
	else
	{
		av = argv + 1; // Dans le cas d un tableau ou les differents elements sont deja separer
		stack_init(&stack_a, av);
	}
}
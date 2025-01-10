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

#include "../../includes/push_swap.h"

// Format the 2 possibilities of args into a tab to make it easier to handle

int	input_formater(int argc, char **argv, t_stack **stack_a)
{
	char	**av;

	if (argc == 2)
	{
		av = ft_split(argv[1], ' '); 
		if (!stack_init(stack_a, av))
			return (0);
		free_tab(av); // must be free bc split malloc the tab
	}
	else
	{
		av = argv + 1; // Dans le cas d un tableau ou les differents elements sont deja separer
		if (!stack_init(stack_a, av))
			return (0);
	}
	return (1);
}
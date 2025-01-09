/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <romain.boland@hotmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 21:23:19 by rboland           #+#    #+#             */
/*   Updated: 2025/01/08 15:49:15 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**av;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || argv[1][0] == NULL)
		return (0);
	if (argc == 2)
	{
		av = ft_split(argv[1], ' '); // Dans le cas d une longue chaine remplie de chiffre
		stack_init(&stack_a, av);
		free_tab(av);
	}
	else
	{
		av = argv + 1; // Dans le cas d un tableau ou les differents elements sont deja separer
		stack_init(&stack_a, av);
	}
	sort_stack();
	free_stack(stack_a);
	return (0);
}

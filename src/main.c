/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <romain.boland@hotmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 21:23:19 by rboland           #+#    #+#             */
/*   Updated: 2025/01/10 11:26:33 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || argv[1][0] == NULL)
		return (0);
	if (input_formater(argc, argv, stack_a))
	{
		print_error();
		return (0);
	} // format one long string of args into multiple args and calls stack_init
	sort_stack();
	free_stack(stack_a);
	return (0);
}

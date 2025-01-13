/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <romain.boland@hotmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 21:23:19 by rboland           #+#    #+#             */
/*   Updated: 2025/01/13 15:17:11 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// static void    print_stack(t_stack **stack_a)
// {
//     int i = 0;
//     t_stack *current = NULL;
//     current = *stack_a;
//     while (current)
//     {
//         ft_printf("Stack (%d)->nb = %d\n", i, current->nb);
//         i++;
//         current = current->next;
//     }
// }

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || argv[1][0] == '\0')
		return (0);
	if (!input_formater(argc, argv, &stack_a))
	// Pass address of stack_a pointer
	{
		print_error();
		return (1);
	}
	sort_stack(&stack_a, &stack_b); // Pass both stacks
	// print_stack(&stack_a);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

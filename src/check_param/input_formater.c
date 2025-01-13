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

static int parse_argv(char **argv)
{
    int i;
    int j;

    i = 0;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] == '"' || argv[i][j] == '\'')
                return (0);  // No quotes allowed in multi-argument mode
            j++;
        }
        i++;
    }
    return (1);
}

int input_formater(int argc, char **argv, t_stack **stack_a)
{
    char **av;

    if (argc == 2)  // Single argument case - quotes allowed
    {
        av = ft_split(argv[1], ' ');
        if (!stack_init(stack_a, av))
            return (0);
        free_tab(av);
    }
    else  // Multiple arguments case - no quotes allowed
    {
        if (!parse_argv(argv + 1))
            return (0);  // Error if quotes found in multi-arg mode
        av = argv + 1;
        if (!stack_init(stack_a, av))
            return (0);
    }
    return (1);
}

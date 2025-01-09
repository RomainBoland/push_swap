/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <romain.boland@hotmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:51:12 by rboland           #+#    #+#             */
/*   Updated: 2025/01/08 16:01:12 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_correct_format(char *str)
{
	
}

int	finds_double(char *str)
{
	
}

int	is_integer(char *str)
{
	
}

int	is_valid_number(char *str)
{
	if (!is_integer(str) || finds_double(str))
		return (0);
	
}

int	input_checker(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (!is_valid_number(tab[i]) || )
		{
			print_error();
			return (0);
		}
		i++;
	}
	return (1);
}

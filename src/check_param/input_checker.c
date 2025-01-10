/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <romain.boland@hotmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:51:12 by rboland           #+#    #+#             */
/*   Updated: 2025/01/10 13:01:13 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// return 0 if more than one + or - is found, or if anything else than 
// a number is found

int	is_valid(char	*str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)) // skip tab and space, there shouldnt be more than one bc split but you never know
		i++;
	if (str[i] == '-' || str[i] == '+') // skip only one + or - since more than one should be an Error
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_integer(long nb)
{
	if (nb >= -2147483648 && nb <= 2147483647)
		return (1);
	else
		return (0);
}

int	atoi_push_swap(const char *str)
{
	int		i;
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	result = result * sign;
	return (result);
}

int	input_checker(char **tab)
{
	long	nb;
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (!is_valid(tab[i]))
			return (0);
		nb = atoi_push_swap(tab[i]);
		if (!is_integer(nb))
			return (0);
		i++;
	}
	return (1);
}

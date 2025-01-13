/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <romain.boland@hotmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:51:12 by rboland           #+#    #+#             */
/*   Updated: 2025/01/13 15:19:06 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// return 0 if more than one + or - is found, or if anything else than
// a number is found

static int	is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
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

static int	check_overflow(long result, char next_digit, int sign)
{
	if (result > 214748364)
		return (1);
	if (result == 214748364)
	{
		if (sign == 1 && (next_digit - '0') > 7)
			return (1);
		if (sign == -1 && (next_digit - '0') > 8)
			return (1);
	}
	return (0);
}

static long	get_overflow_value(int sign)
{
	if (sign == 1)
		return (2147483648);
	return (-2147483649);
}

long	atoi_push_swap(const char *str)
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
		if (check_overflow(result, str[i], sign))
			return (get_overflow_value(sign));
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
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
		if (nb < -2147483648 || nb > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:24:17 by rboland           #+#    #+#             */
/*   Updated: 2024/10/28 10:24:17 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	ft_put_str(char *str);
int	ft_put_int(int nbr);
int	ft_put_unsigned(unsigned int nbr);
int	ft_put_ptr(void *ptr);
int	ft_put_hexa(unsigned int nbr, int upper_case);

#endif
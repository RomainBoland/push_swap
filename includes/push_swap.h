/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <romain.boland@hotmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:53:01 by rboland           #+#    #+#             */
/*   Updated: 2025/01/08 15:57:24 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
} t_stack;

/*
* =============================================================================
* utils
* -----------------------------------------------------------------------------
*/
void	free_stack(t_stack **stack);
void	free_tab(char **tab);
t_stack	*stack_last(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*stack_new_node(int nb);
int	atoi_pushswap(const char *str);
int	stack_init(t_stack **stack_a, char **a);
int	is_valid_number(char *str);
int	is_integer(char *str);
int	finds_double(char *str);

/*
* =============================================================================
* error
* -----------------------------------------------------------------------------
*/
void	print_error(void);
/* 
* =============================================================================
* stack operations
* -----------------------------------------------------------------------------
*/
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_s(t_stack **stack_a, t_stack **stack_b);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_r(t_stack **stack_a, t_stack **stack_b);
void	r_rotate_a(t_stack **stack_a);
void	r_rotate_b(t_stack **stack_b);
void	r_rotate_r(t_stack **stack_a, t_stack **stack_b);

#endif
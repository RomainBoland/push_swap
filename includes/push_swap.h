/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <romain.boland@hotmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:53:01 by rboland           #+#    #+#             */
/*   Updated: 2025/01/10 11:46:27 by rboland          ###   ########.fr       */
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

// check_param
int	is_valid(char	*str);
int	is_integer(long nb);
int	atoi_push_swap(const char *str);
int	input_checker(char **tab);
int	input_format(int argc, char **argv, t_stack *stack_a);

// utils 
void	free_stack(t_stack **stack);
void	free_tab(char **tab);
t_stack	*stack_last(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*stack_new_node(int nb);
int	stack_init(t_stack **stack_a, char **av);

// stack operations
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
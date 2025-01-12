/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:53:01 by rboland           #+#    #+#             */
/*   Updated: 2025/01/12 16:26:08 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct s_stack
{
    int             nb;
    int             index;      // for final sorted position
    int             pos;        // current position in stack
    int             target_pos; // where it needs to go
    int             cost_a;     
    int             cost_b;
    struct s_stack  *next;
} t_stack;

// check_param
long	atoi_push_swap(const char *str);
int		input_checker(char **tab);
int		input_formater(int argc, char **argv, t_stack **stack_a);

// print_error.c
void	print_error(void);

// stack_init.c
t_stack	*stack_last(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*stack_new_node(int nb);
int 	check_duplicates(t_stack **stack);
int		stack_init(t_stack **stack_a, char **av);

// free.c
void	free_stack(t_stack **stack);
void	free_tab(char **tab);

// sort_utils.c
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);
int 	get_min_position(t_stack *stack);

// sort.c
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_two(t_stack **stack_a);
void	sort_three(t_stack **stack_a);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);

// sort_large_moves.c
t_stack *get_cheapest(t_stack **b);
void do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

// sort_large_utils.c
void get_position(t_stack **stack);
int get_target_pos(t_stack **a, int b_idx);
void get_cost(t_stack **a, t_stack **b);
void index_stack(t_stack **stack);

// sort_large.c
void 	sort_large(t_stack **stack_a, t_stack **stack_b);

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
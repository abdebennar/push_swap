/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:57:16 by abennar           #+#    #+#             */
/*   Updated: 2024/01/27 15:12:28 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				node_pos;
	int				cost_a;
	int				cost_b;
	int				trgt_pos;
	struct s_stack	*next;
}				t_stack;

void	null_check(char **argv);
void	space_check(char **argv);
void	err_exit(char **args);
void	tiny_sort(t_stack **stack);
void	sort_args(t_stack **stack_a, t_stack **stack_b);
void	my_free(void	*mem);

void	check_args(char **args);
void	sort_args(t_stack **stack_a, t_stack **stack_b);
void	stack_index(t_stack *stack);

t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int value);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
void	ft_lstclear(t_stack **lst);

bool	is_sorted(t_stack *stack_a);
void	stack_pos(t_stack *stack);
long	ft_atol(const char *s);

void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);

void	rrr_loop(t_stack **stack_a, t_stack **stack_b,
			int *cost_a, int *cost_b);
void	rr_loop(t_stack **stack_a, t_stack **stack_b,
			int *cost_a, int *cost_b);
void	a_cost(t_stack **stack_a, int *cost_a);
void	b_cost(t_stack **stack_b, int *cost_b);
void	target_pos(t_stack *stack_a, t_stack *stack_b);
void	shift_stack(t_stack **stack_a);
int		ft_abs(int nb);

#endif
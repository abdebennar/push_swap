/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:38:59 by abennar           #+#    #+#             */
/*   Updated: 2024/01/27 15:12:08 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

void	space_check(char **argv);
void	null_check(char **argv);
void	err_exit(char **args);
void	my_free(void	*mem);
void	creat_stack(char **args, t_stack **stack_a);
void	check_args(char **args);
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	rrb(t_stack **stack_b);
void	rra(t_stack **stack_a);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	sb(t_stack **stack_b);
void	sa(t_stack **stack_a);
long	ft_atol(const char *s);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int value);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
bool	is_sorted(t_stack *stack_a);
void	error(t_stack **stack_a, t_stack **stack_b);
void	last_steep(t_stack **stack_a, t_stack **stack_b, char **args, int size);
void	error(t_stack **stack_a, t_stack **stack_b);

#endif
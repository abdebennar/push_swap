/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:49:34 by abennar           #+#    #+#             */
/*   Updated: 2024/01/25 17:12:13 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	shift(t_stack **stack)
{
	t_stack	*last;
	t_stack	*tmp;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = (*stack)->next;
		last = ft_lstlast(*stack);
		last->next = (*stack);
		(*stack)->next = NULL;
		(*stack) = tmp;
	}
}

void	ra(t_stack **stack_a)
{
	shift(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	shift(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	shift(stack_a);
	shift(stack_b);
	ft_printf("rr\n");
}

void	rr_loop(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(stack_a, stack_b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cmd_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:49:34 by abennar           #+#    #+#             */
/*   Updated: 2024/01/22 20:07:41 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
}

void	rb(t_stack **stack_b)
{
	shift(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	shift(stack_a);
	shift(stack_b);
}

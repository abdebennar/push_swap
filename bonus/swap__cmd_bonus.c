/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap__cmd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:41:13 by abennar           #+#    #+#             */
/*   Updated: 2024/01/17 20:14:08 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	swap(t_stack **stack)
{
	t_stack		*tmp;

	if ((*stack) && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = (*stack);
		(*stack) = tmp;
	}
}

void	sa(t_stack **stack_a)
{
	if (*stack_a && (*stack_a)->next)
		swap(stack_a);
}

void	sb(t_stack **stack_b)
{
	if (*stack_b && (*stack_b)->next)
		swap(stack_b);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sa(stack_b);
}

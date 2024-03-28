/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap__cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:41:13 by abennar           #+#    #+#             */
/*   Updated: 2024/01/17 15:16:59 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	{
		swap(stack_a);
		ft_printf("sa\n");
	}
}

void	sb(t_stack **stack_b)
{
	if (*stack_b && (*stack_b)->next)
	{
		swap(stack_b);
		ft_printf("sb\n");
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sa(stack_b);
	ft_printf("sa\n");
}

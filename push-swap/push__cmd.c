/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push__cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:25:27 by abennar           #+#    #+#             */
/*   Updated: 2024/01/17 15:19:19 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (*src)
	{
		tmp = *src;
		(*src) = (*src)->next;
		ft_lstadd_front(&(*dst), tmp);
	}
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	if (*stack_b)
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a)
	{
		push(stack_a, stack_b);
		ft_printf("pb\n");
	}
}

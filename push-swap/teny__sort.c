/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teny__sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 20:27:17 by abennar           #+#    #+#             */
/*   Updated: 2024/01/14 17:31:20 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	high_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	tiny_sort(t_stack **stack)
{
	int		index;

	index = high_index(*stack);
	if ((*stack)->index == index)
	{
		ra(stack);
	}
	else if ((*stack)->next->index == index)
	{
		rra(stack);
	}
	if ((*stack)->value > (*stack)->next->value)
	{
		sa(stack);
	}
}

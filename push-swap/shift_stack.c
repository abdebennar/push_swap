/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:20:09 by abennar           #+#    #+#             */
/*   Updated: 2024/01/14 17:28:42 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	small_pos(t_stack *stack_a)
{
	int		index;
	int		pos;

	index = INT_MAX;
	pos = 0;
	while (stack_a)
	{
		if (stack_a->index < index)
		{
			index = stack_a->index;
			pos = stack_a->node_pos;
		}
		stack_a = stack_a->next;
	}
	return (pos);
}

void	shift_stack(t_stack **stack_a)
{
	int	pos;

	stack_pos(*stack_a);
	pos = small_pos(*stack_a);
	if (pos > (ft_lstsize(*stack_a) / 2))
	{
		while (!is_sorted(*stack_a))
			rra(stack_a);
	}
	else
		while (!is_sorted(*stack_a))
			ra(stack_a);
}

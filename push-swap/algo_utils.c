/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:51:28 by abennar           #+#    #+#             */
/*   Updated: 2024/01/14 17:05:15 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_index(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*max_n;
	int		max_v;
	int		index;

	index = ft_lstsize(stack);
	while (index)
	{
		max_v = INT_MIN;
		tmp = stack;
		while (tmp)
		{
			if (tmp->value > max_v && tmp->index == 0)
			{
				max_v = tmp->value;
				max_n = tmp;
				tmp = stack;
			}
			else
				tmp = tmp->next;
		}
		max_n->index = index;
		index--;
	}
}

static int	get_target(t_stack	*stack_a, int b_index,
						int min_index, int trgt_pos)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		if (tmp->index > b_index && tmp->index < min_index)
		{
			trgt_pos = tmp->node_pos;
			min_index = tmp->index;
		}
		tmp = tmp->next;
	}
	if (min_index != INT_MAX)
		return (trgt_pos);
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			trgt_pos = tmp->node_pos;
		}
		tmp = tmp->next;
	}
	return (trgt_pos);
}

void	target_pos(t_stack *stack_a, t_stack *stack_b)
{
	int	trgt_pos;

	trgt_pos = 0;
	stack_pos(stack_a);
	stack_pos(stack_b);
	while (stack_b)
	{
		trgt_pos = get_target(stack_a, stack_b->index, INT_MAX, 0);
		stack_b->trgt_pos = trgt_pos;
		stack_b = stack_b->next;
	}
}

void	a_cost(t_stack **stack_a, int *cost_a)
{
	while (*cost_a < 0)
	{
		rra(stack_a);
		(*cost_a)++;
	}
	while (*cost_a > 0)
	{
		ra(stack_a);
		(*cost_a)--;
	}
}

void	b_cost(t_stack **stack_b, int *cost_b)
{
	while (*cost_b < 0)
	{
		rrb(stack_b);
		(*cost_b)++;
	}
	while (*cost_b > 0)
	{
		rb(stack_b);
		(*cost_b)--;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort__algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:09:42 by abennar           #+#    #+#             */
/*   Updated: 2024/01/23 20:33:52 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	tiny_stack(t_stack **stack_a, t_stack **stack_b)
{
	int		pushed;
	int		i;
	int		size;

	pushed = 0;
	i = 0;
	size = ft_lstsize(*stack_a);
	while ((size - pushed) > 3 && i < size && size > 5)
	{
		if ((*stack_a)->index <= ft_lstsize(*stack_a) / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while ((size - pushed) > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

static void	cont_moves(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	while (stack_b)
	{
		(stack_b)->cost_b = (stack_b)->node_pos;
		if (stack_b->node_pos > size_b / 2)
			stack_b->cost_b = (size_b - (stack_b)->node_pos) * -1;
		(stack_b)->cost_a = (stack_b)->trgt_pos;
		if (stack_b->trgt_pos > size_a / 2)
			stack_b->cost_a = (size_a - (stack_b)->trgt_pos) * -1;
		stack_b = stack_b->next;
	}
}

static void	do_moves(t_stack **stack_a, t_stack **stack_b)
{
	int		s_cost;
	int		cost_a;
	int		cost_b;
	t_stack	*tmp;

	s_cost = INT_MAX;
	tmp = (*stack_b);
	while (tmp)
	{
		if (ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b) < s_cost)
		{
			s_cost = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	if (cost_a < 0 && cost_b < 0)
		rrr_loop(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rr_loop(stack_a, stack_b, &cost_a, &cost_b);
	a_cost(stack_a, &cost_a);
	b_cost(stack_b, &cost_b);
	pa(stack_b, stack_a);
}

static void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	tiny_stack(stack_a, stack_b);
	tiny_sort(stack_a);
	while (*stack_b)
	{
		target_pos(*stack_a, *stack_b);
		cont_moves(*stack_a, *stack_b);
		do_moves(stack_a, stack_b);
	}
	while (!is_sorted(*stack_a))
		shift_stack(stack_a);
}

void	sort_args(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	stack_index(*stack_a);
	if (ft_lstsize(*stack_a) == 2)
	{
		if (!is_sorted(*stack_a))
			ra(stack_a);
	}
	else if (ft_lstsize(*stack_a) == 3)
		tiny_sort(stack_a);
	else
		sort(stack_a, stack_b);
}

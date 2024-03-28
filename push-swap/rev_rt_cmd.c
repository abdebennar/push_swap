/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rt_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:53:23 by abennar           #+#    #+#             */
/*   Updated: 2024/01/22 20:13:00 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_shift(t_stack **stack)
{
	t_stack	*last;
	t_stack	*head;

	if (ft_lstsize(*stack) > 1)
	{
		head = (*stack);
		last = ft_lstlast(*stack);
		while (head)
		{
			if (head->next->next == NULL)
			{
				head->next = NULL;
				break ;
			}
			head = head->next;
		}
		last->next = (*stack);
		(*stack) = last;
	}
}

void	rra(t_stack **stack_a)
{
	rev_shift(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	rev_shift(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_shift(stack_a);
	rev_shift(stack_b);
	ft_printf("rrr\n");
}

void	rrr_loop(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(stack_a, stack_b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

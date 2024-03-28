/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rt_cmd_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:53:23 by abennar           #+#    #+#             */
/*   Updated: 2024/01/22 20:06:48 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	if (ft_lstsize(*stack_a) > 1)
		rev_shift(stack_a);
}

void	rrb(t_stack **stack_b)
{
	if (ft_lstsize(*stack_b) > 1)
		rev_shift(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_shift(stack_a);
	rev_shift(stack_b);
}

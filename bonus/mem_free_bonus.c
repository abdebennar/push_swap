/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_free_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 01:19:48 by abennar           #+#    #+#             */
/*   Updated: 2024/01/22 07:20:15 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*current;
	t_stack	*tmp;

	if (!lst)
		return ;
	current = *lst;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*lst = NULL;
}

void	error(t_stack **stack_a, t_stack **stack_b)
{
	ft_putendl_fd("Error", 2);
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	exit(1);
}

void	last_steep(t_stack **stack_a, t_stack **stack_b, char **args, int size)
{
	if (is_sorted(*stack_a) && size == ft_lstsize(*stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(args);
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
}

void	my_free(void	*mem)
{
	if (mem)
		free(mem);
}

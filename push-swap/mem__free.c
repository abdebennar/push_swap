/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem__free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:20:55 by abennar           #+#    #+#             */
/*   Updated: 2024/01/20 21:34:59 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	my_free(void	*mem)
{
	if (mem)
		free(mem);
}

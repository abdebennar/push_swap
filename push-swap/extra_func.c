/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:37:30 by abennar           #+#    #+#             */
/*   Updated: 2024/01/18 16:20:10 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*skp(const char *str, int *sign)
{
	*sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		*sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str == '0')
		str++;
	return (str);
}

long	ft_atol(const char *s)
{
	int				sign;
	long long		number;

	number = 0;
	s = skp(s, &sign);
	while (*s >= '0' && *s <= '9')
	{
		number = number * 10 + *s - '0';
		s++;
	}
	return ((long)(sign * number));
}

void	stack_pos(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->node_pos = i;
		stack = stack->next;
		i++;
	}
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

bool	is_sorted(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->value > stack_a->next->value)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

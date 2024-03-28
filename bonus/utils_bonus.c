/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:50:52 by abennar           #+#    #+#             */
/*   Updated: 2024/01/22 20:08:39 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	creat_stack(char **args, t_stack **stack_a)
{
	t_stack	*tmp;
	char	*t;

	while (*args)
	{
		tmp = ft_lstnew(ft_atoi(*args));
		if (!tmp)
			error(stack_a, NULL);
		ft_lstadd_back(stack_a, tmp);
		t = *args;
		args++;
		free(t);
	}
	args = NULL;
}

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

bool	is_sorted(t_stack *stack_a)
{
	if (stack_a)
	{
		while (stack_a->next != NULL)
		{
			if (stack_a->value > stack_a->next->value)
				return (false);
			stack_a = stack_a->next;
		}
	}
	return (true);
}

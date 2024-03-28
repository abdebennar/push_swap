/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:06:37 by abennar           #+#    #+#             */
/*   Updated: 2024/01/22 20:06:06 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_isvalid(int c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == '+')
		return (1);
	else
		return (0);
}

void	err_exit(char **args)
{
	char	*tmp;

	if (args && *args)
	{
		while (*args)
		{
			tmp = *args;
			args++;
			free(tmp);
		}
	}
	ft_putendl_fd("Error", 2);
	exit(1);
}

static void	non_duplicates(char **args)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		j = i + 1;
		while (args[j])
		{
			if (tmp == ft_atoi(args[j]))
				err_exit(args);
			j++;
		}
		i++;
	}
}

static void	non_int(char **args)
{
	long	tmp;

	while (*args)
	{
		tmp = ft_atol(*args);
		if (tmp > INT_MAX || tmp < INT_MIN)
			err_exit(args);
		args++;
	}
}

void	check_args(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (!ft_isvalid(args[i][j]))
				err_exit(args);
			if (args[i][j] == '-' || args[i][j] == '+')
				if (!ft_isdigit(args[i][j + 1])
				|| (args[i][j - 1] != ' ' && j != 0))
					err_exit(args);
			j++;
		}
		i++;
	}
	non_int(args);
	non_duplicates(args);
}

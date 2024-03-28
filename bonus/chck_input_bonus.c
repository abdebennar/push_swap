/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_input_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:04:29 by abennar           #+#    #+#             */
/*   Updated: 2024/01/22 20:04:07 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	space_check(char **argv)
{
	int	i;
	int	j;
	int	t;

	i = 1;
	j = 0;
	t = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				break ;
			if (argv[i][j] == ' ')
				t++;
			j++;
		}
		if (ft_strlen(argv[i]) == (size_t)t)
		{
			err_exit(NULL);
		}
		i++;
	}
}

void	null_check(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
		{
			err_exit(NULL);
		}
		i++;
	}
}

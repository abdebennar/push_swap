/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:18:59 by abennar           #+#    #+#             */
/*   Updated: 2024/01/22 18:03:23 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	my_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

static char	*join(char **args, char *str)
{
	char	*tmp;
	int		j;

	tmp = NULL;
	j = 0;
	while (args[j])
	{
		tmp = str;
		str = ft_strjoin(str, args[j]);
		my_free(tmp);
		tmp = str;
		str = ft_strjoin(str, " ");
		my_free(args[j]);
		my_free(tmp);
		j++;
	}
	return (str);
}

static char	**cnv_args(char **argv)
{
	char	**args;
	char	*str;
	int		i;

	i = 1;
	str = NULL;
	while (argv[i])
	{
		args = ft_split(argv[i], ' ');
		str = join(args, str);
		my_free(args);
		i++;
	}
	args = ft_split(str, ' ');
	my_free(str);
	return (args);
}

void	exc_cmd(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (my_strcmp(line, "sa\n") == 0)
		sa(stack_a);
	else if (my_strcmp(line, "sb\n") == 0)
		sb(stack_b);
	else if (my_strcmp(line, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (my_strcmp(line, "pa\n") == 0)
		pa(stack_b, stack_a);
	else if (my_strcmp(line, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (my_strcmp(line, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (my_strcmp(line, "rb\n") == 0)
		rb(stack_b);
	else if (my_strcmp(line, "ra\n") == 0)
		ra(stack_a);
	else if (my_strcmp(line, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else if (my_strcmp(line, "rrb\n") == 0)
		rrb(stack_b);
	else if (my_strcmp(line, "rra\n") == 0)
		rra(stack_a);
	else
		error(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	char	*line;
	int		size;

	args = NULL;
	if (argc >= 2)
	{
		null_check(argv);
		space_check(argv);
		args = cnv_args(argv);
		check_args(args);
		creat_stack(args, &stack_a);
		size = ft_lstsize(stack_a);
		line = get_next_line(0);
		while (line)
		{
			exc_cmd(&stack_a, &stack_b, line);
			free(line);
			line = get_next_line(0);
		}
		last_steep(&stack_a, &stack_b, args, size);
	}
	return (0);
}

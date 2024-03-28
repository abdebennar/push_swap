/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:45:24 by abennar           #+#    #+#             */
/*   Updated: 2024/01/26 10:47:32 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	creat_stack(char **args, t_stack **stack_a)
{
	t_stack	*tmp;
	char	*t;

	while (*args)
	{
		tmp = ft_lstnew(ft_atoi(*args));
		if (!tmp)
			ft_lstclear(stack_a);
		ft_lstadd_back(stack_a, tmp);
		t = *args;
		args++;
		free(t);
	}
	args = NULL;
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
		if (!args)
			return (NULL);
		str = join(args, str);
		my_free(args);
		i++;
	}
	args = ft_split(str, ' ');
	my_free(str);
	if (!args)
		return (NULL);
	return (args);
}

int	main(int argc, char	**argv)
{
	char	**args ;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc >= 2)
	{
		stack_a = NULL;
		stack_b = NULL;
		null_check(argv);
		space_check(argv);
		args = cnv_args(argv);
		if (!args)
			err_exit(NULL);
		check_args(args);
		creat_stack(args, &stack_a);
		if (!is_sorted(stack_a))
			sort_args(&stack_a, &stack_b);
		free(args);
		ft_lstclear(&stack_a);
	}
	return (0);
}

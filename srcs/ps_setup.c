/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:49:58 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/29 16:52:43 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_var	*init_v(t_var *v)
{
	v = malloc(sizeof(t_var));
	v->a = NULL;
	v->b = NULL;
	v->args = NULL;
	v->len_a = 0;
	v->instru = 0;
	return (v);
}

void	get_args(t_var *v, int argc, char **argv)
{
	if (argc == 2)
		v->args = ft_split(argv[1], ' ');
	else
		v->args = &argv[1];
}

void	check_args(char **args)
{
	int			i;
	int			j;
	long long	tmp;

	i = -1;
	while (args[++i])
	{
		j = -1;
		while (++j < i)
		{
			if (ft_strcmp(args[i], args[j]) == 0)
				error("Error\n");
		}
		j = -1;
		if (args[i][0] == '-')
			j++;
		while (args[i][++j])
		{
			if (args[i][j] < '0' || args[i][j] > '9')
				error("Error\n");
		}
		tmp = ft_atoi(args[i]);
		if (tmp < -2147483647 || tmp > 2147483648)
			error("Error\n");
	}
}

void	get_stack(t_var *v)
{
	t_stack	*tmp;
	int		i;
	int		check_sort;

	i = -1;
	check_sort = 0;
	while (v->args[++i])
	{
		tmp = malloc(sizeof(t_stack));
		tmp->n = ft_atoi(v->args[i]);
		tmp->next = NULL;
		tmp->prev = NULL;
		ft_lstadd_back(&v->a, tmp);
		tmp = NULL;
	}
	tmp = v->a;
	while (tmp != NULL && tmp->next != NULL && check_sort == 0)
	{
		if (tmp->n > tmp->next->n)
			check_sort = 1;
		else
			tmp = tmp->next;
	}
	if (!check_sort)
		error("Error\n");
}

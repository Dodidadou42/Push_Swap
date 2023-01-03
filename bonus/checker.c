/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:09:38 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/29 19:09:40 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	exec_instr_next(char *instr, t_var *v);

int	check_sorted(t_var *v)
{
	if (v->b)
		return (0);
	while (v->a)
	{
		if (v->a->next)
		{
			if (v->a->n > v->a->next->n)
				return (0);
			else
				v->a = v->a->next;
		}
		else
			break ;
	}
	return (1);
}

int	exec_instr(char *instr, t_var *v)
{
	if (!ft_strcmp(instr, "sa"))
		swap(v->a);
	else if (!ft_strcmp(instr, "sb"))
		swap(v->b);
	else if (!ft_strcmp(instr, "ss"))
	{
		swap(v->a);
		swap(v->b);
	}
	else if (!ft_strcmp(instr, "pa"))
		push(&v->b, &v->a);
	else if (!ft_strcmp(instr, "pb"))
		push(&v->a, &v->b);
	else if (!ft_strcmp(instr, "ra"))
		rotate(&v->a);
	else if (!ft_strcmp(instr, "rb"))
		rotate(&v->b);
	else
		return (exec_instr_next(instr, v));
	return (1);
}

int	exec_instr_next(char *instr, t_var *v)
{
	if (!ft_strcmp(instr, "rr"))
	{
		rotate(&v->a);
		rotate(&v->b);
	}
	else if (!ft_strcmp(instr, "rra"))
		rrotate(&v->a);
	else if (!ft_strcmp(instr, "rrb"))
		rrotate(&v->b);
	else if (!ft_strcmp(instr, "rrr"))
	{
		rrotate(&v->a);
		rrotate(&v->b);
	}
	else
		return (0);
	return (1);
}

void	read_instr(t_var *v)
{
	char	instr[4];
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (!read(0, &instr[i], 1))
			break ;
		if (instr[i] == '\n')
		{	
			instr[i] = 0;
			if (!exec_instr(instr, v))
				error("Error\n");
			i = -1;
		}
	}
	if (i == 4)
		error("Error\n");
}

int	main(int argc, char **argv)
{
	t_var	*v;

	v = NULL;
	if (argc < 2)
		exit(EXIT_FAILURE);
	else
	{
		v = init_v(v);
		get_args(v, argc, argv);
		check_args(v->args);
		get_stack(v);
		read_instr(v);
		if (check_sorted(v))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
}

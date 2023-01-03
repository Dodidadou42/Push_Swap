/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:02:42 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/29 17:04:36 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sorting_hub(t_var *v)
{
	if (v->len_a == 2)
		pick_case(v, SA);
	else if (v->len_a == 3)
		sort_three(v);
	else if (v->len_a == 4)
		sort_four(v);
	else if (v->len_a == 5)
		sort_five(v);
	else if (v->len_a > 5)
		sort_big(v);
}

void	push_swap(t_var *v, int argc, char **argv)
{
	get_args(v, argc, argv);
	check_args(v->args);
	get_stack(v);
	if (argv[1][0] == 34)
		free_args(v);
	v->len_a = ft_lstsize(v->a);
	sorting_hub(v);
}

int	main(int argc, char **argv)
{
	t_var	*v;

	v = NULL;
	if (argc < 2)
		error("Not enough arguments.");
	else
	{
		v = init_v(v);
		push_swap(v, argc, argv);
	}
}

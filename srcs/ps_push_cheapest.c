/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_cheapest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:44:10 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/29 16:49:08 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_stacks_next(t_var *v, int ra, int rb)
{
	while (rb > 0)
	{
		pick_case(v, RB);
		rb--;
	}
	while (ra < 0)
	{
		pick_case(v, RRA);
		ra++;
	}
	while (rb < 0)
	{
		pick_case(v, RRB);
		rb++;
	}
}

void	rotate_stacks(t_var *v, int ra, int rb)
{
	while (ra > 0 && rb > 0)
	{
		pick_case(v, RR);
		ra--;
		rb--;
	}
	while (ra < 0 && rb < 0)
	{
		pick_case(v, RRR);
		ra++;
		rb++;
	}
	while (ra > 0)
	{
		pick_case(v, RA);
		ra--;
	}
	rotate_stacks_next(v, ra, rb);
}

void	push_cheapest(t_var *v)
{
	t_pos	*cheap;
	int		rotate_a;
	int		rotate_b;
	int		index_b;

	cheap = get_cheapest(v);
	index_b = get_index_b(cheap->n, v);
	rotate_b = get_rotate_b(v, index_b);
	rotate_a = get_rotate_a(v, cheap->i, cheap->n);
	rotate_stacks(v, rotate_a, rotate_b);
	pick_case(v, PB);
	free(cheap);
}

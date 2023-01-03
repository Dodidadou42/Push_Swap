/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_little.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:53:16 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/29 17:00:52 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_five_next(t_var *v, int n);

void	sort_three(t_var *v)
{
	int	min;

	min = ft_lstmin(v->a);
	if (v->a->n == min && v->a->next->n > v->a->next->next->n)
	{
		pick_case(v, SA);
		pick_case(v, RA);
	}
	else if (v->a->next->next->n == min)
	{
		if (v->a->n > v->a->next->n)
		{
			pick_case(v, SA);
			pick_case(v, RRA);
		}
		else if (v->a->n < v->a->next->n)
			pick_case(v, RRA);
	}
	else if (v->a->next->n == min)
	{
		if (v->a->n < v->a->next->next->n)
			pick_case(v, SA);
		else
			pick_case(v, RA);
	}
}

int	get_pos(t_var *v)
{
	int		ret;
	t_stack	*tmp;

	tmp = v->a;
	ret = 0;
	while (v->b->n > tmp->n && tmp)
	{
		ret++;
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	return (ret);
}

void	sort_four(t_var *v)
{
	int	n;

	pick_case(v, PB);
	sort_three(v);
	n = get_pos(v);
	if (n == 1)
	{
		pick_case(v, PA);
		pick_case(v, SA);
	}
	else if (n == 2)
	{
		pick_case(v, RA);
		pick_case(v, PA);
		pick_case(v, SA);
		pick_case(v, RRA);
	}
	else if (n == 3)
	{
		pick_case(v, PA);
		pick_case(v, RA);
	}
	else
		pick_case(v, PA);
}

void	sort_five(t_var *v)
{
	int	n;

	pick_case(v, PB);
	sort_four(v);
	n = get_pos(v);
	if (n == 1)
	{
		pick_case(v, PA);
		pick_case(v, SA);
	}
	else if (n == 2)
	{
		pick_case(v, PA);
		pick_case(v, SA);
		pick_case(v, RA);
		pick_case(v, SA);
		pick_case(v, RRA);
	}
	else
		sort_five_next(v, n);
}

void	sort_five_next(t_var *v, int n)
{
	if (n == 3)
	{
		pick_case(v, RRA);
		pick_case(v, PA);
		pick_case(v, RA);
		pick_case(v, RA);
	}
	else if (n == 4)
	{
		pick_case(v, PA);
		pick_case(v, RA);
	}
	else
		pick_case(v, PA);
}

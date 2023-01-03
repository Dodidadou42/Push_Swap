/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:11:25 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/29 16:16:10 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_big_setup(t_var *v)
{
	pick_case(v, PB);
	pick_case(v, PB);
	v->len_a = ft_lstsize(v->a);
	v->len_b = 2;
	v->max = malloc(sizeof(t_pos));
	v->min = malloc(sizeof(t_pos));
	if (v->b->n > v->b->next->n)
	{
		v->min->n = v->b->next->n;
		v->min->i = 1;
		v->max->n = v->b->n;
		v->max->i = 0;
	}
	else
	{
		v->min->n = v->b->n;
		v->min->i = 0;
		v->max->n = v->b->next->n;
		v->max->i = 1;
	}
}

void	update_min_max(t_var *v, t_stack *s)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	v->max->n = INT_MIN;
	v->min->n = INT_MAX;
	tmp = copy_list(s);
	while (tmp)
	{
		if (tmp->n >= v->max->n)
		{
			v->max->n = tmp->n;
			v->max->i = i;
		}
		if (tmp->n <= v->min->n)
		{
			v->min->n = tmp->n;
			v->min->i = i;
		}
		free(tmp);
		tmp = tmp->next;
		i++;
	}
	free_list(tmp);
}

int	get_index_a(t_var *v)
{
	int		ret;
	t_stack	*a;

	ret = 0;
	a = copy_list(v->a);
	if (v->b->n < a->n)
	{
		while (v->b->n < a->n)
		{
			ret++;
			a = a->next;
		}
	}
	while (v->b->n > a->n && a)
	{
		ret++;
		if (a->next)
			a = a->next;
		else
			break ;
	}
	while (a->prev)
		a = a->prev;
	free_list(a);
	return (ret);
}

void	push_back(t_var *v)
{
	int	index_a;

	update_min_max(v, v->a);
	if (v->b->n > v->max->n || v->b->n < v->min->n)
		index_a = v->min->i;
	else
		index_a = get_index_a(v);
	if (index_a <= ft_lstsize(v->a) / 2)
	{
		while (index_a-- > 0)
			pick_case(v, RA);
	}
	else
	{
		while (index_a++ < ft_lstsize(v->a))
			pick_case(v, RRA);
	}
	pick_case(v, PA);
}

void	sort_big(t_var *v)
{
	int	i;

	sort_big_setup(v);
	i = ft_lstsize(v->a) + 1;
	while (--i > 3)
	{
		push_cheapest(v);
		update_min_max(v, v->b);
	}
	sort_three(v);
	while (v->b)
		push_back(v);
	update_min_max(v, v->a);
	if (v->min->i <= ft_lstsize(v->a) / 2)
	{
		while (v->a->n != v->min->n)
			pick_case(v, RA);
	}
	else
	{
		while (v->a->n != v->min->n)
			pick_case(v, RRA);
	}
}

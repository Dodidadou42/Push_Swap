/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_cheapest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:34:35 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/29 16:36:38 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_index_b(int n, t_var *v)
{
	t_stack	*tmpb;
	int		i;

	tmpb = copy_list(v->b);
	i = 0;
	if (n > v->max->n || n < v->min->n)
		i = v->max->i;
	else
	{
		while (n > tmpb->n && tmpb && i++ > -1)
		{
			free(tmpb);
			tmpb = tmpb->next;
		}
		while (n < tmpb->n && tmpb && i++ > -1)
		{
			free(tmpb);
			tmpb = tmpb->next;
			if (!tmpb)
				break ;
		}
	}
	free_list(tmpb);
	return (i);
}

int	get_count(int n, int i, t_var *v)
{
	int	rotate_a;
	int	rotate_b;
	int	index_b;
	int	ret;

	rotate_a = get_rotate_a(v, i, n);
	index_b = get_index_b(n, v);
	rotate_b = get_rotate_b(v, index_b);
	ret = get_rotate(rotate_a, rotate_b);
	if (ret < 0)
		ret = -ret;
	ret++;
	return (ret);
}

t_pos	*get_cheapest(t_var *v)
{
	t_pos	*ret;
	t_stack	*tmpa;
	int		i;
	int		count;

	i = 0;
	tmpa = copy_list(v->a);
	ret = malloc(sizeof(t_pos));
	ret->c = INT_MAX;
	while (tmpa)
	{
		count = get_count(tmpa->n, i, v);
		if (count < ret->c)
		{
			ret->c = count;
			ret->n = tmpa->n;
			ret->i = i;
		}
		free(tmpa);
		tmpa = tmpa->next;
		i++;
	}
	return (ret);
}

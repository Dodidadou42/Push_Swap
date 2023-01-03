/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:38:53 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/29 16:41:12 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_rotate(int rotate_a, int rotate_b)
{
	int	ret;

	if (rotate_a != rotate_b)
	{
		if (rotate_a > 0 && rotate_b > 0)
		{
			if (rotate_a > rotate_b)
				ret = rotate_a;
			else
				ret = rotate_b;
		}
		else if (rotate_a < 0 && rotate_b < 0)
		{
			if (rotate_a < rotate_b)
				ret = rotate_a;
			else
				ret = rotate_b;
		}
		else
			ret = rotate_a - rotate_b;
	}
	else
		ret = rotate_a;
	return (ret);
}

int	get_rotate_a(t_var *v, int i, int n)
{
	int		ret;
	t_stack	*tmp;

	tmp = copy_list(v->a);
	ret = 0;
	while (tmp->n != n)
	{
		if (i <= ft_lstsize(tmp) / 2)
		{
			rotate(&tmp);
			ret++;
		}
		else
		{
			rrotate(&tmp);
			ret--;
		}
	}
	free_list(tmp);
	return (ret);
}

int	get_rotate_b(t_var *v, int i)
{
	int		ret;
	t_stack	*tmp;

	ret = 0;
	tmp = copy_list(v->b);
	if (i <= ft_lstsize(tmp) / 2)
	{
		while (i != 0)
		{
			rotate(&tmp);
			i--;
			ret++;
		}
	}
	else
	{
		while (i < ft_lstsize(tmp))
		{
			rrotate(&tmp);
			i++;
			ret--;
		}
	}
	free_list(tmp);
	return (ret);
}

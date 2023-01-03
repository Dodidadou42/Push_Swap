/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_case_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:20:46 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/29 16:23:39 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pick_case_next(t_var *v, int c);
void	pick_case_next_next(t_var *v, int c);

void	pick_case(t_var *v, int c)
{
	v->instru++;
	if (c == SA)
	{
		ft_putstr_fd("sa\n", 1);
		swap(v->a);
	}
	else if (c == SB)
	{
		ft_putstr_fd("sb\n", 1);
		swap(v->b);
	}
	else if (c == SS)
	{
		ft_putstr_fd("ss\n", 1);
		swap(v->a);
		swap(v->b);
	}
	else
		pick_case_next(v, c);
}

void	pick_case_next(t_var *v, int c)
{
	if (c == PA)
	{
		ft_putstr_fd("pa\n", 1);
		push(&v->b, &v->a);
	}
	else if (c == PB)
	{
		ft_putstr_fd("pb\n", 1);
		push(&v->a, &v->b);
	}
	else if (c == RA)
	{
		ft_putstr_fd("ra\n", 1);
		rotate(&v->a);
	}
	else if (c == RB)
	{
		ft_putstr_fd("rb\n", 1);
		rotate(&v->b);
	}
	else
		pick_case_next_next(v, c);
}

void	pick_case_next_next(t_var *v, int c)
{
	if (c == RR)
	{
		ft_putstr_fd("rr\n", 1);
		rotate(&v->a);
		rotate(&v->b);
	}
	else if (c == RRA)
	{
		ft_putstr_fd("rra\n", 1);
		rrotate(&v->a);
	}
	else if (c == RRB)
	{
		ft_putstr_fd("rrb\n", 1);
		rrotate(&v->b);
	}
	else if (c == RRR)
	{
		ft_putstr_fd("rrr\n", 1);
		rrotate(&v->a);
		rrotate(&v->b);
	}
}

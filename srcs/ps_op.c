/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:41:29 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/29 16:43:57 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *s)
{
	int	tmp;

	if (s && s->next)
	{
		tmp = s->n;
		s->n = s->next->n;
		s->next->n = tmp;
	}
}

void	push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*b == NULL && *a)
	{
		*b = malloc(sizeof(t_stack));
		(*b)->prev = NULL;
		(*b)->n = (*a)->n;
		(*b)->next = NULL;
		free(*a);
		(*a) = (*a)->next;
		(*a)->prev = NULL;
	}
	else if (*a)
	{
		tmp = malloc(sizeof(t_stack));
		tmp->n = (*a)->n;
		tmp->next = NULL;
		tmp->prev = NULL;
		ft_lstadd_front(b, tmp);
		free(*a);
		(*a) = (*a)->next;
	}
}

void	rotate(t_stack **s)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	tmp->next = NULL;
	tmp->n = (*s)->n;
	ft_lstadd_back(s, tmp);
	free(*s);
	(*s) = (*s)->next;
}

void	rrotate(t_stack **s)
{
	t_stack	*front;
	t_stack	*back;
	t_stack	*head;

	front = *s;
	back = *s;
	head = *s;
	while (front->next)
	{
		front = front->next;
		if (front->next != NULL)
			back = back->next;
	}
	if (front->next == NULL)
	{
		front->next = head;
		back->next = NULL;
	}
	*s = front;
}

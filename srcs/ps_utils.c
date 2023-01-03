/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:01:11 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/29 17:31:51 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error(char *str)
{
	if (ft_strlen(str) > 1)
		ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	free_args(t_var *v)
{
	int	i;

	i = -1;
	while (v->args[++i])
		free(v->args[i]);
	free(v->args);
}

/*void	print_stacks(t_var *v)
{
	t_stack	*a;
	t_stack	*b;

	a = copy_list(v->a);
	b = copy_list(v->b);
	while (a)
	{
		printf("a : %d\n", a->n);
		free(a);
		a = a->next;
	}
	while (b)
	{
		printf("b : %d\n", b->n);
		free(b);
		b = b->next;
	}
}*/

t_stack	*copy_list(t_stack *list)
{
	t_stack	*head;
	t_stack	*tail;
	t_stack	*node;
	t_stack	*new_node;

	head = NULL;
	tail = NULL;
	node = list;
	while (node)
	{
		new_node = malloc(sizeof(t_stack));
		new_node->n = node->n;
		new_node->prev = tail;
		new_node->next = NULL;
		if (tail)
			tail->next = new_node;
		tail = new_node;
		if (!head)
			head = new_node;
		node = node->next;
	}
	return (head);
}

void	free_list(t_stack *list)
{
	t_stack	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

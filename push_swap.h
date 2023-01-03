/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:07:51 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/29 17:10:54 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define SA  1
# define SB  2
# define SS  3
# define PA  4
# define PB  5
# define RA  6
# define RB  7
# define RR  8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct s_pos
{
	int	n;
	int	i;
	int	c;
}	t_pos;

typedef struct s_stack
{
	int				n;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_var
{
	int		len_a;
	int		len_b;
	int		instru;

	char	**args;

	t_stack	*a;
	t_stack	*b;

	t_pos	*min;
	t_pos	*max;
}	t_var;

//LIBFT
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *str);
char		**ft_split(char const *s, char c);
int			ft_strcmp(char *s1, char *s2);
long long	ft_atoi(char *s);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack		*ft_lstlast(t_stack *lst);
int			ft_lstsize(t_stack *lst);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
int			ft_lstmin(t_stack *lst);
t_stack		*copy_list(t_stack *list);
void		free_list(t_stack *list);

//PUSH_SWAP MAIN
t_var		*init_v(t_var *v);
void		get_args(t_var *v, int argc, char **argv);
void		check_args(char **args);
void		get_stack(t_var *v);
void		free_args(t_var *v);
void		sorting_hub(t_var *v);
void		sort_five(t_var *v);
void		sort_four(t_var *v);
void		sort_three(t_var *v);
void		sort_big(t_var *v);
void		pick_case(t_var *v, int c);
void		print_stacks(t_var *v);
void		error(char *str);

//SORT_BIG UTILS
t_pos		*get_cheapest(t_var *v);
int			get_index_b(int n, t_var *v);
int			get_rotate_b(t_var *v, int i);
int			get_rotate_a(t_var *v, int i, int n);
int			get_rotate(int rotate_a, int rotate_b);
void		push_cheapest(t_var *v);

//PUSH_SWAP OPS
void		push(t_stack **a, t_stack **b);
void		swap(t_stack *s);
void		rrotate(t_stack **s);
void		rotate(t_stack **s);

#endif

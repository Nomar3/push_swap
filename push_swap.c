/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:37:07 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/07/10 17:44:53 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	micro_index(t_nd *node, int pos, int index)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		i++;
		node = node->next;
	}
	node->ind = index;
}

void	put_index(t_nd *node, int size)
{
	t_nd	*head;
	int		max_p;
	int		max_v;

	head = node;
	while (size > 0)
	{
		max_v = INT_MIN;
		while (node)
		{
			if (node->value >= max_v && node->ind == 0)
			{
				max_v = node->value;
				max_p = node->pos;
			}
			node = node->next;
		}
		node = head;
		micro_index(node, max_p, size);
		size--;
	}
}

static void	create_st(t_nd **st, int nbr)
{
	t_nd	*nd;
	t_nd	*last_nd;

	if (st == NULL)
		return ;
	nd = malloc(sizeof(t_nd));
	if (nd == NULL)
		return ;
	nd->next = NULL;
	nd->value = nbr;
	nd->ind = 0;
	if (*st == NULL)
	{
		*st = nd;
		nd->prev = NULL;
	}
	else
	{
		last_nd = find_last_nd(*st);
		last_nd->next = nd;
		nd->prev = last_nd;
	}
}

static void	init_st(t_nd **a, char **argv)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		nbr = ft_atol(argv[i], a);
		if (nbr < INT_MIN || nbr > INT_MAX)
			error(*a, NULL);
		create_st(a, (int)nbr);
		i++;
	}
	if (!check_rep(*a))
		error(*a, NULL);
	put_position(*a);
	put_index(*a, st_size(*a));
}

int	main(int argc, char **argv)
{
	t_nd	*a;
	t_nd	*b;
	char **aux;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if ((argc == 2 && !argv[1][0]))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else if (argc == 2)
		aux = ft_split(argv[1], ' ');
	else
		aux = &(argv[1]);
	init_st(&a, aux);
	if (st_size(a) <= 3 && !is_sorted(a))
		sort_three(&a);
	else if (!is_sorted(a))
		sort(&a, &b);
	free_st(&a);
	free_st(&b);
	if (argc == 2)
		free_pp(&aux);
	return (0);
}

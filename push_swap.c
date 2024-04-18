/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:37:07 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/04/18 20:07:14 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_position(t_nd *node)
{
	int	i;

	i = 0;
	while (node)
	{
		node->pos = i;
		i++;
		node = node->next;
	}
}

void	micro_index(t_nd *node, int pos, int index)
{
	int i;

	i = 0;
	while(i < pos)
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

static void create_st(t_nd **st, int nbr)
{
	t_nd	*nd;
	t_nd	*last_nd;
	
	if(st == NULL)
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

static void init_st(t_nd **a, char **argv)
{
	long	nbr;
	int i=0;
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

	
 void	prueba(t_nd *a,t_nd *b)
{
	t_nd *prueba1;
	t_nd *prueba2;
	
	prueba1 = a;
	prueba2 = b;
	printf("stack A:\n");
	while(prueba1)
	{
		
		printf("Value: %d   index: %d   pos: %d   target: %d\n", prueba1->value, prueba1->ind, prueba1->pos, prueba1->target);
		prueba1 = prueba1->next;
	}
	printf("stack B:\n");
	while(prueba2)
	{
		printf("Value: %d   index: %d   pos: %d   target: %d   cost b: %d   cost a: %d   cost total: %d\n", prueba2->value, prueba2->ind, prueba2->pos, prueba2->target, prueba2->cost_b, prueba2->cost_a, prueba2->cost_t);
		prueba2 = prueba2->next;
	}

} 

int main(int argc, char **argv)
{
	t_nd	*a;
	t_nd	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if ((argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv= ft_split(argv[1], ' ');
	else
		argv =&(argv[1]);
	//iniciacion del stack, con prueba
	
	init_st(&a, argv);
	//if el stack no esta ordenado --> procede el algoritmo con sus funciones
	if (st_size(a) <= 3 && !is_sorted(a))
		sort_three(&a);
	else if (!is_sorted(a))
	{
		left_three(&a, &b);
		put_position(a);
		set_target(a, b);
		sort_three(&a);
		while (b)
		{
			put_position(a);
			put_position(b);
			set_target(a, b);
			set_cost_b(b);
			set_cost_a(a, b);
			set_total_cost(a, b);
			sort_node(cheap_node(b), &a, &b);
			//prueba(a, b);
		}
		put_position(a);
		last_sort(&a);
	}
	//prueba(a, b);
	return (0);
}		
	//liberacion del stack una vez ordenado


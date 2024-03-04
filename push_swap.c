/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:37:07 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/02/28 17:42:28 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void create_st(t_nd **st, int nbr)
{
	t_nd	*nd;
	t_nd	*last_nd;
	
	if(st == NULL)
		return ;
	nd = malloc(sizeof(t_nd));
	if (nd == NULL)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (*stack = NULL)
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

static void init_st(t_nd **a, char **argv, )
{
	long	nbr;

	while (*argv)
	{
		nbr = ft_atol(*argv);
		if (nbr < INT_MIN || nbr > INT_MAX)
			//error
		//if (numeros se repiten) --> error
		create_st(a, (int)nbr);
		argv++;
	}
}

int main(int argc, char **argv)
{
	t_nd	*a;
	t_nd	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if(argc == 2)
		argv = ft_split(argv[1], ' ');
	//iniciacion del stack
	
	//if el stack no esta ordenado --> procede el algoritmo con sus funciones
	
	//liberacion del stack una vez ordenado
	return (0);
}

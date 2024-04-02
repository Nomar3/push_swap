/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:37:07 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/04/02 18:35:43 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_rep(t_nd *stack)
{
	t_nd	*aux;

	while (stack)
	{
		aux = stack->next;
		while (aux)
		{
			if (stack->value == aux->value)
			{
				printf("numero repe\n");
				return (0);
			}
			aux = aux->next;
		}
		stack = stack->next;
	}
	return (1);
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
	argv++;
	while (*argv)
	{
		nbr = ft_atol(*argv);
		if (nbr < INT_MIN || nbr > INT_MAX)
			error(a, NULL);
		create_st(a, (int)nbr);
		argv++;
	}
	if (check_rep(*a))
		printf("numeros bien\n");
}

int main(int argc, char **argv)
{
	t_nd	*a;
	t_nd	*b;
	t_nd *prueba1;
	t_nd *prueba2;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	//iniciacion del stack, con prueba
	
	init_st(&a, argv);
	//init_st(&b, argv);
	//rra(&a);
	//if el stack no esta ordenado --> procede el algoritmo con sus funciones
	
	//liberacion del stack una vez ordenado
	
	
	//modo prueba:
	prueba1 = a;
	prueba2 = b;
	printf("stack A:\n");
	while(prueba1)
	{
		printf("%d\n", prueba1->value);
		prueba1 = prueba1->next;
	}
	printf("stack B:\n");
	while(prueba2)
	{
		printf("%d\n", prueba2->value);
		prueba2 = prueba2->next;
	}

	return (0);
}

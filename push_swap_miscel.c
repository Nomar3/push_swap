/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_miscel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:29:37 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/04/02 21:31:16 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//funciones que chekean

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

int	is_sorted(t_nd **stack)
{
	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:21:13 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/03/20 20:45:42 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_nd **stack)
{
	t_nd	*aux;

	aux = (*stack);
	*stack = (*stack)->next;
	aux->next = (*stack)->next;
	(*stack)->next = aux;
}

void	sa(t_nd **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_nd **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_nd **a, t_nd **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

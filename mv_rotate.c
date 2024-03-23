/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:46:14 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/03/21 18:52:13 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_nd **stack)
{
	t_nd	*aux;
	t_nd	*head;

	aux = (*stack);
	head = (*stack)->next;
	(*stack) = find_last_nd(*stack);
	(*stack)->next = aux;
	aux->next = NULL;
	(*stack) = head;
}
void	ra (t_nd **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb (t_nd **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr (t_nd **a, t_nd **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

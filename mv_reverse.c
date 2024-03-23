/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:59:36 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/03/21 19:36:19 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_nd **stack)
{
	t_nd	*head;
	t_nd	*aux;

	aux = (*stack);
	head = find_last_nd(*stack);
	while ((*stack)->next->next)
		(*stack) = (*stack)->next;
	head->next = aux;
	(*stack)->next = NULL;
	(*stack) = head;
}

void	rra(t_nd **a)
{
	reverse(a);
	write(1, "rra\n", 4);
}

void	rrb(t_nd **b)
{
	reverse(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_nd **a, t_nd **b)
{
	reverse(a);
	reverse(b);
	write(1, "rrr\n", 4);
}

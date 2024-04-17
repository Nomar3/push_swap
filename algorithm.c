/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:10:44 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/04/17 20:41:40 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_node_two(t_nd *node, t_nd **a, t_nd **b)
{
	while (node->cost_a < 0)
	{
		rra(a);
		node->cost_a ++;
	}
	while (node->cost_a > 0)
	{
		ra(a);
		node->cost_a --;
	}
	while (node->cost_b < 0)
	{
		rrb(b);
		node->cost_b ++;
	}
	while (node->cost_b > 0)
	{
		rb(b);
		node->cost_b --;
	}
}

void	sort_node(t_nd *node, t_nd **a, t_nd **b)
{
	while (node->cost_a > 0 && node->cost_b > 0)
	{
		rr(a, b);
		node->cost_a --;
		node->cost_b --;
	}
	while (node->cost_a < 0 && node->cost_b < 0)
	{
		rrr(a, b);
		node->cost_a ++;
		node->cost_b ++;
	}
	sort_node_two(node, a, b);
	pa(b, a);
}

void	last_sort(t_nd **a)
{
	t_nd	*aux;

	aux = *a;
	while ((aux)->ind != 1)
		aux = (aux)->next;
	while ((aux)->pos)
	{
		ra(a);
		(aux)->pos --;
	}
}

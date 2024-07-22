/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:10:44 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/07/10 17:47:05 by rmarin-j         ###   ########.fr       */
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
	while ((aux)->pos && st_size(*a) > ((aux)->pos) / 2)
	{
		rra(a);
		put_position(*a);
	}
	while ((aux)->pos && st_size(*a) <= ((aux)->pos) / 2)
	{
		ra(a);
		put_position(*a);
	}
}

void	sort(t_nd **a, t_nd **b)
{
	left_three(a, b);
	put_position(*a);
	set_target(*a, *b);
	sort_three(a);
	while (*b)
	{
		put_position(*a);
		put_position(*b);
		set_target(*a, *b);
		set_cost_b(*b);
		set_cost_a(*a, *b);
		set_total_cost(*a, *b);
		sort_node(cheap_node(*b), a, b);
	}
	put_position(*a);
	last_sort(a);
}

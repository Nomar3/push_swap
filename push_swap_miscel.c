/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_miscel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:29:37 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/04/23 17:03:41 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_total_cost(t_nd *a, t_nd *b)
{
	while (b)
	{
		if (((b->cost_b < 0) && (b->cost_a < 0))
			|| ((b->cost_b > 0) && (b->cost_a > 0)))
		{
			if (ft_abs(b->cost_a) > ft_abs(b->cost_b))
				b->cost_t = ft_abs(b->cost_a);
			else
				b->cost_t = ft_abs(b->cost_b);
		}
		else
		{
			b->cost_t = (ft_abs(b->cost_b) + ft_abs(b->cost_a));
		}
		b = b->next;
	}
}

void	set_cost_a(t_nd *a, t_nd *b)
{
	int	size_a;
	int	half_a;

	size_a = st_size(a);
	half_a = size_a / 2;
	while (b)
	{
		if (b->target <= half_a)
			b->cost_a = b->target;
		else
			b->cost_a = b->target - size_a;
		b = b->next;
	}
}

void	set_cost_b(t_nd *b)
{
	int	half;
	int	size;

	size = st_size(b);
	half = st_size(b) / 2;
	while (b)
	{
		if (b->pos <= half)
			b->cost_b = b->pos;
		else
			b->cost_b = b->pos - size;
		b = b->next;
	}
}

int	check_rep(t_nd *stack)
{
	t_nd	*aux;

	while (stack)
	{
		aux = stack->next;
		while (aux)
		{
			if (stack->value == aux->value)
				error(stack, NULL);
			aux = aux->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	is_sorted(t_nd *node)
{
	while (node->next)
	{
		if (node->ind > (node->next)->ind)
			return (0);
		node = node->next;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:56:17 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/04/18 16:17:27 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_tar(t_nd *a, t_nd *b)
{
	int	value;
	int	min_value;
	int	min_pos;

	min_value = INT_MAX;
	min_pos = 0;
	value = b->value;
	while (a)
	{
		if ((value < a->value) && (a->value < min_value))
		{
			min_value = a->value;
			min_pos = a->pos;
		}
		a = a->next;
	}
	b->target = min_pos;
}

void	set_target(t_nd *a, t_nd *b)
{
	while (b)
	{
		input_tar(a, b);
		b = b->next;
	}
}

void	left_three(t_nd **a, t_nd **b)
{
	int	max_ind;

	max_ind = st_size(*a);
	while (st_size(*a) > 3)
	{
		if (((*a)->ind > (max_ind - 3)))
			ra(a);
		else
			pb(a, b);
	}
}

void	sort_three(t_nd **stack)
{
	if (st_size(*stack) == 2)
		sa(stack);
	else
	{
		if (((*stack)->ind > (*stack)->next->ind)
			&& ((*stack)->ind > (*stack)->next->next->ind))
			ra(stack);
		if (((*stack)->ind < (*stack)->next->ind)
			&& ((*stack)->next->ind > (*stack)->next->next->ind))
			rra(stack);
		if (((*stack)->ind > (*stack)->next->ind))
			sa(stack);
	}
}

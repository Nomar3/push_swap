/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:52:34 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/04/17 19:40:35 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

t_nd	*cheap_node(t_nd *b)
{
	int		aux;
	t_nd	*ch_nd;

	aux = INT_MAX;
	ch_nd = NULL;
	while (b)
	{
		if (b->cost_t <= aux)
		{
			aux = b->cost_t;
			ch_nd = b;
		}
		b = b->next;
	}
	return (ch_nd);
}

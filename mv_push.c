/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:58:53 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/08/01 17:09:07 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_nd **src, t_nd **dest)
{
	t_nd	*nd_push;

	if (*src)
	{
		nd_push = (*src);
		*src = (*src)->next;
		nd_push->next = *dest;
		*dest = nd_push;
	}
}

void	pa(t_nd **a, t_nd **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_nd **b, t_nd **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}

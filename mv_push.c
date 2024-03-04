/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:58:53 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/02/28 19:30:56 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_nd **dest, t_nd **src)
{
	t_nd	*nd_push;
	
	if (*src = NULL)
		return (NULL);
	nd_push = *src->next;
	*src = (*src)->next;
	/*if (*src)
		(*src) ->prev = NULL;
	*/
	nd_push->prev = NULL;
	if(*dest == NULL)
	{
		*dest = nd_push;
		nd_push->next = NULL;
	}
	else
	{
		nd_push->next = *dest;
		nd_push->next->prev = nd_push;
		*dest = nd_push;
	}
}
void pa (t_nd **a, t_nd **b)
{
	push(&a, &b);
	write(1, "pa\n", 3);
}

void pb (t_nd **b, t_nd **a)
{
	push(&b, &a);
	write(1, "pb\n", 3);
}
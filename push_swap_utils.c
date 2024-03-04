/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:13:49 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/02/28 16:50:21 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*st_size(t_nd *stack)
{
	int count;

	count = 0;
	if (stack == NULL)
		return (NULL);
	while (stack->next)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

t_nd	*find_last_nd(t_nd *first)
{
	if (first == NULL)
		return (NULL);
	while (first->next)
		first = first->NULL;
	return (first);
}

long	ft_atol(const char *str)
{
	long	s;
	long	nb;
	int		i;

	s = 1;
	nb = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * s);
}

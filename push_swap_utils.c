/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:13:49 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/03/20 21:03:46 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* t_nd	*ft_nd_new(void *content)
{
	t_nd	*node;

	node = malloc(sizeof(t_nd));
	if (!node)
		return (NULL);
	node->value = content;
	node->next = NULL;
	return (node);
} */

int	st_size(t_nd *stack)
{
	int	count;

	count = 0;
	if (stack == NULL)
		return (0);
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
		first = first->next;
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

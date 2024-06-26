/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:13:49 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/05/17 16:43:52 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_st(t_nd **stack)
{
	t_nd	*aux;

	aux = NULL;
	if (*stack && (*stack)->next)
		aux = (*stack)->next;
	while (aux)
	{
		free(*stack);
		(*stack) = aux;
		aux = aux->next;
	}
	free(*stack);
}

void	error(t_nd *st_a, t_nd *st_b)
{
	write(2, "Error\n", 6);
	if (st_a)
		free_st(&st_a);
	if (st_b)
		free_st(&st_b);
	exit(1);
}

int	st_size(t_nd *stack)
{
	int	count;

	count = 0;
	if (!stack)
		return (0);
	while (stack)
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

long	ft_atol(const char *str, t_nd **stack)
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
		if (str[i + 1] < '0' || str[i + 1] > '9')
			error(*stack, NULL);
		if (str[i] == '-')
			s = -s;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error(*stack, NULL);
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:37:24 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/02/28 17:41:21 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_nd
{
	int	value;
	int	ind;
	int cost;
	struct s_nd *next;
	struct s_nd *prev;
}	t_nd;

/*------------ft_split------------*/
char	**ft_split(char const *s, char c);
static int	ft_free(const char *sub_s, char **ptr, char c, int *k);
static int	cont_word(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
/*------------utils------------*/
long	ft_atol(const char *str);
t_nd	*find_last_nd(t_nd *first);

/*------------push_swap------------*/
static void create_st(t_nd **st, int nbr);
static void init_st(t_nd **a, char **argv, );
#endif
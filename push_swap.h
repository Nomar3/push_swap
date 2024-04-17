/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:37:24 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/04/17 20:29:47 by rmarin-j         ###   ########.fr       */
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
	int	pos;
	int	target;
	int	cost_a;
	int	cost_b;
	int	cost_t;
	struct s_nd	*next;
	struct s_nd	*prev;
}	t_nd;

/*----------miscelaneus------------*/
int			check_rep(t_nd *stack);
int			is_sorted(t_nd *stack);
void		set_cost_a(t_nd *a, t_nd *b);
void		set_cost_b(t_nd *b);
void		set_total_cost(t_nd *a, t_nd *b);

/*------------utils------------*/
long		ft_atol(const char *str, t_nd **stack);
t_nd		*find_last_nd(t_nd *first);
int			st_size(t_nd *stack);
void		free_st(t_nd **stack);
void		error(t_nd *st_a, t_nd *st_b);
/*------------utils_2------------*/
int			ft_abs(int n);
t_nd		*cheap_node(t_nd *b);
/*------------algorithm------------*/
void		sort_node(t_nd *node, t_nd **a, t_nd **b);
void		last_sort(t_nd **a);
/*-----------sorting------------*/
void		left_three(t_nd **a, t_nd **b);
void		sort_three(t_nd **stack);
void		input_tar(t_nd *a, t_nd *b);
void		set_target(t_nd *a, t_nd *b);
/*------------push_swap------------*/
static void	create_st(t_nd **st, int nbr);
static void	init_st(t_nd **a, char **argv);
/*------------ft_split------------*/
char		**ft_split(char const *s, char c);
static int	ft_free(const char *sub_s, char **ptr, char c, int *k);
static int	cont_word(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);
/*----------swap----------*/
static void	swap(t_nd **stack);
void		sa(t_nd **a);
void		sb(t_nd **b);
void		ss(t_nd **a, t_nd **b);
/*---------push----------*/
static void	push(t_nd **dest, t_nd **src);
void		pa(t_nd **a, t_nd **b);
void		pb(t_nd **b, t_nd **a);
/*---------rotate-------*/
static void	rotate(t_nd **stack);
void		ra(t_nd **a);
void		rb(t_nd **b);
void		rr(t_nd **a, t_nd **b);
/*----------reverse_rotate----------*/
void		reverse(t_nd **stack);
void		rra(t_nd **a);
void		rrb(t_nd **b);
void		rrr(t_nd **a, t_nd **b);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:49:06 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/03 12:07:56 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_big(t_stacks *s)
{
	int	start;
	int	max;
	int	i;

	start = 0;
	max = 0;
	ft_croissant(s, &start, &max);
	ft_push_b(s, &start, &max);
	while (s->b_size >= 0)
	{
		ft_maximize(s);
		i = s->size - 1;
		while (i >= 0)
			printf("%2d ", s->a[i--]);
		printf("\n");
		i = s->size - 1 ;
		while (i >= 0)
			printf("%2d ", s->b[i--]);
		printf("\n\n");
	}
}

void	ft_maximize(t_stacks *s)
{
	t_cost	r;
	int		i;
	int		tmp;

	r.min_index = s->size * 3;
	i = -1;
	while (++i < s->b_size / 2)
	{
		tmp = ft_cost(s, &r, (s->b_size - i));
		if (tmp == i + 1)
		{
			printf("%d\n", tmp);
			break ;
		}
		else if (tmp < r.min_index)
			ft_min(&r, tmp);
		tmp = ft_cost(s, &r, (i));
		if (tmp == i + 2)
		{
			printf("%d\n", tmp);
			break ;
		}
		else if (tmp < r.min_index)
			ft_min(&r, tmp);
	}
}

void	ft_min(t_cost *r, int tmp)
{
	r->min_index = tmp;
	r->r = r->min_r;
	r->r_rota = r->min_r_rota;
}

int	ft_cost(t_stacks *s, t_cost *r, int i)
{
	int	index;
	int	j;
	int	k;

	ft_min_max(s);
	if (s->b[i] < s->min || s->b[i] > s->max)
		index = s->index;
	else
	{	
		j = ft_index(s, s->index);
		k = ft_index(s, j);
		while (!(s->b[i] > s->a[j] && s->b[i] < s->a[k]))
		{
			j = k;
			k = ft_index(s, j);
		}
		index = j;
	}
	return (ft_false_rotate(s, r, i, index));
}

int	ft_index(t_stacks *s, int j)
{
	if (s->a[j] == 0)
		return (s->a_size);
	return (j - 1);
}

int	ft_false_rotate(t_stacks *s, t_cost *r, int b, int a)
{
	int	cost;

	r->r_rota = 0;
	r->r = 0;
	if (a >= s->a_size && b >= s->b_size)
	{
		a = s->a_size - a;
		b = s->b_size - b;
		r->r = 1;
		r->r_rota = ft_abs(a - b);
		cost = a + b - r->r_rota + 1;
	}
	else if (a < s->a_size && b < s->b_size)
	{
		a ++;
		b ++;
		r->r = 2;
		r->r_rota = ft_abs(a - b);
		cost = a + b - r->r_rota + 1;
	}
	else if (a < s->a_size && b >= s->b_size)
		cost = (s->b_size - b) + a + 2;
	else if (a >= s->a_size && b < s->b_size)
		cost = (s->a_size - a) + b + 2;
}

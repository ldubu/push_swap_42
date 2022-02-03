/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:49:06 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/03 16:33:18 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_big(t_stacks *s)
{
	int	start;
	int	max;

	start = 0;
	max = 0;
	ft_croissant(s, &start, &max);
	ft_push_b(s, &start, &max);
	while (s->b_size >= 0)
	{
		ft_maximize(s);
	}
	ft_min_max(s);
	ft_rotate(s, s->index);
	/*int i = s->size - 1;
	while (i >= 0)
		//printf("%2d ", s->a[i--]);
	printf("\n");
	i = s->size - 1 ;
	while (i >= 0)
		printf("%2d ", s->b[i--]);
	printf("\n\n");*/

}

void	ft_maximize(t_stacks *s)
{
	t_cost	r;
	int		i;
	int		tmp;

	r.min = s->size * 3;
	r.min_r = 0;
	r.min_r_rota = 0;
	i = -1;
	while (++i <= s->b_size / 2)
	{
		tmp = ft_cost(s, &r, (s->b_size - i));
		//printf("%d\n", r.min_b);
		if (tmp == (i + 1))
		{
			ft_min(&r, tmp);
			ft_rotate_ab(s, &r);
			ft_p('a', s);
			i = s->b_size + 8;
			break ;
		}
		else if (tmp < r.min)
			ft_min(&r, tmp);
		tmp = ft_cost(s, &r, (i));
		if (tmp == i + 2)
		{
			ft_min(&r, tmp);
			ft_rotate_ab(s, &r);
			ft_p('a', s);
			i = s->b_size + 8;
			break ;
		}
		else if (tmp < r.min)
			ft_min(&r, tmp);
	}
	if (i != s->b_size + 8)
	{ ft_rotate_ab(s, &r); ft_p('a', s);}
}

void	ft_min(t_cost *r, int tmp)
{
	r->min = tmp;
	r->r = r->min_r;
	r->r_rota = r->min_r_rota;
	r->min_b = r->b;
	r->min_a = r->a;
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
		
		j = ft_index(s, s->index, 'a');
		k = ft_index(s, j, 'a');
		while (!(s->b[i] > s->a[j] && s->b[i] < s->a[k]))
		{
			j = k;
			k = ft_index(s, j, 'a');
		}
		index = k;
		//printf("index = %d, j = %d, k= %d\n", index, j, k);
	}
	r->a = index;
	r->b = i;
	return (ft_false_rotate(s, r, i, index));
}

int	ft_index(t_stacks *s, int j, char c)
{
	if (c == 'a' && j == 0)
		return (s->a_size);
	else if (c == 'b' && j == 0)
		return (s->b_size);
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
	return (cost);
}

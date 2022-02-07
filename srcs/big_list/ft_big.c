/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:49:06 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/07 17:23:06 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_big(t_stacks *s)
{
	int ch_size;
	int	ch_n;
	int	i = -1;
	int cnt = 0;
	int x = -1;
	while (++i < s->size)
	{
		cnt = 0;
		x = -1;
		while (++x < s->size)
			if (x != i && s->a[x] < s->a[i])
				cnt++;
		s->b[i] = cnt;
	}
	i = -1;
	while (++i < s->size)
	{
		s->a[i] = s->b[i];
		s->b[i] = 0;
	}
	ch_size = (s->size / 12) + 22;
	ch_n = 1;
	i = 0;
	while (s->a_size >= 0)
	{
		//printf("data = %d, ch_size = %d, ch_n = %d, i = %d\n", s->a[s->a_size], ch_size, ch_n, i);
		if (s->a[s->a_size] < (ch_size * ch_n))
		{
			ft_p('b', s);
			if (s->b[s->b_size] < ch_size * ch_n - (ch_size / 2) && s->b_size > 0)
				ft_r('b', s);
			i++;
		}
		else
			ft_r('a', s);
		if ( i == ch_size * ch_n)
			ch_n++;
	}
	int	index;
	/*int j= s->size - 1;
	while (j>= 0)
		printf("%2d ", s->a[j--]);
	printf("\n");
	j= s->size - 1 ;
	while (j>= 0)
		printf("%2d ", s->b[j--]);
	printf("\n\n");*/
	while (s->a_size < s->size - 1)
	{
		index = search_next(s);
		if (rotate_b(s, index))
		{
			ft_p('a', s);
			if (s->b_size > 0 && s->b[s->b_size] < s->b[s->b_size - 1])
				ft_s('s', s);
			else
				ft_s('a', s);
		}
		else
			ft_p('a', s);
		/*j= s->size - 1;
		while (j>= 0)
			printf("%2d ", s->a[j--]);
		printf("\n");
		j= s->size - 1 ;
		while (j>= 0)
			printf("%2d ", s->b[j--]);
		printf("\n\n");*/
	}

	/*int j= s->size - 1;
	while (j>= 0)
		printf("%2d ", s->a[j--]);
	printf("\n");
	j= s->size - 1 ;
	while (j>= 0)
		printf("%2d ", s->b[j--]);
	printf("\n\n");*/
	/*int	start;
	int	end;

	start = 0;
	end = 0;
	ft_croissant(s, &start, &end);
	while (s->b_size >= 0)
	{
		ft_maximize(s);
	}
	ft_min_max(s);
	rotate_a(s, s->index);
	int j= s->size - 1;
	while (i >= 0)
		printf("%2d ", s->a[i--]);
	printf("\n");
	i = s->size - 1 ;
	while (i >= 0)
		printf("%2d ", s->b[i--]);
	printf("\n\n");*/

}

int	search_next(t_stacks *s)
{
	int i;

	i = 0;
	//printf("%d\n", s->b_size);
	while (s->b[i] < s->b_size)
		i++;
	//printf("%d\n", i);
	return (i);
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

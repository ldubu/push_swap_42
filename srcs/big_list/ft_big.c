/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:49:06 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/10 11:30:26 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_big(t_stacks *s)
{
	int	index;

	replace_number(s);
	push_on_b(s);
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
	}	
}

int	search_next(t_stacks *s)
{
	int	i;

	i = 0;
	while (s->b[i] < s->b_size)
		i++;
	return (i);
}

void	replace_number(t_stacks *s)
{
	int	i;
	int	cnt;
	int	x;

	i = -1;
	cnt = 0;
	x = -1;
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
}

void	push_on_b(t_stacks *s)
{
	int	ch_size;
	int	ch_n;
	int	i;

	ch_size = (s->size / 12) + 22;
	ch_n = 1;
	i = 0;
	while (s->a_size >= 0)
	{
		if (s->a[s->a_size] < (ch_size * ch_n))
		{
			ft_p('b', s);
			if (s->b[s->b_size]
				< ch_size * ch_n - (ch_size / 2) && s->b_size > 0)
				ft_r('b', s);
			i++;
		}
		else
			ft_r('a', s);
		if (i == ch_size * ch_n)
			ch_n++;
	}
}

/*int j= s->size - 1;
	while (j>= 0)
		printf("%2d ", s->a[j--]);
	printf("\n");
	j= s->size - 1 ;
	while (j>= 0)
		printf("%2d ", s->b[j--]);
	printf("\n\n");*/

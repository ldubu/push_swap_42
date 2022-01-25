/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:34:29 by ldubuche          #+#    #+#             */
/*   Updated: 2022/01/25 16:38:09 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_small(t_stacks *s)
{
	if (s->size == 2)
		ft_putstr_fd("sa\n", 1);
	else if (s->size == 3)
		ft_3nbr(s);
	else
		ft_sup3(s);
	
}

void	ft_3nbr(t_stacks *s)
{
	if (s->a[2] < s->a[1] && s->a[1] > s->a[0])
	{
		ft_rr('a', s, 3);
		if (s->a[2] > s->a[1])
			ft_s('a', s, 3);
	}
	else if (s->a[2] > s->a[1] && s->a[1] < s->a[0])
	{
		if (s->a[2] > s->a[0])
			ft_r('a', s, 3);
		else
			ft_s('a', s, 3);
	}
	else
	{
		ft_s('a', s, 3);
		ft_rr('a', s, 3);
	}
}

void	ft_sup3(t_stacks *s)
{
	int	i;

	i = s->size - 3;
	while (i-- > 0)
		ft_p('b', s);
	//printf("%d %d %d %d %d\n", s->b[0], s->b[1], s->b[2], s->b[3], s->b[4]);
	//printf("%d %d %d %d %d\n", s->a[0], s->a[1], s->a[2], s->a[3], s->a[4]);
	ft_3nbr(s);
	//printf("%d %d %d %d %d\n", s->b[0], s->b[1], s->b[2], s->b[3], s->b[4]);
	//printf("%d %d %d %d %d\n", s->a[0], s->a[1], s->a[2], s->a[3], s->a[4]);
	//printf(" b_size = %d\n", s->b_size);
	while (s->b_size >= 0)
	{	ft_move(s);
		//printf("%d %d %d %d %d\n", s->b[0], s->b[1], s->b[2], s->b[3], s->b[4]);
		//printf("%d %d %d %d %d\n", s->a[0], s->a[1], s->a[2], s->a[3], s->a[4]);
	}
	while (s->a[s->a_size] > s->a[0])
	{
		ft_r('a', s, s->a_size + 1);
		//printf("%d %d %d %d %d\n", s->a_size, s->b[1], s->b[2], s->b[3], s->b[4]);
		//printf("%d %d %d %d %d\n", s->a[0], s->a[1], s->a[2], s->a[3], s->a[4]);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:02:30 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/07 15:55:29 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_pa(t_stacks *s)
{
	int	i;
	int	j;

	while (s->b_size >= 0)
	{
		j = s->b_size;
		i = s->a_size;
		if (s->b[j] > s->max || s->b[j] < s->min)
		{
			rotate_a(s, s->index);
			ft_p('a', s);
		}
		else if (s->b[j] < s->a[i] && s->b[j] > s->a[0])
			ft_p('a', s);
		else
			ft_pa2(s, i, j);
		s->b_size = s->b_size - 1;
	}
}

void	ft_pa2(t_stacks *s, int i, int j)
{
	while (i > 0)
	{
		if (s->b[j] > s->a[i] && s->b[j] < s->a[i - 1])
		{
			rotate_a(s, i - 1);
			ft_p('a', s);
			i = 0;
		}
		i--;
	}
}

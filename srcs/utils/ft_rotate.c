/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:45:39 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/03 14:53:55 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rotate(t_stacks *s, int index)
{
	while (index < s->a_size)
	{
		if (index >= s->a_size / 2)
		{
			ft_r('a', s);
			index = index + 1;
		}
		else
		{
			ft_rr('a', s);
			if (index == 0)
				index = s->a_size;
			else
				index = index - 1;
		}
	}
}

void	ft_rotate_ab(t_stacks *s, t_cost *r)
{
	while (r->min_r_rota-- > 0)
	{
		if (r->min_r == 1)
		{
			ft_r('r', s);
			r->min_a = r->min_a + 1;
			r->min_b = r->min_b + 1;
		}
		else if (r->min_r == 2)
		{
			ft_rr('r', s);
			r->min_a = ft_index(s, r->min_a, 'a');
			r->min_b = ft_index(s, r->min_b, 'b');
		}
	}
	ft_rotate(s, r->min_a);
	while (r->min_b < s->b_size)
	{
		if (r->min_b >= s->b_size / 2)
		{
			ft_r('b', s);
			r->min_b = r->min_b + 1;
		}
		else
		{
			ft_rr('b', s);
			if (r->min_b == 0)
				r->min_b = s->b_size;
			else
				r->min_b = r->min_b - 1;
		}
	}
}

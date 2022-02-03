/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:45:39 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/03 13:50:46 by ldubuche         ###   ########.fr       */
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

/*void	ft_rotate_ab(t_stacks *s, t_cost *r)
{
	if (r->min_r == 1)
		while (r->min_r_rota-- > 0)
			ft_r('r', s);
	while (index < s->b_size)
	{
		if (index >= s->b_size / 2)
		{
			ft_r('b', s);
			index = index + 1;
		}
		else
		{
			ft_rr('b', s);
			if (index == 0)
				index = s->b_size;
			else
				index = index - 1;
		}
	}
}
*/
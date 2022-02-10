/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:45:39 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/07 15:48:09 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_a(t_stacks *s, int index)
{
	while (index < s->a_size)
	{
		if (index < 0)
			index = s->a_size;
		if (index >= s->a_size / 2)
		{
			ft_r('a', s);
			index = index + 1;
		}
		else
		{
			ft_rr('a', s);
			index = ft_index(s, index, 'a');
		}
	}
}

int	rotate_b(t_stacks *s, int index)
{
	int	sa;

	sa = 0;
	while (index < s->b_size)
	{
		if (index < 0)
			index = s->b_size;
		if (s->b[s->b_size] == (s->b[index] - 1))
		{
			ft_p('a', s);
			sa = 1;
		}
		if (index >= s->b_size / 2 && index < s->b_size)
		{
			ft_r('b', s);
			index = index + 1;
		}
		else if (index < s->b_size)
		{
			ft_rr('b', s);
			index = ft_index(s, index, 'b');
		}
	}
	return (sa);
}

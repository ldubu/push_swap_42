/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:41:16 by ldubuche          #+#    #+#             */
/*   Updated: 2022/01/25 16:37:21 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move(t_stacks *s)
{
	int i;

	i = s->a_size/2;
	if (s->b[s->b_size] < s->a[s->a_size])
		ft_p('a', s);
	else if (s->b[s->b_size] > s->a[0] && s->b[s->b_size] < s->a[s->a_size])
	{
		ft_p('a',s);
		ft_rr('a', s, s->a_size + 1);
	}
	else if (s->b[s->b_size] > s->a[i])
	{
		while (s->a[s->a_size] < s->b[s->b_size])
			ft_rr('a', s, s->a_size + 1);
		ft_p('a', s);
	}
	else
	{
		while (s->a[s->a_size] > s->b[s->b_size])
			ft_r('a', s, s->a_size + 1);
		ft_p('a', s);
	}	
}
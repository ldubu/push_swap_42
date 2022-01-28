/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:34:29 by ldubuche          #+#    #+#             */
/*   Updated: 2022/01/28 13:30:48 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

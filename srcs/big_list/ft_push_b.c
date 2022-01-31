/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:38:40 by ldubuche          #+#    #+#             */
/*   Updated: 2022/01/31 15:39:45 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_push_b(t_stacks *s, int *start, int *max)
{
	s->i = s->a_size;
	ft_rotate(s, s->max_index - 1);
	*start = *max;
	s->max_index = 0;
	while (s->a_size >= *max || s->i == 0)
	{
		if (s->i > *start || s->i < s->max_index)
			ft_p('b', s);
		s->i = s->i - 1;
	}
}
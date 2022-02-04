/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:46:52 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/04 16:03:04 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_min_max(t_stacks *s)
{
	int	i;

	i = s->a_size;
	s->min = s->a[s->a_size];
	s->max = s->a[s->a_size];
	s->index = s->a_size;
	while (i >= 0)
	{
		if (s->a[i] < s->min)
		{
			s->min = s->a[i];
			s->index = i;
		}
		if (s->a[i] > s->max)
		{
			s->max = s->a[i];
		}
		i--;
	}
}

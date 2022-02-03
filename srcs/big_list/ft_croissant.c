/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_croissant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:16:58 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/03 16:33:56 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_croissant(t_stacks *s, int *start, int *max)
{
	int	temp;

	ft_min_max(s);
	s->j = 0;
	s->i = s->index;
	temp = 1;
	while (s->j < s->size - 1)
	{
		s->j = s->j + 1;
		ft_gagner_ligne(s, start, max, &temp);
		if (s->i != s->a_size)
			s->i = s->i - 1;
	}
}

void	ft_gagner_ligne(t_stacks *s, int *start, int *max, int *temp)
{
	if (s->i == 0)
	{
		if (s->a[s->i] > s->a[s->a_size])
		{
			if ((s->j - (*temp - 1)) > *max)
			{
				*max = (s->j - *temp - 1);
				s->max_index = s->i;
				*start = (s->i + *temp) % s->a_size;
			}
			*temp = s->j + 1;
		}
		s->i = s->a_size;
	}
	else if (s->a[s->i] > s->a[s->i - 1])
	{
		
		if ((s->j - (*temp -1)) > *max)
		{
			*max = s->j - (*temp -1);
			s->max_index = s->i;
			*start = (s->i + (*max -1)) % s->a_size;
		}
		*temp = s->j + 1;
	}
}

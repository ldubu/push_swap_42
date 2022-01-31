/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:49:06 by ldubuche          #+#    #+#             */
/*   Updated: 2022/01/31 12:48:38 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_big(t_stacks *s)
{
	int	start;
	int	max;
	int	i;

	start = 0;
	max = 0;
	ft_croissant(s, &start, &max);
	ft_push_b(s, &start, &max);
	i = s->size - 1;
	while (i >= 0)
		printf("%2d ", s->a[i--]);
	printf("\n");
	i = s->size -1 ;
	while (i >=0)
		printf("%2d ", s->b[i--]);
	printf("\n\n");
}

void	ft_push_b(t_stacks *s, int *start, int *max)
{
	s->i = s->a_size;
	
	if (*start < s->max_index)
	{       printf("start = %d, max_index = %d\n", *start, s->index);
			if (s->i < *start || s->i > s->max_index)
				ft_p('b', s);
			else
			{
				while ((*max)-- > 0)
				{
					ft_r('a', s, s->a_size + 1);
					*start = (*start + 1) % (s->i + 1);
					s->max_index = (s->max_index + 1) % s->i;
				}
			}
			s->i = s->i - 1;
	}
	else
	{
		while (s->i >= 0)
		{
			if (s->i > *start || s->i < s->max_index)
				ft_p('b', s);
			else
			{
				while ((*max)-- > 0)
				{
					ft_r('a', s, s->a_size + 1);
					*start = (*start + 1) % (s->i + 1);
					s->max_index = (s->max_index + 1) % s->i;
				}
			}
			s->i = s->i - 1;
		}
	}
}
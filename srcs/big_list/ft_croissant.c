/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_croissant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:16:58 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/04 17:39:20 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_croissant(t_stacks *s, int *start, int *end)
{
	int	temp;
	int i;
	int j;
	int max_temp;
	int max;

	ft_min_max(s);
	i = s->index;
	max = 0;
	//printf("min %d, max %d, index %d\n", s->min, s->max, s->index);
	while (i != ((s->index + 1) % s->a_size) )
	{
		//printf("i = %d ", i);
		j = ft_index(s, i, 'a');
		temp = s->a[i];
		max_temp = 2;
		while (s->a[j] < s->max)
		{
			if (s->a[j] > temp)
			{
				temp = s->a[j];
				max_temp++;
				//printf(" a[j] %d", s->a[j]);
			}
			j = ft_index(s, j, 'a');
		}
		
		if (max_temp > max)
		{
			*start = i;
			max = max_temp;
			*end = j;
			//printf(" new max !! max = %d", max);
		}
		i = ft_index(s, i, 'a');
		//printf("\n");

	}
	//printf("start %d, end %d\n", *start, *end);
	ft_push_b(s, start, end, max);
}

		
		/*printf("start %d max index %d max %d start[] %d\n", *start, s->max_index, *max, s->a[*start]);
		s->j = s->j + 1;
		ft_gagner_ligne(s, start, max, &temp);
		if (s->i != s->a_size)
			s->i = s->i - 1;
	}
	printf("start %d max index %d max %d start[] %d\n", *start, s->max_index, *max, s->a[*start]);
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
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:38:40 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/04 17:38:56 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_push_b(t_stacks *s, int *start, int *end, int max)
{
	int	temp;
	int i;
	int last;

	i = *start;
	temp = s->a[i];
	while (i < *end)
	{
		if (s->a[i] > temp)
			temp = s->a[i];
		i = ft_index(s, i, 'a');
		
	}
	i = s->a_size;
	while (i >= max)
	{
		//printf("i %d, temp %d end %d\n", i, temp, ft_abs(*end - *start));
		if ((s->a[i] > temp || s->a[i] == s->a[*start]) && i >= *start)
		{
			if (!last)
				last = s->a[i];
			temp = s->a[i];
			ft_r('a', s);
			*end = (*end + 1) % (s->a_size + 1);
			*start = (*start + 1) % (s->a_size + 1);
		}
		else
		{
			ft_p('b', s);
			i = ft_index(s, i, 'a');
		}
		if (last && s->a[i] == last)
			break ;
		/*int j= s->size - 1;
		while (j>= 0)
			printf("%2d ", s->a[j--]);
		printf("\n");
		j= s->size - 1 ;
		while (j>= 0)
			printf("%2d ", s->b[j--]);
		printf("\n\n");*/
	}
	
}
	


/*ft_r('a', s);
	*end = (*end + 1) % s->a_size;
	*start = (*start + 1) % s->a_size;
	temp = s->a[*start];
	while (s->a[i] < last)
	{
		printf("start %d\n", *start);
		if ((s->a[i] > temp || s->a[i] == s->a[*start]))
		{
			ft_r('a', s);
			temp = s->a[i];
		}
		else
		{
			ft_p('b', s);
			i = ft_index(s, i, 'a');
		}
		int j= s->size - 1;
		while (j>= 0)
			printf("%2d ", s->a[j--]);
		printf("\n");
		j= s->size - 1 ;
		while (j>= 0)
			printf("%2d ", s->b[j--]);
		printf("\n\n");
	}*/


	/*ft_rotate(s, s->max_index - 1);
	*start = *max;
	s->max_index = 0;
	while (s->a_size >= *max || s->i == 0)
	{
		if (s->i > *start || s->i < s->max_index)
			ft_p('b', s);
		s->i = s->i - 1;
	}
	int i = s->size - 1;
	while (i >= 0)
		printf("%2d ", s->a[i--]);
	printf("\n");
	i = s->size - 1 ;
	while (i >= 0)
		printf("%2d ", s->b[i--]);
	printf("\n\n");
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:49:06 by ldubuche          #+#    #+#             */
/*   Updated: 2022/01/28 16:53:47 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_big(t_stacks *s)
{
	int	start;
	int max;

	start = 0;
	max = 0;
	ft_croissant(s, &start, &max);
	printf("start index = %d, taille = %d\n", start, max);
	int i = 0;
	while (i++ < max)
		printf("%d ", s->a[start--]);
	printf("\n");
}

void	ft_croissant(t_stacks *s, int *start, int *max)
{
	int temp;
	int i;
	int j;

	ft_min_max(s);
	//printf("min = %d, index = %d\n", s->min, s->index);
	j = 0;
	i = s->index;
	temp = 1;
	while(j < s->size-1)
	{
		j++;
		//printf("i = %d, j = %d, temp = %d, *max = %d, *start = %d, nbr = %d, nbr+1 = %d\n", i, j, temp, *max, *start, s->a[i], s->a[i - 1]);
		if (i == 0)
		{
			//printf("IFFFFFFFF 0\n");
			if (s->a[i] > s->a[s->a_size])
			{ 
				if ((j - (temp - 1)) > *max)
				{
					//printf("condition ok \n");
					*max = (j - temp - 1);
					*start = (i + temp) % s->a_size;
				}
				temp = j + 1;
			}
			i = s->a_size;
		}
		else if (s->a[i] > s->a[i - 1])
		{
			//printf("autreif \n");
			if ((j - (temp -1)) > *max)
			{
				//printf("condition ok\n");
				*max = j - (temp -1);
				*start = (i + (*max -1)) % s->a_size;
				
			}
			temp =  j + 1;
			i--;
		}
		else 
			i--;
	}
}
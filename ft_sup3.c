/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sup3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:30:57 by ldubuche          #+#    #+#             */
/*   Updated: 2022/01/26 17:04:56 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sup3(t_stacks *s)
{
	int	i;

	i = ft_sort(s);
	if (i != -1)
	{
		i = s->size - 4;
		while (i-- > 0)
			ft_p('b', s);
	}
	//printf("%d %d %d %d %d\n", s->b[0], s->b[1], s->b[2], s->b[3], s->b[4]);
	//printf("%d %d %d %d %d\n", s->a[0], s->a[1], s->a[2], s->a[3], s->a[4]);
	i = ft_sort(s);
	int j = 10;
	while (i != -1 && j != 0)
	{
		//////printf("       i = %d index = %d\n", i, s->index);
		if (s->a[3] > s->a[2] && s->index != 2)
		{
			ft_s('a', s, 4);
		}
		else if (s->a[2] > s->a[1] && s->index != 1)
		{
			ft_r('a', s, 4);
			ft_s('a', s, 4);
		}
		else if (s->a[1] > s->a[0] && s->index != 0)
		{
			ft_r('a', s, 4);
			ft_r('a', s, 4);
			ft_s('a', s, 4);
		}
		else if (s->a[0] > s->a[3] && s->index != 3)
		{
			ft_rr('a', s, 4);
			ft_s('a', s, 4);
		}
		i = ft_sort(s);
		j--;
	}
	//printf("%d %d %d %d %d\n", s->b[0], s->b[1], s->b[2], s->b[3], s->b[4]);
	//printf("%d %d %d %d %d\n", s->a[0], s->a[1], s->a[2], s->a[3], s->a[4]);
	while (s->b_size >= 0)
	{
		j = s->b_size;
		i = s->a_size;
		if (s->b[j] > s->max || s->b[j] < s->min)
		{
			ft_rotate(s, s->index + 1);
			ft_p('a', s);
			i = 0;
		}
		else if (s->b[j] < s->a[s->a_size] && s->b[j] > s->a[0])
		{
			ft_p('a', s);
			i = 0;
		}		
		while (i > 0)
		{
			if (s->b[j] > s->a[i] && s->b[j] < s->a[i-1])
			{
				ft_rotate(s, i - 1);
				ft_p('a', s);
				i = 0;
			}
			i--;
		}
		s->b_size = s->b_size - 1;
	}
	//printf("%d %d %d %d %d\n", s->b[0], s->b[1], s->b[2], s->b[3], s->b[4]);
	//printf("%d %d %d %d %d\n", s->a[0], s->a[1], s->a[2], s->a[3], s->a[4]);
	ft_min_max(s);
	//printf("%d\n", s->index);
	ft_rotate(s, s->index + 1);
	//printf("%d %d %d %d %d\n", s->b[0], s->b[1], s->b[2], s->b[3], s->b[4]);
	//printf("%d %d %d %d %d\n", s->a[0], s->a[1], s->a[2], s->a[3], s->a[4]);

}

int	ft_sort(t_stacks *s)
{
	int	i;
	int j;

	ft_min_max(s);
	i = 0;
	while (i < 3 )
	{
		j = (i + (s->index + 1))  % (s->a_size + 1);
		//////printf("j = %d, j-1 = %d, i = %d, index = %d\n", j , ((j+1)% (s->a_size + 1)), i , s->index);
		if (s->a[j] < s->a[(j + 1) % (s->a_size + 1)])
		{
			////printf("              NOP\n");
			return (j);		
		}
		i++;
	}
	////printf("                      YAY\n");
	return (-1);
}

void	ft_min_max(t_stacks *s)
{
	int i;
	
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

void	ft_rotate(t_stacks *s, int index)
{
	while (index <= s->a_size)
	{
		if (index >= s->a_size / 2)
		{
			ft_r('a', s, s->a_size + 1);
			index = index + 1;
		}
		else 
		{
			ft_rr('a', s, s->a_size + 1);
			if (index == 0)
				index = s->a_size;
			else 
				index = index - 1;
		}
	}
}
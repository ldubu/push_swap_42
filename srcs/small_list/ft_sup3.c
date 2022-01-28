/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sup3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:30:57 by ldubuche          #+#    #+#             */
/*   Updated: 2022/01/28 13:30:56 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
	ft_sort4nbr(s);
	ft_pa(s);
	ft_min_max(s);
	ft_rotate(s, s->index);
}

int	ft_sort(t_stacks *s)
{
	int	i;
	int	j;

	ft_min_max(s);
	i = 0;
	while (i < 3)
	{
		j = (i + (s->index + 1)) % (s->a_size + 1);
		if (s->a[j] < s->a[(j + 1) % (s->a_size + 1)])
		{
			return (j);
		}
		i++;
	}
	return (-1);
}

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

void	ft_rotate(t_stacks *s, int index)
{
	while (index < s->a_size)
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

void	ft_sort4nbr(t_stacks *s)
{
	int	i;

	i = ft_sort(s);
	while (i != -1)
	{
		if (s->a[3] > s->a[2] && (s->max != s->a[3] || s->index != 2))
			ft_s('a', s, 4);
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
	}
}

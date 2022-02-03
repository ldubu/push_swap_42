/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sup3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:30:57 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/03 13:49:14 by ldubuche         ###   ########.fr       */
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

void	ft_sort4nbr(t_stacks *s)
{
	int	i;

	i = ft_sort(s);
	while (i != -1)
	{
		if (s->a[3] > s->a[2] && (s->max != s->a[3] || s->index != 2))
			ft_s('a', s);
		else if (s->a[2] > s->a[1] && s->index != 1)
		{
			ft_r('a', s);
			ft_s('a', s);
		}
		else if (s->a[1] > s->a[0] && s->index != 0)
		{
			ft_r('a', s);
			ft_r('a', s);
			ft_s('a', s);
		}
		else if (s->a[0] > s->a[3] && s->index != 3)
		{
			ft_rr('a', s);
			ft_s('a', s);
		}
		i = ft_sort(s);
	}
}

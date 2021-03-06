/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:43:57 by ldubuche          #+#    #+#             */
/*   Updated: 2022/01/28 15:07:39 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_is_sorted(t_stacks *s)
{
	int	i;

	i = s->size - 1;
	while (i > 0)
	{
		if (s->a[i] > s->a[i - 1])
		{
			if (s->size < 6)
				ft_small(s);
			else
				ft_big(s);
			i = -1;
		}
		i--;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:45:39 by ldubuche          #+#    #+#             */
/*   Updated: 2022/01/31 15:47:35 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

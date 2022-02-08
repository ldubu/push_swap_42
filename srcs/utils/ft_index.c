/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:58:58 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/08 10:05:01 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_index(t_stacks *s, int j, char c)
{
	if (c == 'a' && j == 0)
		return (s->a_size);
	else if (c == 'b' && j == 0)
		return (s->b_size);
	return (j - 1);
}

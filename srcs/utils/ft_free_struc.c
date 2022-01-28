/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_struc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:52:52 by ldubuche          #+#    #+#             */
/*   Updated: 2022/01/28 13:31:02 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_free_struc(t_stacks *s)
{
	if (s)
	{
		if (s->a)
			free(s->a);
		if (s->b)
			free(s->b);
		free(s);
	}
	return (0);
}

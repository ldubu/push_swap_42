/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:49:06 by ldubuche          #+#    #+#             */
/*   Updated: 2022/01/31 15:41:29 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_big(t_stacks *s)
{
	int	start;
	int	max;
	int	i;

	start = 0;
	max = 0;
	ft_croissant(s, &start, &max);
	ft_push_b(s, &start, &max);
	i = s->size - 1;
	while (i >= 0)
		printf("%2d ", s->a[i--]);
	printf("\n");
	i = s->size -1 ;
	while (i >=0)
		printf("%2d ", s->b[i--]);
	printf("\n\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:27:41 by ldubuche          #+#    #+#             */
/*   Updated: 2022/01/28 13:30:05 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_is_doublon(int *tab, int i, int nbr, int size)
{
	int	j;

	j = size - 1;
	while (j > i - 1)
	{
		if (tab[j] == nbr)
			return (1);
		j--;
	}
	return (0);
}

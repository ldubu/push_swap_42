/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:27:41 by ldubuche          #+#    #+#             */
/*   Updated: 2022/01/20 16:57:11 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_doublon(int *tab, int i, int nbr)
{
	int j;

	j = 0;
	//printf("tab %d nbr %d i %d\n", tab[j], nbr, i);
	while (j < i)
	{
		
		if (tab[j] == nbr)
			return (1);
		j++;
	}
	return(0);
}
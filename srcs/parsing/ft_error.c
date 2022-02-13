/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:43:07 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/13 15:42:43 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	*ft_error(int argc, char *argv[])
{
	int			*tab;
	int			size;
	long int	temp;

	argv++;
	size = argc - 1;
	tab = (int *) malloc (sizeof(int) * argc - 1);
	while (--argc > 0)
	{
		if (ft_isnbr(*argv) == 0 || ft_strlen(*argv) > 11)
		{
			free(tab);
			return (NULL);
		}
		temp = ft_atoips(*argv);
		if (temp > 2147483647 || temp < -2147483648
			|| ft_is_doublon(tab, argc, temp, size))
		{
			free(tab);
			return (NULL);
		}
		tab[argc - 1] = temp;
		argv++;
	}
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:41:16 by ldubuche          #+#    #+#             */
/*   Updated: 2022/01/18 18:41:16 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int *stack_a;
	int	i;

	i = 0;
	if (argc == 1)
		return (0);
	stack_a = ft_error(argc, argv);
	if (stack_a == NULL)
	{
		ft_putstr_fd("Error\n", 1);
		return(0);
	}
	while (--argc > 0)
	{
		printf("%d\n", stack_a[i]);
		i++;
	}
	return (0);
}

int	*ft_error(int argc, char *argv[])
{
	int	*tab;
	int	i;
	int	temp;

	i = 0;
	argv++;
	tab = (int *) malloc (sizeof(int) * argc);
	while (--argc > 0)
	{
		if (ft_isnbr(*argv) == 0)
			return (NULL);
		temp = ft_atoips(*argv);
		//printf("temp %d, tab %d, argv %s\n", temp, tab[i], *argv);
		if (ft_is_doublon(tab, i, temp))
			return(NULL);
		tab[i] = temp;
		
		i++;
		argv++;		
	}
	return (tab);
}
	
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

	if (argc == 1)
		return (0);
	stack_a = ft_error(argc, argv);
	if (stack_a == NULL)
	{
		ft_putstr_fd("Error\n", 1);
		return(0);
	}
	ft_is_sorted(stack_a, argc-1);
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
		if (ft_is_doublon(tab, i, temp))
			return(NULL);
		tab[i] = temp;
		
		i++;
		argv++;		
	}
	return (tab);
}

void	ft_is_sorted(int *stack_a, int size)
{
	int i;
	int j;

	i = size;
	j = 0;
	while (i-- > 1)
	{
		if (stack_a[j] > stack_a[j + 1])
		{
			if (size < 6)
				printf("tri algo petite stack\n");
			else
				printf("tri grande stack\n");
			i = 0;
		}
		j++;
	}
}
	
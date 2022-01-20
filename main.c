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
	t_list	*stack_a;
	if (argc == 1)
		return (0);
	stack_a = ft_error(argc, argv)
	else if (stack_a == NULL)
	{
		ft_putstr_fd("Error\n");
		return(0);
	}
	return (0);
}

t_list	*ft_error(int argc, char *argv[])
{
	argv++;
	while (--argc > 0)
	{
		if (ft_isnbr(*argv) == 0)
			return (NULL);
		
	}
}
	
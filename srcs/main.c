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

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stacks	*s;
	int			i;

	i = 0;
	if (argc == 1)
		return (0);
	s = (t_stacks *) malloc(sizeof(t_stacks));
	s->a = ft_error(argc, argv);
	s->b = (int *) malloc (sizeof(int) * argc - 1);
	if (s->a == NULL)
	{
		ft_putstr_fd("Error\n", 1);
		return (ft_free_struc(s));
	}
	s->size = argc - 1;
	while (i < s->size)
		s->b[i++] = 0;
	s->a_size = s->size - 1;
	s->b_size = -1;
	ft_is_sorted(s);
	return (ft_free_struc(s));
}

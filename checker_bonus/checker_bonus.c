/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:35:36 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/09 13:35:36 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

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
	get_args(s);
	return (ft_free_struc(s));
}

void	get_args(t_stacks *s)
{
	char	*line;
	int		error;

	error = 0;
	line = get_next_line(0);
	while (line && error == 0)
	{
		if (error == 0)
		{
			error = do_instruction(line, s);
			if (error == 1)
				ft_putstr_fd("Error\n", 1);
		}
		free(line);
		if (error == 0)
			line = get_next_line(0);
	}
	if (is_sorted(s) && !error)
		ft_putstr_fd("OK\n", 1);
	else if (!error)
		ft_putstr_fd("KO\n", 1);
}

int	do_instruction(char *line, t_stacks *s)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sc('a', s);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sc('b', s);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		sc('s', s);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		p('a', s);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		p('b', s);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		r('a', s);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		r('b', s);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		r('r', s);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rr('a', s);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rr('b', s);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rr('r', s);
	else
		return (1);
	return (0);
}

int	is_sorted(t_stacks *s)
{
	int	i;

	i = s->size - 1;
	while (i > 0)
	{
		if (s->a[i] > s->a[i - 1])
			return (0);
		i--;
	}
	return (1);
}

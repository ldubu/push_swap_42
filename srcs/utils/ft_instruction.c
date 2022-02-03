/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:00:36 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/03 16:35:37 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_s(char c, t_stacks *s)
{
	int	temp;
	int	*stack;
	int size;

	if (c == 's')
		ft_s('u', s);
	stack = ft_abr(c, s, &size);
	temp = stack[size];
	stack[size] = stack[size - 1];
	stack[size - 1] = temp;
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("sb\n", 1);
	else if (c == 's')
		ft_putstr_fd("ss\n", 1);
}

void	ft_rr(char c, t_stacks *s)
{
	int	temp;
	int	i;
	int	*stack;
	int size;

	if (c == 'r')
		ft_rr('u', s);
	stack = ft_abr(c, s, &size);
	temp = stack[0];
	i = 0;
	while (size >= 0)
	{
		stack[i] = stack[i + 1];
		i++;
		size --;
	}
	stack[i - 1] = temp;
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
	else if (c == 'r')
		ft_putstr_fd("rrr\n", 1);
}

void	ft_r(char c, t_stacks *s)
{
	int	temp;
	int	i;
	int	*stack;
	int size;

	if (c == 'r')
		ft_r('u', s);
	stack = ft_abr(c, s, &size);
	temp = stack[size];
	i = size;
	while (size-- > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = temp;
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rb\n", 1);
	else if (c == 'r')
		ft_putstr_fd("rr\n", 1);
}

void	ft_p(char c, t_stacks *s)
{
	if (c == 'a')
	{
		s->a[s->a_size + 1] = s->b[s->b_size];
		s->b[s->b_size] = 0;
		s->a_size = s->a_size + 1;
		s->b_size = s->b_size - 1;
		ft_putstr_fd("pa\n", 1);
	}
	else
	{
		s->b[s->b_size + 1] = s->a[s->a_size];
		s->a[s->a_size] = 0;
		s->b_size = s->b_size + 1;
		s->a_size = s->a_size - 1;
		ft_putstr_fd("pb\n", 1);
	}

}
/*	int j;
	j = s->size-1;
	printf("pb\n");
	while (j >= 0)
		printf("%2d ", s->a[j--]);
	printf("\n");
	j = s->size-1;
	while (j >=0)
		printf("%2d ", s->b[j--]);
	printf("\n\n");*/

int	*ft_abr(char c, t_stacks *s, int *size)
{
	int	*stack;

	if (c == 'a' || c == 'u')
	{
		stack = s->a;
		*size = s->a_size;
	}
	else if (c == 'b' || c == 's' || c == 'r')
	{
		stack = s->b;
		*size = s->b_size;
	}
	return (stack);
}

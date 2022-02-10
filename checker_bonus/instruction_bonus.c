/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:08:55 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/10 10:19:44 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	sc(char c, t_stacks *s)
{
	int	temp;
	int	*stack;
	int	size;

	if (c == 's')
		sc('u', s);
	stack = abr(c, s, &size);
	temp = stack[size];
	stack[size] = stack[size - 1];
	stack[size - 1] = temp;
}

void	rr(char c, t_stacks *s)
{
	int	temp;
	int	i;
	int	*stack;
	int	size;

	if (c == 'r')
		rr('u', s);
	stack = abr(c, s, &size);
	temp = stack[0];
	i = 0;
	while (size >= 0)
	{
		stack[i] = stack[i + 1];
		i++;
		size --;
	}
	stack[i - 1] = temp;
}

void	r(char c, t_stacks *s)
{
	int	temp;
	int	i;
	int	*stack;
	int	size;

	if (c == 'r')
		r('u', s);
	stack = abr(c, s, &size);
	temp = stack[size];
	i = size;
	while (size-- > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = temp;
}

void	p(char c, t_stacks *s)
{
	if (c == 'a')
	{
		s->a[s->a_size + 1] = s->b[s->b_size];
		s->b[s->b_size] = 0;
		s->a_size = s->a_size + 1;
		s->b_size = s->b_size - 1;
	}
	else
	{
		s->b[s->b_size + 1] = s->a[s->a_size];
		s->a[s->a_size] = 0;
		s->b_size = s->b_size + 1;
		s->a_size = s->a_size - 1;
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

int	*abr(char c, t_stacks *s, int *size)
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

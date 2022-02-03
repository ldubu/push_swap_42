/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:18:56 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/03 14:24:43 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct stacks
{
	int	*a;
	int	*b;
	int	size;
	int	a_size;
	int	b_size;
	int	min;
	int	max;
	int	max_index;
	int	index;
	int	i;
	int	j;
	
}		t_stacks;

typedef struct cost
{
	int min;
	int min_r_rota;
	int min_r;
	int min_a;
	int min_b;
	int a;
	int b;
	int r_rota;
	int r;
}		t_cost;

#endif
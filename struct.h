/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:18:56 by ldubuche          #+#    #+#             */
/*   Updated: 2022/01/26 15:35:44 by ldubuche         ###   ########.fr       */
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
	int min;
	int max;
	int index;
}		t_stacks;

#endif
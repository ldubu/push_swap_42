/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:25:51 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/10 09:25:51 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

int		is_sorted(t_stacks *s);
int		do_instruction(char *line, t_stacks *s);
void	get_args(t_stacks *s);
int		*abr(char c, t_stacks *s, int *size);
void	p(char c, t_stacks *s);
void	r(char c, t_stacks *s);
void	rr(char c, t_stacks *s);
void	sc(char c, t_stacks *s);

#endif
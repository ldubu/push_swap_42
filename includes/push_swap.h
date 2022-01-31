/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:42:17 by ldubuche          #+#    #+#             */
/*   Updated: 2022/01/18 18:42:17 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "struct.h"

int		ft_isnbr(char *str);
int		*ft_error(int argc, char *argv[]);
int		ft_is_doublon(int tab[], int i, int nbr, int size);
int		ft_atoips(const char *str);
int		ft_free_struc(t_stacks *s);
int		*ft_abr(char c, t_stacks *s);
int		ft_sort(t_stacks *s);
int		ft_abs(int x);

void	ft_is_sorted(t_stacks *s);
void	ft_small(t_stacks *s);
void	ft_3nbr(t_stacks *s);
void	ft_s(char c, t_stacks *s, int size);
void	ft_r(char c, t_stacks *s, int size);
void	ft_rr(char c, t_stacks *s, int size);
void	ft_p(char c, t_stacks *s);
void	ft_sup3(t_stacks *s);
void	ft_move(t_stacks *s);
void	ft_min_max(t_stacks *s);
void	ft_rotate(t_stacks *s, int index);
void	ft_pa(t_stacks *s);
void	ft_pa2(t_stacks *s, int i, int j);
void	ft_sort4nbr(t_stacks *s);
void	ft_big(t_stacks *s);
void	ft_croissant(t_stacks *s, int *start, int *max);
void	ft_gagner_ligne(t_stacks *s, int *start, int *max, int *temp);
void	ft_push_b(t_stacks *s, int *start, int *max);


#endif

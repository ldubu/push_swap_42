/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 09:32:21 by ldubuche          #+#    #+#             */
/*   Updated: 2022/01/28 13:23:02 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBER_H
# define NUMBER_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int	ft_atoi(const char *str);
int is_in_tab(int tab[], int nbr, int i);

#endif
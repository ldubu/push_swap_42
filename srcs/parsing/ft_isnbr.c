/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:44:02 by ldubuche          #+#    #+#             */
/*   Updated: 2022/01/18 20:44:02 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_isnbr(char *str)
{
	if ((*str == '-' || *str == '+' )&& ft_strlen(str) > 1)
		str++;
	while (*str)
	{
		if ((*str < 48 || *str > 57))
			return (0);
		str++;
	}
	return (1);
}

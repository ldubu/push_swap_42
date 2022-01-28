/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoips.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:51:55 by ldubuche          #+#    #+#             */
/*   Updated: 2022/01/18 20:51:55 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_atoips(const char *str)
{
	int	num;
	int	sign;

	sign = 1;
	num = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		num = num * 10 + *str - 48;
		str++;
	}
	return (num * sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 09:31:56 by ldubuche          #+#    #+#             */
/*   Updated: 2022/01/28 16:05:29 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 09:31:56 by ldubuche          #+#    #+#             */
/*   Updated: 2022/01/26 16:04:16 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "number.h"

int main(int argc, char *argv[])
{
	int min, max, voulu = 0, i = 0, nbr = 0;

	srand((long int) time(0) + getpid());
	if (argc != 4)
	{
		printf("Veuillez entrer les parametres ainsi\n");
		printf("./generate nbr_voulu");
		exit(0);
	}
	voulu = ft_atoi(argv[1]);
	min = ft_atoi(argv[2]);
	max = ft_atoi(argv[3]);
	int tab[voulu];
	while (i < voulu)
	{
		nbr = (rand() % max);
		while (is_in_tab(tab, nbr, i))
		{
			nbr = rand() % (max + 1 - min) + min;
		}
		tab[i] = nbr;
		i++;
	}
	i = 0;
	while (i < voulu - 1)
	{
		printf("%2.2d ", tab[i]);
		i++;
	}
	printf("%2.2d ", tab[i]);
	return(0);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;

	sign = 1;
	num = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - 48;
		str++;
	}
	return (num * sign);
}

int is_in_tab(int tab[], int nbr, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (tab[j] == nbr)
			return (1);
		j++;
	}
	return(0);
}
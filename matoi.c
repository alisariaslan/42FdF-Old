/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:08:03 by msariasl          #+#    #+#             */
/*   Updated: 2023/03/10 13:08:24 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	matoi(char *arg)
{
	int			i;
	int	total;
	int	stair;
	int			n;

	i = 0;
	while (arg[++i])
		;
	i--;
	total = 0;
	stair = 1;
	while (arg[i] > 47 && arg[i] < 58)
	{
		n = arg[i--] - 48;
		total += n * stair;
		stair *= 10;
	}
	if (arg[0] == '-')
		total *= -1;
	return (total);
}
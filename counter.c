/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:05:36 by msariasl          #+#    #+#             */
/*   Updated: 2023/03/10 13:11:48 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	char_counter(char *chars)
{
	int	i;

	i = 0;
	while (chars[i])
	{
		i++;
	}
	return (i);
}

int	step_counter(int n)
{
	int	steps;

	steps = 1;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		n /= 10;
		steps++;
	}
	return (steps);
}
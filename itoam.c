/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoam.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:06:56 by msariasl          #+#    #+#             */
/*   Updated: 2023/03/10 13:09:06 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*itoam(int n)
{
	int malsize;
	int steps;
	char *new;

	malsize = 1;
	if (n < 0)
	{
		n *= -1;
		malsize++;
	}
	steps = step_counter(n);
	if (malsize == 2)
		steps++;
	new = malloc(sizeof(char) * steps + malsize);
	new[steps--] = 0;
	if (malsize == 2)
		new[0] = '-';
	while (n >= 10)
	{
		new[steps--] = n % 10 + 48;
		n /= 10;
	}
	new[steps--] = n % 10 + 48;
	return (new);
}
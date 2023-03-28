/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:36:10 by msariasl          #+#    #+#             */
/*   Updated: 2023/03/28 12:40:25 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_button(int key, void *vars)
{
	exit(0);
	return (key);
}

int	keyboard_click(int key, p_vars *vars)
{
	printf("key: %d\n", key);
	if (key == KEY_ESC_UBUNTU)
		exit_button(65307, vars);
	if (key == 'w')
	{
	}
	if (key == 's')
	{
	}
	if (key == 'd')
	{
	}
	if (key == 'a')
	{
	}
	return (key);
}

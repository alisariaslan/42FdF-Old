/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:36:10 by msariasl          #+#    #+#             */
/*   Updated: 2023/03/30 19:42:13 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_button(int key, void *vars)
{
	exit(0);
	return (key);
}

int	keyboard_click(int key, t_vars *vars)
{
	ft_printf("key: %d\n", key);
	if (key == KEY_ESC)
		exit_button(key, vars);
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

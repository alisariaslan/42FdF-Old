/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorwrite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:24:30 by msariasl          #+#    #+#             */
/*   Updated: 2023/04/25 09:54:39 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_red(void)
{
	ft_printf("\033[1;31m");
}

void	print_green(void)
{
	ft_printf("\033[1;32m");
}

void	print_yellow(void)
{
	ft_printf("\033[1;33m");
}

void	print_color_reset(void)
{
	ft_printf("\033[0m");
}

void	fc_printf(char *text, int r, int g, int y)
{
	if (r == 1)
		print_red();
	else if (g == 1)
		print_green();
	else if (y == 1)
		print_yellow();
	ft_printf("%s", text);
	print_color_reset();
}

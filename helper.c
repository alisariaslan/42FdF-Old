/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:38:35 by msariasl          #+#    #+#             */
/*   Updated: 2023/04/25 09:52:31 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_fd(int fd)
{
	if (fd < 0)
		exit_program(1, "Error! Map file error occured");
	return (fd);
}

void	show_invalid_file_input(char *argv0)
{
	print_red();
	ft_printf("Error: Your file input is invalid!\n");
	ft_printf("You can use like that -> ");
	ft_printf("%s map.fdf\n", argv0);
	print_color_reset();
}

void	how_to_control(void)
{
	print_yellow();
	ft_printf("\nMAP CONTROLS:\n");
	ft_printf("ESC		-> Exit\n");
	ft_printf("R  		-> Reset Position\n");
	ft_printf("C		-> Reset Color\n");
	ft_printf("W, A, S, D	-> Move Map\n");
	ft_printf("Q, E	-> Zoom\n");
	ft_printf("T, Y	-> Altitude\n");
	ft_printf("P	-> Projection Switch\n");
	ft_printf("B -> Blue\n");
	ft_printf("G -> Green\n");
	ft_printf("K, L -> Map Strech\n\n");
	print_color_reset();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:35:15 by ali               #+#    #+#             */
/*   Updated: 2023/04/02 03:56:20 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"




void	read_map(char *file, t_fdf *fdf)
{
	int fd;
	int x;
	int y;
	char *line;

	x = 0;
	y = 0;
	fdf->map.breadth = count_lines(file,fdf);
}

void	close_program(char *closing_text, int exit_code)
{
	ft_printf("\n\033[03;33m%s\n", closing_text);
	exit(exit_code);
}

void	init_program(char *argv1, t_fdf *fdf)
{
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		close_program("Malloc fail!", 0);
	read_map(argv1,fdf);
	
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc == 2)
		init_program(argv[1], fdf);
	else
		show_invalid_file_input(argv[0]);
	return (0);
}

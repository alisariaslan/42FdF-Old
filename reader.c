/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 08:48:55 by msariasl          #+#    #+#             */
/*   Updated: 2023/04/20 11:58:55 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	verify_line(char *line)
{
	while (*line)
	{
		if (!ft_isdigit(*line) && *line != ' ' && *line != '\n' && *line != '-' && *line != '+')
			exit_program(1,"Error! Map has different characters than expected. Ex:(digit,'newline','minus','positive')");
		line++;
	}
}

static void	apply_values(t_fdf *fdf, int x, int y, char *line)
{
	int		i;
	char	**vals;

	vals = ft_split(line, ' ');
	if (vals)
	{
		i = 0;
		while (vals[i] && (x != fdf->map.line_count))
		{
			fdf->map.vals[y][x] = ft_atoi(vals[i]);
			i++;
			x++;
		}
		free(vals);
	}
}

void	read_map(char *file, t_fdf *fdf)
{
	int fd;
	int x;
	int y;
	char *line;

	x = 0;
	y = 0;
	fdf->map.char_count = count_lines(file, fdf);
	fdf->map.vals = (int **)malloc(sizeof(int *) * fdf->map.char_count);
	if (!fdf->map.vals)
		exit_program(1,"Error! Not enough memory space for map.vals[][]");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_program(1,"Error! Map opening error occured");
	line = get_next_line(fd);
	while (line)
	{
		fdf->map.vals[y] = (int *)malloc(sizeof(int) * fdf->map.line_count);
		if (!fdf)
			exit_program(1,"Error! Not enough memory space for map.vals[y]");
		verify_line(line);
		apply_values(fdf, x, y, line);
		x = 0;
		y++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	if (close(fd) < 0)
		exit_program(1,"Error! Map closing error occured");
}
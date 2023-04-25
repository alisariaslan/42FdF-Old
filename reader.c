/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 08:48:55 by msariasl          #+#    #+#             */
/*   Updated: 2023/04/25 10:02:40 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	verify_line(char *line)
{
	fc_printf(line, 1, 0, 0);
	while (*line)
	{
		if (!ft_isdigit(*line) && *line != ' ' && *line != '\n' && *line != '-'
			&& *line != '+')
			exit_program(1, "Error! Map has different characters than expected. \
			Ex:(digit,'newline','minus','positive')");
		line++;
	}
}

static void	apply_values(t_fdf *fdf, int x, int y, char *line)
{
	int		i;
	char	**vals;

	vals = ft_split(line, ' ');
	i = 0;
	while (vals[i] && (x != fdf->map.char_count))
	{
		fdf->map.vals[y][x] = ft_atoi(vals[i]);
		free(vals[i]);
		i++;
		x++;
	}
	free(vals[i]);
	free(vals);
}

void	read_map(char *file, t_fdf *fdf, int x, int y)
{
	int		fd;
	char	*line;

	fdf->map.line_count = count_lines(file, fdf, 0, 0);
	fdf->map.vals = (int **)malloc(sizeof(int *) * fdf->map.line_count);
	if (!fdf->map.vals)
		exit_program(1, "Error! Not enough memory space for map.vals[][]");
	fd = check_fd(open(file, O_RDONLY));
	fc_printf("\nTHE MAP:\n", 0, 0, 1);
	line = get_next_line(fd);
	while (line)
	{
		fdf->map.vals[y] = (int *)malloc(sizeof(int) * fdf->map.char_count);
		if (!fdf)
			exit_program(1, "Error! Not enough memory space for map.vals[y]");
		verify_line(line);
		apply_values(fdf, x, y, line);
		x = 0;
		y++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	check_fd(close(fd));
}

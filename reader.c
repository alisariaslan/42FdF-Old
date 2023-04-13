/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 08:48:55 by msariasl          #+#    #+#             */
/*   Updated: 2023/04/13 21:50:06 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	verify_line(char *line)
{
	while (*line)
	{
		if (!ft_isdigit(*line) && *line != ' ' && *line != '\n')
			close_program("fdf.c -> Map has different characters other than numbers!", 0);
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
		while (vals[i] && (x != fdf->map.len))
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
	fdf->map.breadth = count_lines(file, fdf);
	fdf->map.vals = (int **)malloc(sizeof(int *) * fdf->map.breadth);
	if (!fdf->map.vals)
		close_program("fdf.c -> Map values allocation error!", 0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		close_program("fdf.c -> Map Open Error!", 0);
	line = get_next_line(fd);
	while (line)
	{
		fdf->map.vals[y] = (int *)malloc(sizeof(int) * fdf->map.len);
		if (!fdf)
			close_program("fdf.c -> Map y values malloc fail!", 0);

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
		close_program("fdf.c -> Map CLOSE Error!", 0);
}
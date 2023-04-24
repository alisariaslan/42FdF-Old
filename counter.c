/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 03:54:40 by msariasl          #+#    #+#             */
/*   Updated: 2023/04/24 22:19:45 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_words(char *text, char divider)
{
	int		n;
	char	**split;

	n = 0;
	split = ft_split(text, divider);
	while (*split)
	{
		n++;
		split++;
	}
	return (n);
}

static void	warn_before_exit(char *file, int rows, int cols, int len)
{
	ft_printf("\nError Target: %s\nError Row: %d\nExpected Count: \
					%d\nError Count: %d", file, rows + 1, cols, len);
	exit_program(1, "Error! This map has different char counts");
}

int	count_lines(char *file, t_fdf *fdf, int rows, int columns)
{
	int		length;
	int		fd;
	char	*line;

	fd = check_fd(open(file, O_RDONLY));
	line = get_next_line(fd);
	while (line)
	{
		if (line == 0)
			break ;
		length = count_words(line, ' ');
		if (columns == 0)
			columns = length;
		if (columns == length)
			rows++;
		else
			warn_before_exit(file, rows, columns, length);
		free(line);
		line = get_next_line(fd);
	}
	if (rows < 4 || length < 4)
		exit_program(1, "Error! This map is smaller than 3x3 area");
	close(fd);
	fdf->map.line_count = length;
	return (rows);
}

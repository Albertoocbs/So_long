/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:37:32 by aoutumur          #+#    #+#             */
/*   Updated: 2025/02/06 13:15:19 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "mlx/minilibx-linux/mlx.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	**read_map(const char *filename, int *rows, int *cols)
{
	FILE	*file;
	char	**map;
	int		row_count;
	char	buffer[1024];
	size_t	line_length;

	file = fopen(filename, "r");
	if (!file)
	{
		perror("Error opening file");
		return (NULL);
	}
	map = NULL;
	row_count = 0;
	*cols = 0;
	while (fgets(buffer, sizeof(buffer), file))
	{
		line_length = strlen(buffer);
		if (buffer[line_length - 1] == '\n')
			buffer[line_length - 1] = '\0';
		else
			line_length++;
		if (*cols == 0)
			*cols = line_length - 1;
		map = realloc(map, sizeof(char *) * (row_count + 1));
		if (!map)
		{
			perror("Memory allocation error");
			fclose(file);
			return (NULL);
		}
		map[row_count] = malloc(line_length);
		if (!map[row_count])
		{
			perror("Memory allocation error");
			fclose(file);
			return (NULL);
		}
		strcpy(map[row_count], buffer);
		row_count++;
	}
	fclose(file);
	*rows = row_count;
	return (map);
}

/*int	count_lines(const char *filename)
{
	int		fd;
	int		lines;
	char	buffer[1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (-1);
	}
	lines = 0;
	while (read(fd, buffer, 1) > 0)
		if (buffer[0] == '\n')
			lines++;
	close(fd);
	return (lines + 1);
}

char	**allocate_map(int rows, int cols)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * rows);
	if (!map)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		map[i] = malloc(sizeof(char) * (cols + 1));
		if (!map[i])
			return (NULL);
		i++;
	}
	return (map);
}

int	open_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		perror("Error opening file");
	return (fd);
}

char	**read_map(const char *filename, int *rows, int *cols)
{
	int		fd;
	int		row_count;
	char	buffer[1024];
	char	**map;

	*rows = count_lines(filename);
	if (*rows <= 0)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (NULL);
	}
	row_count = 0;
	map = allocate_map(*rows, *cols);
	if (!map)
		return (NULL);
	while (read(fd, buffer, sizeof(buffer) - 1) > 0)
	{
		buffer[ft_strlen(buffer) - 1] = '\0';
		ft_strlcpy(map[row_count], buffer, *cols);
		row_count++;
	}
	close(fd);
	return (map);
}*/

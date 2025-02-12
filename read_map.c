/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:37:32 by aoutumur          #+#    #+#             */
/*   Updated: 2025/02/12 11:08:46 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "mlx/minilibx-linux/mlx.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	count_map_rows(const char *filename)
{
	char	buffer[1];
	int		rows;
	int		fd;

	fd = 0;
	rows = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, buffer, 1) > 0)
		if (buffer[0] == '\n')
			rows++;
	close(fd);
	return (rows);
}

int	get_map_cols(const char *filename)
{
	char	buffer[1];
	int		cols;
	int		fd;

	fd = 0;
	cols = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: Cannot open file to count columns\n");
		return (0);
	}
	while (read(fd, buffer, 1) > 0 && buffer[0] != '\n')
		cols++;
	close(fd);
	return (cols);
}

char	**allocate_map_grid(int rows, int cols)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (rows + 1));
	if (!map)
	{
		ft_printf("Error: Failed to allocate map grid\n");
		return (NULL);
	}
	i = 0;
	while (i < rows)
	{
		map[i] = malloc(cols + 1);
		if (!map[i])
		{
			ft_printf("Error: Failed to allocate row %d\n", i);
			free_map(map, i);
			return (NULL);
		}
		i++;
	}
	map[rows] = NULL;
	return (map);
}

void	fill_map_grid(char **map, int fd, int rows, int cols)
{
	int		i;
	char	*buffer;

	buffer = malloc(sizeof(char) * (cols + 2));
	if (!buffer)
	{
		perror("Erreur d'allocation mémoire");
		exit(1);
	}
	i = 0;
	while (i < rows)
	{
		if (read(fd, buffer, cols + 1) <= 0)
			break ;
		buffer[cols] = '\0';
		ft_strlcpy(map[i], buffer, cols + 1);
		i++;
	}
	buffer[cols + 1] = '\0';
	free(buffer);
}

char	**read_map(const char *filename, int *rows, int *cols)
{
	int		fd;
	char	**map;

	*rows = count_map_rows(filename);
	*cols = get_map_cols(filename);
	if (*rows == 0 || *cols == 0)
	{
		ft_printf("Error: Invalid map dimensions\n");
		return (NULL);
	}
	map = allocate_map_grid(*rows, *cols);
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: Cannot open file to read map\n");
		free_map(map, *rows);
		return (NULL);
	}
	fill_map_grid(map, fd, *rows, *cols);
	close(fd);
	return (map);
}

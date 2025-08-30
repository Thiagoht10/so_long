/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:14:51 by thde-sou          #+#    #+#             */
/*   Updated: 2025/08/31 00:33:36 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all_arr(char **arr)
{
	int	a;

	a = 0;
	if (!arr)
		return ;
	while (arr[a])
	{
		free(arr[a]);
		a++;
	}
	free(arr);
}

size_t	ft_strlen_new(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

int	count_lines_fd(char **argv)
{
	int		fd;
	int		count_line;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	count_line = 0;
	line = get_next_line(fd);
	while (line)
	{
		count_line++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count_line);
}

char	*get_line(int fd)
{
	char	*line;
	int		len;
	char	*output_line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	len = ft_strlen_new(line);
	output_line = malloc((len + 1) * sizeof(char));
	if (!output_line)
		return (NULL);
	ft_strlcpy(output_line, line, len + 1);
	free(line);
	return (output_line);
}

char	**make_map(char **argv)
{
	char	**map;
	char	*line;
	int		size;
	int		fd;
	int		i;

	i = 0;
	fd = safe_open(argv);
	size = count_lines_fd(argv);
	map = malloc((size + 1) * sizeof(char *));
	if (!map)
		return (close(fd), NULL);
	while (i < size)
	{
		line = get_line(fd);
		map[i] = malloc((ft_strlen(line) + 1) * sizeof(char));
		if (!map[i])
			double_pointer_error(fd, map, line);
		ft_strlcpy(map[i], line, ft_strlen(line) + 1);
		free(line);
		i++;
	}
	map[size] = NULL;
	close(fd);
	return (map);
}

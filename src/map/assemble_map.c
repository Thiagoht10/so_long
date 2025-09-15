/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:14:51 by thde-sou          #+#    #+#             */
/*   Updated: 2025/09/15 15:29:56 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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
		return (free(line), NULL);
	ft_strlcpy(output_line, line, len + 1);
	free(line);
	return (output_line);
}

char	**make_map(char **argv)
{
	t_data	data;

	data.i = 0;
	data.fd = safe_open(argv);
	data.size = count_lines_fd(argv);
	if (data.size < 3)
		return (close(data.fd), format_error(), NULL);
	data.map = malloc((data.size + 1) * sizeof(char *));
	if (!data.map)
		return (close(data.fd), NULL);
	while (data.i < data.size)
	{
		data.line = get_line(data.fd);
		if (!data.line)
			return (double_pointer_error(data.fd, data.map, data.line), NULL);
		data.map[data.i] = malloc((ft_strlen(data.line) + 1) * sizeof(char));
		if (!data.map[data.i])
			return (double_pointer_error(data.fd, data.map, data.line), NULL);
		ft_strlcpy(data.map[data.i], data.line, ft_strlen(data.line) + 1);
		free(data.line);
		data.i++;
	}
	data.map[data.size] = NULL;
	close(data.fd);
	return (data.map);
}

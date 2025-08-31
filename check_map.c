/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 05:20:04 by thde-sou          #+#    #+#             */
/*   Updated: 2025/08/31 17:41:25 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_format(char **map)
{
	int		i;
	size_t	len;
	size_t	compare_len;

	if (!map)
		return (-1);
	i = 1;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		compare_len = ft_strlen(map[i]);
		if (compare_len != len)
			return (format_error(), FALSE);
		i++;
	}
	return (TRUE);
}

int	check_wall(char **map)
{
	t_data	data;

	data.i = 1;
	data.len = ft_strlen(map[0]);
	data.size = count_map_lines(map);
	while (map[data.i])
	{
		data.j = 0;
		while (map[data.i][data.j] != '\0')
		{
			if (map[0][data.j] != '1')
				return (wall_error(), FALSE);
			if (map[data.i][0] != '1' || map[data.i][data.len - 1] != '1')
				return (wall_error(), FALSE);
			if (map[data.size - 1][data.j] != '1')
				return (wall_error(), FALSE);
			data.j++;
		}
		data.i++;
	}
	return (TRUE);
}

int	check_items(char **map)
{
	t_data	data;

	inits_check_items(&data);
	while (map[data.i])
	{
		data.j = 0;
		while (map[data.i][data.j] != '\0')
		{
			if (map[data.i][data.j] == 'P')
				data.player += 1;
			if (map[data.i][data.j] == 'C')
				data.collectibles += 1;
			if (map[data.i][data.j] == 'E')
				data.exit += 1;
			data.j++;
		}
		data.i++;
	}
	if (data.player != 1)
		return (items_error(&data), FALSE);
	if (data.collectibles < 1)
		return (items_error(&data), FALSE);
	if (data.exit != 1)
		return (items_error(&data), FALSE);
	return (TRUE);
}

int	find_player(char **map, int coordinates[2])
{
	t_data	data;

	data.i = 0;
	while (map[data.i])
	{
		data.j = 0;
		while (map[data.i][data.j] != '\0')
		{
			if (map[data.i][data.j] == 'P')
			{
				coordinates[0] = data.i;
				coordinates[1] = data.j;
				return (TRUE);
			}
			data.j++;
		}
		data.i++;
	}
	return (FALSE);
}

int check_path(char **map)
{
    t_data data;

    data.map = copy_map(map);
	if (!data.map)
		return (-1);
    data.size = count_map_lines(map);
    data.len = ft_strlen(data.map[0]);
    find_player(data.map, data.coordinates);
    walk_path(&data, data.coordinates[0], data.coordinates[1]);
    if(check_leftover_items(data.map))
    {
        free_all_arr(data.map);
        return (TRUE);
    }
    free_all_arr(data.map);
    return (path_error(), FALSE);
}

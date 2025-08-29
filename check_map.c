/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 05:20:04 by thde-sou          #+#    #+#             */
/*   Updated: 2025/08/29 05:16:27 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_format(char **map)
{
    int i;
    size_t len;
    size_t compare_len;

    if (!map)
        return (-1);
    i = 1;
    len = ft_strlen(map[0]);
    while(map[i])
    {
        compare_len = ft_strlen(map[i]);
        if(compare_len != len)
            return(0);
        i++;
    }
    return (1);
}

int check_wall(char **map)
{
    t_data data;

    data.i = 1;
    data.len = ft_strlen(map[0]);
    data.size = count_map_lines();
    while(map[data.i])
    {
        data.j = 0;
        while(map[data.i][data.j] != '\0')
        {
            if(map[0][data.j] != '1')
                return (0);
            if(map[data.i][0] != '1' || map[data.i][data.len - 1] != '1')
                return (0);
            if(map[data.size - 1][data.j] != '1')
                return (0);
            data.j++;
        }
        data.i++;
    }
    return (1);
}

int check_items(char **map)
{
    t_data data;

    inits_check_items(&data);
    while(map[data.i])
    {
        data.j = 0;
        while (map[data.i][data.j] != '\0')
        {
            if(map[data.i][data.j] == 'P')
                data.player += 1;
            if(map[data.i][data.j] == 'C')
                data.collectibles += 1;
            if(map[data.i][data.j] == 'E')
                data.exit += 1;
            data.j++;
        }
        data.i++;
    }
    if(data.player != 1)
        return (0);
    if(data.collectibles < 1)
        return (0);
    if(data.exit != 1)
        return (0);
    return (1);
}

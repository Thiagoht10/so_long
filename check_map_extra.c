/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:22:58 by thde-sou          #+#    #+#             */
/*   Updated: 2025/08/31 17:40:44 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    walk_path(t_data *data, int y, int x)
{
    if(y < 0 || y >= data->size || x < 0 || x >= data->len)
        return ;
    if(data->map[y][x] == '1' || data->map[y][x] == 'F')
        return;
    data->map[y][x] = 'F';
    walk_path(data, y + 1, x);
    walk_path(data, y - 1, x);
    walk_path(data, y, x + 1);
    walk_path(data, y, x - 1);
}

int check_valid_items(char **map)
{
    t_data data;
    int k;

    data.i = 0;
    data.items = "01EPC";
    while(map[data.i])
    {
        data.j = 0;
        while(map[data.i][data.j])
        {
            k = 0;
            while(data.items[k])
            {
                if(map[data.i][data.j] == data.items[k])
                    break;
                k++;
            }
            if(k == 5)
                return (valid_items_error(), FALSE);
            data.j++;
        }
        data.i++;
    }
    return (TRUE);
}

int check_map(char **map)
{
    if (!map)
        return (-1);
    if(!check_format(map))
        return (FALSE);
    else if(!check_valid_items(map))
        return(FALSE);
    else if(!check_wall(map))
        return (FALSE);
    else if(!check_items(map))
        return (FALSE);
    else if(!check_path(map))
        return (FALSE);
    return (TRUE);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 04:47:56 by thde-sou          #+#    #+#             */
/*   Updated: 2025/08/29 05:55:55 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    inits_check_items(t_data *data)
{
    data->collectibles = 0;
    data->exit = 0;
    data->player = 0;
    data->i = 0;
}

void    find_player(char **map, int coordinates[2])
{
    t_data data;

    data.i = 0;
    while(map[data.i])
    {
        data.j = 0;
        while(map[data.i][data.j] != '\0')
        {
            if(map[data.i][data.j] == 'P')
            {
                coordinates[0] = data.i;
                coordinates[1] = data.j;
                return ;
            }
            data.j++;
        }
        data.i++;
    }
    coordinates[0] = -1;
    coordinates[1] = -1;
}

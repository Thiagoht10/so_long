/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 04:47:56 by thde-sou          #+#    #+#             */
/*   Updated: 2025/08/29 23:25:20 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	inits_check_items(t_data *data)
{
	data->collectibles = 0;
	data->exit = 0;
	data->player = 0;
	data->i = 0;
}
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

int check_leftover_items(char **map)
{
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'C' || map[i][j] == 'E')
                return (FALSE);
            j++;
        }
        i++;
    }
    return (TRUE);
}

void    put_error(char *str)
{
    int i;

    i = 0;
    write(1, "Error\n", 6);
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 05:20:04 by thde-sou          #+#    #+#             */
/*   Updated: 2025/08/28 06:19:30 by thde-sou         ###   ########.fr       */
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
    int i;
    int j;
    int len;
    int size;

    i = 1;
    len = ft_strlen(map[i]);
    size = count_map_lines();
    while(map[i])
    {
        j = 0;
        while(map[i][j] != '\0')
        {
            if(map[0][j] != '1')
                return (0);
            if(map[i][0] != '1' || map[i][len - 1] != '1')
                return (0);
            if(map[size - 1][j] != '1')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

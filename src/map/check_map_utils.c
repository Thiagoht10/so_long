/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 04:47:56 by thde-sou          #+#    #+#             */
/*   Updated: 2025/09/06 00:17:13 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	inits_check_items(t_data *data)
{
	data->collectibles = 0;
	data->exit = 0;
	data->player = 0;
	data->i = 0;
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

int count_map_lines(char **map)
{
    int i;

    i = 0;
    while(map[i])
        i++;
    return (i);
}

char    **copy_map(char **map)
{
    char    **result;
    int size;
    int i;

    size = count_map_lines(map);
    result = malloc((size + 1) * sizeof(char*));
    if(!result)
        return (NULL);
    i = 0;
    while (i < size)
    {
        result[i] = ft_strdup(map[i]);
        if(!result[i])
        {
            free_all_arr(result);
            return (NULL);
        }
        i++;
    }
    result[size] = NULL;
    return (result);
}


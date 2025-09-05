/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 00:04:10 by thde-sou          #+#    #+#             */
/*   Updated: 2025/09/06 00:17:55 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void    format_error(void)
{
    char *error;

    error = "(incorrect map format)\n";
    put_error(error);
}

void    wall_error(void)
{
    char *error;

    error = "(map without walls around)\n";
    put_error(error);
}

void    items_error(t_data *data)
{
    char    *error;

    error = "";
    if(data->player != 1)
        error = "(wrong number of players)\n";
    else if(data->collectibles < 1)
        error = "(at least one collectible is required)\n";
    else if(data->exit != 1)
        error = "(wrong number of exits)\n";
    put_error(error);
}

void    path_error(void)
{
    char    *error;

    error = "(invalid path)\n";
    put_error(error);
}

void    valid_items_error(void)
{
    char    *error;

    error = "(invalid items)\n";
    put_error(error);
}
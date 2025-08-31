/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 05:23:46 by thde-sou          #+#    #+#             */
/*   Updated: 2025/08/31 05:57:05 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void    calculate_window(char **map, int *pixel_x, int *pixel_y)
{
    int x;
    int y;
    int tile;

    tile = 48;
    x = ft_strlen(map[0]);
    y = count_map_lines(map);
    *pixel_x = x * tile;
    *pixel_y = y * tile;
}

void    open_window(char **map)
{
    int pixel_x;
    int pixel_y;
    void    *mlx;

    calculate_window(map, &pixel_x, &pixel_y);
    mlx = mlx_init();
    mlx_new_window(mlx, pixel_x, pixel_y, "So_long");
    mlx_loop(mlx);
}
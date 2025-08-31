/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 05:23:46 by thde-sou          #+#    #+#             */
/*   Updated: 2025/08/31 17:43:40 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    upload_image(t_game *game)
{
    int tile;

    tile = 48;
    game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor_48.xpm", &tile, &tile);
    game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall_48.xpm", &tile, &tile);
    if(!game->img_floor || !game->img_wall)
        return (FALSE);
    return (TRUE);
}

void    draw_screen(t_game *game)
{
    int x;
    int y;
    int tile;

    y = 0;
    tile = 48;
    while (game->map[y])
    {
        x = 0;
        while(game->map[y][x])
        {
            if(game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * tile, y * tile);
            if(game->map[y][x] != '1')
                mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * tile, y * tile);
            x++;
        }
        y++;
    }
}

void    open_window(t_game *game)
{
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, game->width, game->height, "So_long");
    if(upload_image(game))
        draw_screen(game);
    mlx_loop(game->mlx);
}
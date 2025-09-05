/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 05:23:46 by thde-sou          #+#    #+#             */
/*   Updated: 2025/09/06 00:18:54 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int    upload_image(t_game *game)
{
    int tile;
    int tile2;

    tile = 48;
    tile2 = 47;
    game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor_48.xpm", &tile, &tile);
    game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall_48.xpm", &tile, &tile);
    game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player_48.xpm", &tile2, &tile2);
    if(!game->img_floor || !game->img_wall || !game->img_player)
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
            mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * tile, y * tile);
            if(game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * tile, y * tile);
            if(game->map[y][x] == 'P')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * tile, y * tile);
                mlx_put_image_to_window(game->mlx, game->win, game->img_player, x * 47, y * 47);
            }
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
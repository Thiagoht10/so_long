/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:11:39 by thde-sou          #+#    #+#             */
/*   Updated: 2025/09/06 19:33:00 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void    if_player_on_exit(t_game *game, int coordinates[2])
{
    if(game->player_on_exit == TRUE)
        game->map[coordinates[0]][coordinates[1]] = 'E';
    else
        game->map[coordinates[0]][coordinates[1]] = '0';
    game->player_on_exit = FALSE;
}

void    close_game(t_game *game)
{
    mlx_loop_end(game->mlx);
    mlx_destroy_image(game->mlx, game->img_collect);
    mlx_destroy_image(game->mlx, game->img_exit);
    mlx_destroy_image(game->mlx, game->img_floor);
    mlx_destroy_image(game->mlx, game->img_open_exit);
    mlx_destroy_image(game->mlx, game->img_player);
    mlx_destroy_image(game->mlx, game->img_wall);
    mlx_destroy_image(game->mlx, game->img_player_on_exit);
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_display(game->mlx);
    free_stack_game(game);
    exit(0);
}

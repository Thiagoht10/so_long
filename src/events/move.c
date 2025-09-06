/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:16:32 by thde-sou          #+#    #+#             */
/*   Updated: 2025/09/06 19:44:48 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void    move_up(t_game *game)
{
    int coord[2];

    find_player(game->map, coord);
    if(game->map[coord[0] - 1][coord[1]] == '1')
        return;
    else if(game->map[coord[0] - 1][coord[1]] == 'C'
        || game->map[coord[0] - 1][coord[1]] == '0')
    {
        if(game->map[coord[0] - 1][coord[1]] == 'C')
            game->collectibles -= 1;
        if_player_on_exit(game, coord);
        game->map[coord[0] - 1][coord[1]] = 'P';
    }
    else if (game->map[coord[0] - 1][coord[1]] == 'E' && game->collectibles > 0)
    {
        if_player_on_exit(game, coord);
        game->map[coord[0] - 1][coord[1]] = 'P';
        game->player_on_exit = TRUE;
    }
    else if (game->map[coord[0] - 1][coord[1]] == 'E' && game->collectibles == 0)
        close_game(game);
    game->moves += 1;
    draw_screen(game);
}

void    move_down(t_game *game)
{
    int coord[2];

    find_player(game->map, coord);
    if(game->map[coord[0] + 1][coord[1]] == '1')
        return;
    else if(game->map[coord[0] + 1][coord[1]] == 'C'
        || game->map[coord[0] + 1][coord[1]] == '0')
    {
        if(game->map[coord[0] + 1][coord[1]] == 'C')
            game->collectibles -= 1;
        if_player_on_exit(game, coord);
        game->map[coord[0] + 1][coord[1]] = 'P';
    }
    else if (game->map[coord[0] + 1][coord[1]] == 'E' && game->collectibles > 0)
    {
        if_player_on_exit(game, coord);
        game->map[coord[0] + 1][coord[1]] = 'P';
        game->player_on_exit = TRUE;
    }
    else if (game->map[coord[0] + 1][coord[1]] == 'E' && game->collectibles == 0)
        close_game(game);
    game->moves += 1;
    draw_screen(game);
}

void    move_left(t_game *game)
{
    int coord[2];

    find_player(game->map, coord);
    if(game->map[coord[0]][coord[1] - 1] == '1')
        return;
    else if(game->map[coord[0]][coord[1] - 1] == 'C'
        || game->map[coord[0]][coord[1] - 1] == '0')
    {
        if(game->map[coord[0]][coord[1] - 1] == 'C')
            game->collectibles -= 1;
        if_player_on_exit(game, coord);
        game->map[coord[0]][coord[1] - 1] = 'P';
    }
    else if (game->map[coord[0]][coord[1] - 1] == 'E' && game->collectibles > 0)
    {
        if_player_on_exit(game, coord);
        game->map[coord[0]][coord[1] - 1] = 'P';
        game->player_on_exit = TRUE;
    }
    else if (game->map[coord[0]][coord[1] - 1] == 'E' && game->collectibles == 0)
        close_game(game);
    game->moves += 1;
    draw_screen(game);
}

void    move_right(t_game *game)
{
    int coord[2];

    find_player(game->map, coord);
    if(game->map[coord[0]][coord[1] + 1] == '1')
        return;
    else if(game->map[coord[0]][coord[1] + 1] == 'C'
        || game->map[coord[0]][coord[1] + 1] == '0')
    {
        if(game->map[coord[0]][coord[1] + 1] == 'C')
            game->collectibles -= 1;
        if_player_on_exit(game, coord);
        game->map[coord[0]][coord[1] + 1] = 'P';
    }
    else if (game->map[coord[0]][coord[1] + 1] == 'E' && game->collectibles > 0)
    {
        if_player_on_exit(game, coord);
        game->map[coord[0]][coord[1] + 1] = 'P';
        game->player_on_exit = TRUE;
    }
    else if (game->map[coord[0]][coord[1] + 1] == 'E' && game->collectibles == 0)
        close_game(game);
    game->moves += 1;
    draw_screen(game);
}

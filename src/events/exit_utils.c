/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 19:21:03 by thde-sou          #+#    #+#             */
/*   Updated: 2025/09/12 19:59:37 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	get_exit_right(t_game *game, int *coord)
{
	game->start_time = timestamp_ms();
	if_player_on_exit(game, coord);
	game->map[coord[0]][coord[1] + 1] = 'P';
	game->player_on_exit = TRUE;
	mlx_loop_hook(game->mlx, loop_handler, game);
}

void	get_exit_up(t_game *game, int *coord)
{
	game->start_time = timestamp_ms();
	if_player_on_exit(game, coord);
	game->map[coord[0] - 1][coord[1]] = 'P';
	game->player_on_exit = TRUE;
	mlx_loop_hook(game->mlx, loop_handler, game);
}

void	get_exit_left(t_game *game, int *coord)
{
	game->start_time = timestamp_ms();
	if_player_on_exit(game, coord);
	game->map[coord[0]][coord[1] - 1] = 'P';
	game->player_on_exit = TRUE;
	mlx_loop_hook(game->mlx, loop_handler, game);
}

void	get_exit_down(t_game *game, int *coord)
{
	game->start_time = timestamp_ms();
	if_player_on_exit(game, coord);
	game->map[coord[0] + 1][coord[1]] = 'P';
	game->player_on_exit = TRUE;
	mlx_loop_hook(game->mlx, loop_handler, game);
}

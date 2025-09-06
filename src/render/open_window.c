/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 05:23:46 by thde-sou          #+#    #+#             */
/*   Updated: 2025/09/06 19:23:31 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	upload_image(t_game *game)
{
	int	tile;

	tile = 48;
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor_48.xpm",
			&tile, &tile);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall_48.xpm",
			&tile, &tile);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"textures/player_48.xpm", &tile, &tile);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, "textures/coin_48.xpm",
			&tile, &tile);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit_48.xpm",
			&tile, &tile);
	game->img_open_exit = mlx_xpm_file_to_image(game->mlx,
			"textures/open_exit_48.xpm", &tile, &tile);
    game->img_player_on_exit = mlx_xpm_file_to_image(game->mlx, "textures/player_on_exit_48.xpm", &tile, &tile);
	if (!game->img_floor || !game->img_wall || !game->img_player
		|| !game->img_collect || !game->img_exit || !game->img_open_exit
        || !game->img_player_on_exit)
		return (FALSE);
	return (TRUE);
}

void	draw_screen(t_game *game)
{
	int	x;
	int	y;
	int	tile;

	y = 0;
	tile = 48;
	while (game->map[y])
	{
		x = 0;
        aux_draw_screen(game, y, &x, tile);
		y++;
	}
}

void	open_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width, game->height, "So_long");
	if (upload_image(game))
		draw_screen(game);
    mlx_key_hook(game->win, handle_key, game);
	mlx_loop(game->mlx);
}
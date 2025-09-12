/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:05:42 by thde-sou          #+#    #+#             */
/*   Updated: 2025/09/12 19:58:27 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_game	*creat_stack_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	return (game);
}

int	inits_stack_game(char **map, t_game *game)
{
	int	tile;

	tile = 48;
	if (!map)
		return (FALSE);
	game->height = count_map_lines(map) * tile;
	game->width = ft_strlen(map[0]) * tile;
	game->collectibles = count_collectibles(map);
	game->player_on_exit = 0;
	game->moves = 0;
	game->map = copy_map(map);
	if (!game->map)
		return (FALSE);
	return (TRUE);
}

void	free_stack_game(t_game *game)
{
	if (!game)
		return ;
	free_all_arr(game->map);
	free(game->mlx);
	free(game);
}

void	aux_draw_screen(t_game *game, int y, int *x, int tile)
{
	while (game->map[y][*x])
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor, *x
			* tile, y * tile);
		if (game->map[y][*x] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->img_wall, *x
				* tile, y * tile);
		if (game->map[y][*x] == 'P')
			mlx_put_image_to_window(game->mlx, game->win, game->img_player, *x
				* tile, y * tile);
		if (game->map[y][*x] == 'C')
			mlx_put_image_to_window(game->mlx, game->win, game->img_collect, *x
				* tile, y * tile);
		if (game->map[y][*x] == 'E' && game->collectibles == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->img_open_exit,
				*x * tile, y * tile);
		if (game->map[y][*x] == 'E' && game->collectibles > 0)
			mlx_put_image_to_window(game->mlx, game->win, game->img_exit, *x
				* tile, y * tile);
		player_on_exit(game, y, *x, tile);
		(*x)++;
	}
}

void	player_on_exit(t_game *game, int y, int x, int tile)
{
	if (game->map[y][x] == 'P' && game->player_on_exit == TRUE)
		mlx_put_image_to_window(game->mlx, game->win, game->img_player_on_exit,
			x * tile, y * tile);
	if (game->map[y][x] == 'P' && game->player_on_exit == TRUE
		&& game->collectibles == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_player_open_exit, x * tile, y * tile);
}

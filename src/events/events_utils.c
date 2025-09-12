/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:11:39 by thde-sou          #+#    #+#             */
/*   Updated: 2025/09/12 19:51:40 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	if_player_on_exit(t_game *game, int coordinates[2])
{
	if (game->player_on_exit == TRUE)
		game->map[coordinates[0]][coordinates[1]] = 'E';
	else
		game->map[coordinates[0]][coordinates[1]] = '0';
	game->player_on_exit = FALSE;
}

int	close_game(t_game *game)
{
	mlx_loop_end(game->mlx);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_open_exit);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_player_on_exit);
	mlx_destroy_image(game->mlx, game->img_player_open_exit);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_stack_game(game);
	exit(0);
	return (0);
}

void	draw_cointer(t_game *game)
{
	char	*num;
	char	*msg;

	num = ft_itoa(game->moves);
	msg = ft_strjoin("movements: ", num);
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFF00, msg);
	write(1, "movements: ", 11);
	write(1, num, ft_strlen(num));
	write(1, "\n", 1);
	free(num);
	free(msg);
}

long	timestamp_ms(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000L + t.tv_usec / 1000L);
}

int	loop_handler(t_game *game)
{
	if (game->player_on_exit)
	{
		if (timestamp_ms() - game->start_time >= 250)
			close_game(game);
	}
	return (0);
}

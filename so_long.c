/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:38:46 by thde-sou          #+#    #+#             */
/*   Updated: 2025/08/31 17:42:10 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_game	*game;

	if(argc != 2)
		return (put_error(""), -1);
	map = make_map(argv);
	if (!map)
		return (0);
	if(!check_map(map))
		return (free_all_arr(map), -1);
	game = creat_stack_game();
	if(!game)
		return (-1);
	if(!inits_stack_game(map, game))
		return (-1);
	open_window(game);
	free_all_arr(map);
	free_stack_game(game);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:05:42 by thde-sou          #+#    #+#             */
/*   Updated: 2025/09/06 00:19:08 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_game *creat_stack_game(void)
{
    t_game *game;

    game = malloc(sizeof(t_game));
    if(!game)
        return (NULL);
    return (game);
}

int    inits_stack_game(char **map, t_game *game)
{
    int tile;

    tile = 48;
    if(!map)
        return (FALSE);
    game->height = count_map_lines(map) * tile;
    game->width = ft_strlen(map[0]) * tile;
    game->map = copy_map(map);
    if(!game->map)
        return (FALSE);
    return (TRUE);
}

void    free_stack_game(t_game *game)
{
    if(!game)
        return ;
    free_all_arr(game->map);
    free(game);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:38 by thde-sou          #+#    #+#             */
/*   Updated: 2025/09/06 19:43:49 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int handle_key(int keycode, t_game *game)
{
    if (keycode == KEY_W)
        move_up(game);
    else if (keycode == 97)
        move_left(game);
    else if (keycode == 115) 
        move_down(game);
    else if (keycode == 100)
        move_right(game);
    else if (keycode == KEY_ESC)
        close_game(game);
    return (0);
}
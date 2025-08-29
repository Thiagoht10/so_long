/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:38:46 by thde-sou          #+#    #+#             */
/*   Updated: 2025/08/29 05:58:59 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
    int lines;
    char    **map;
    int i = 0;
    int coordinates[2];

    lines = count_map_lines();
    printf("\ncount_line: %d\n\n", lines);
    map = make_map();
    if(!map)
        return (0);
    while (map[i])
        printf("%s\n", map[i++]);
    printf("\nFORMAT?: %d\n", check_format(map));
    printf("\nWALL?: %d\n", check_wall(map));
    printf("\nITEMS?: %d\n", check_items(map));
    find_player(map, coordinates);
    printf("\nCOORDINATES_PLAYER(Y, X): %d, %d\n", coordinates[0], coordinates[1]);
    free_all_arr(map);
    return (0);
}
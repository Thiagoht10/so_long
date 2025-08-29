/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:38:46 by thde-sou          #+#    #+#             */
/*   Updated: 2025/08/29 22:48:05 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	int		lines;
	char	**map;
	int		i;
	int		coordinates[2];

	i = 0;
	lines = count_map_lines();
	printf("\ncount_line: %d\n\n", lines);
	map = make_map();
	if (!map)
		return (0);
	while (map[i])
		printf("%s\n", map[i++]);
	printf("\nFORMAT?: %d\n", check_format(map));
	printf("\nWALL?: %d\n", check_wall(map));
	printf("\nITEMS?: %d\n", check_items(map));
	if (find_player(map, coordinates))
		printf("\nCOORDINATES_PLAYER(Y, X): %d, %d\n", coordinates[0],
			coordinates[1]);
    printf("\nPATH: %d\n", check_path());
	free_all_arr(map);
	return (0);
}

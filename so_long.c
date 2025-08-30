/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:38:46 by thde-sou          #+#    #+#             */
/*   Updated: 2025/08/31 00:10:54 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	//int		lines;
	char	**map;
	int		i;
	int		coordinates[2];

	if(argc != 2)
		return (put_error(""), -1);
	i = 0;
	map = make_map(argv);
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
    printf("\nPATH: %d\n", check_path(map));
	printf("\nCHECK_MAP: %d\n", check_map(map));
	free_all_arr(map);
	return (0);
}

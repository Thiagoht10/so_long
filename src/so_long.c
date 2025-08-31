/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:38:46 by thde-sou          #+#    #+#             */
/*   Updated: 2025/08/31 05:09:31 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	void	*mlx;
	//void	*win;

	if(argc != 2)
		return (put_error(""), -1);
	map = make_map(argv);
	if (!map)
		return (0);
	if(!check_map(map))
		return (free_all_arr(map), -1);
	mlx = mlx_init();
	mlx_new_window(mlx, 800, 600, "So_long");
	mlx_loop(mlx);
	free_all_arr(map);
	return (0);
}

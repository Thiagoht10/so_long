/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 00:04:10 by thde-sou          #+#    #+#             */
/*   Updated: 2025/09/11 20:42:30 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	format_error(void)
{
	char	*error;

	error = "Incorrect map format\n";
	put_error(error);
}

void	wall_error(void)
{
	char	*error;

	error = "Map without walls around\n";
	put_error(error);
}

void	items_error(t_data *data)
{
	char	*error;

	error = "";
	if (data->player != 1)
		error = "Wrong number of players\n";
	else if (data->collectibles < 1)
		error = "At least one collectible is required\n";
	else if (data->exit != 1)
		error = "Wrong number of exits\n";
	put_error(error);
}

void	path_error(void)
{
	char	*error;

	error = "Invalid path\n";
	put_error(error);
}

void	valid_items_error(void)
{
	char	*error;

	error = "Invalid items\n";
	put_error(error);
}

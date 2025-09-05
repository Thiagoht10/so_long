/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 04:57:47 by thde-sou          #+#    #+#             */
/*   Updated: 2025/09/06 00:19:28 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	double_pointer_error(int fd, char **map, char *line)
{
	close(fd);
	free_all_arr(map);
	free(line);
}

int	safe_open(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		exit(127);
	}
	return (fd);
}

void    put_error(char *str)
{
    int i;

    i = 0;
    write(1, "Error\n", 6);
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}
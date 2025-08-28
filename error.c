/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 04:57:47 by thde-sou          #+#    #+#             */
/*   Updated: 2025/08/28 05:12:35 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    double_pointer_error(int fd, char **map, char *line)
{
    close (fd);
    free_all_arr(map);
    free(line);
    return ;
}

int    safe_open(void)
{
    int fd;
    fd = open("map.ber", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return (-1);
    }
    return (fd);
}
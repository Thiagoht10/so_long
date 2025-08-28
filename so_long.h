/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:39:01 by thde-sou          #+#    #+#             */
/*   Updated: 2025/08/28 05:57:39 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "libft/libft.h"

//#define malloc(x) (NULL)

int count_map_lines(void);
char    *check_end_line(int fd);
char    **make_map(void);
void    free_all_arr(char **arr);
void    double_pointer_error(int fd, char **map, char *line);
int    safe_open(void);
int check_format(char **map);
int check_wall(char **map);
#endif
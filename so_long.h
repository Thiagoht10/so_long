/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:39:01 by thde-sou          #+#    #+#             */
/*   Updated: 2025/08/30 00:07:42 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"

typedef struct s_data
{
    char    **map;
	int	player;
	int	collectibles;
    int coordinates[2];
	int	exit;
	int	size;
	int	len;
	int	i;
	int	j;
}		t_data;

//#define malloc(x) (NULL)

# define TRUE 1
# define FALSE 0

int		count_map_lines(void);
char	*check_end_line(int fd);
char	**make_map(void);
void	free_all_arr(char **arr);
void	double_pointer_error(int fd, char **map, char *line);
int		safe_open(void);
int		check_format(char **map);
int		check_wall(char **map);
int		check_items(char **map);
void	inits_check_items(t_data *data);
int		find_player(char **map, int coordinates[2]);
void    walk_path(t_data *data, int y, int x);
int    check_path(void);
int check_leftover_items(char **map);
void    put_error(char *str);
void    format_error(void);
void    wall_error(void);
void    items_error(t_data *data);
void    path_error(void);
#endif
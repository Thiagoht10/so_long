/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:39:01 by thde-sou          #+#    #+#             */
/*   Updated: 2025/09/12 19:49:28 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <sys/time.h>

typedef struct s_data
{
	char	**map;
	char	*items;
	char	*line;
	int		fd;
	int		player;
	int		collectibles;
	int		coordinates[2];
	int		exit;
	int		size;
	int		len;
	int		i;
	int		j;
}			t_data;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	void	*img_wall;
	void	*img_floor;
	void	*img_collect;
	void	*img_player;
	void	*img_exit;
	void	*img_open_exit;
	void	*img_player_on_exit;
	void	*img_player_open_exit;
	int		img_w;
	int		img_h;
	int		collectibles;
	int		moves;
	int		player_on_exit;
	long	start_time;
}			t_game;

# define TRUE 1
# define FALSE 0
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define ON_DESTROY 17

int			count_lines_fd(char **argv);
char		*get_line(int fd);
char		**make_map(char **argv);
void		free_all_arr(char **arr);
void		double_pointer_error(int fd, char **map, char *line);
int			safe_open(char **argv);
int			check_format(char **map);
int			check_wall(char **map);
int			check_items(char **map);
void		inits_check_items(t_data *data);
int			find_player(char **map, int coordinates[2]);
void		walk_path(t_data *data, int y, int x);
int			check_path(char **map);
int			check_leftover_items(char **map);
void		put_error(char *str);
void		format_error(void);
void		wall_error(void);
void		items_error(t_data *data);
void		path_error(void);
int			check_map(char **map);
int			check_valid_items(char **map);
void		valid_items_error(void);
int			count_map_lines(char **map);
char		**copy_map(char **map);
void		open_window(t_game *game);
t_game		*creat_stack_game(void);
int			inits_stack_game(char **map, t_game *game);
void		free_stack_game(t_game *game);
int			upload_image(t_game *game);
void		draw_screen(t_game *game);
int			count_collectibles(char **map);
void		aux_draw_screen(t_game *game, int y, int *x, int tile);
void		if_player_on_exit(t_game *game, int coordinates[2]);
int			handle_key(int keycode, t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
int			close_game(t_game *game);
void		draw_cointer(t_game *game);
void		player_on_exit(t_game *game, int y, int x, int tile);
int			loop_handler(t_game *game);
long		timestamp_ms(void);
void		get_exit_right(t_game *game, int *coord);
void		get_exit_down(t_game *game, int *coord);
void		get_exit_left(t_game *game, int *coord);
void		get_exit_up(t_game *game, int *coord);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:19:36 by kyacini           #+#    #+#             */
/*   Updated: 2023/12/26 01:07:22 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define ROTATE_LEFT 65361
# define ROTATE_RIGHT 65363
# define FORWARD 119
# define BACK 115
# define RIGHT 100
# define LEFT 97
# define ESC 65307
# define PI 3.1415926535
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include "/usr/include/X11/X.h"
# include <math.h>

typedef struct s_texture{
	void	*img_text;
	int		width;
	int		height;
	int		*data_img_text;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_texture;

typedef struct s_params
{
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		**map;
	int			f_color[3];
	int			c_color[3];
	int			x;
	int			y;
	double		real_x;
	double		real_y;
	void		*mlx;
	void		*mlx_win;
	double		dirx;
	double		diry;
	double		raydirx;
	double		raydiry;
	double		camerax;
	double		deltadistx;
	double		deltadisty;
	double		planx;
	double		plany;
	double		sidedistx;
	double		sidedisty;
	int			stepx;
	int			stepy;
	double		perpwalldist;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	void		*main_img;
	int			*img_data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	double		speed;
	double		rotation;
	double		wall;
	double		step;
	t_texture	*texture_north;
	t_texture	*texture_south;
	t_texture	*texture_east;
	t_texture	*texture_west;
	int			tex_x;
	int			tex_y;
	double		tex_pos;
	int			buff;
}	t_params;

int		have_walls(char **str);
void	check_extension(char *str, t_params *game);
int		error_treatment(int nb_params, char **params, t_params *game);
char	**get_map(char *str);
int		only_one(char *str);
void	free_double_char(char **str);
int		check_params_map(char **map);
int		check_elements(char **str);
int		get_params_map(char **map, t_params *game);
int		test_border_zero(char c);
void	free_parsing_success(t_params *game);
void	free_parsing_failure(t_params *game);
int		search_xy(t_params *game);
int		check_nl(char *str);
void	count_stock_inc(int *c, char *s);
void	stock_var_init(char s[6], int *i, int *c, int *j);
void	count_var_i_inc(int c, int *v, int *i);
void	init_game_data(t_params *game);
int		make_window(t_params *game);
void	process_raycasting(t_params *game);
void	init_params(t_params *game, int x);
void	initialize_ray_step(t_params *game);
void	calculate_wall_distance(t_params *game);
void	configure_wall_texture(t_params *game, int mid, int x);
void	initialize_texture_resources(t_params *game);
int		key_event(int key, t_params *game);
void	rotate(t_params *game, int way);
void	forward(t_params *game);
void	back(t_params *game);
void	right(t_params *game);
void	left(t_params *game);
int		is_passable_space(int x, int y, t_params *game);
void	exit_game(char *error, t_params *game);
int		close_win(t_params *game);
void	destroy_texture(t_params *game, t_texture *t, void *img);
void	render_column(t_params *game, int x);
void	affect_position(t_params *game, int i, int j, int *buff);
void	free_buffers(char **fc, char **cc, char **map);
int		create_map(t_params *game, char **fc, char **cc, char **map);
int		ft_strlen_double(char **str);
int		test_if_player(char c);
int		check_walls(char **str, int i, int j);

#endif
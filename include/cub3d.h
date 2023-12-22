/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:19:36 by kyacini           #+#    #+#             */
/*   Updated: 2023/12/22 10:01:19 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
#define ROTATE_LEFT 65361
#define ROTATE_RIGHT 65363
#define FORWARD_W_Z 122
#define BACK_S_S 115
#define RIGHT_D_D 100
#define LEFT_A_Q 113
#define PI 3.1415926535
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
    char *north;
    char *south;
    char *east;
    char *west;
	char	**map;
    int f_color[3];
    int c_color[3];
    int x;
    int y;
	double real_x;
	double real_y;
    void	*mlx;
	void	*mlx_win;
	double		dirx;
	double		diry;
	double		raydirx; //calcul de direction x du rayon
	double		raydiry; //calcul de direction y du rayon
	double		camerax;
	double		deltadistx; //distance que rayon parcours entre chaque point d'intersection vertical
	double		deltadisty;
	double		planx; //vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	double		plany;
	double		sidedistx; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	double		sidedisty;
	int		stepx; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int		stepy;
	double		perpwalldist;
	int		hit;
	int		side;
	int		lineheight; //hauteur de la ligne a dessiner
	int		drawstart; //position de debut ou il faut dessiner
	int		drawend;
	void 	*main_img;
	int 	*img_data;
    int 	bits_per_pixel;
    int 	size_line;
    int 	endian;
	double	speed;
	double	rotation;
	double wall;
	double			step;
	t_texture		*texture_north;
	t_texture		*texture_south;
	t_texture		*texture_east;
	t_texture		*texture_west;

	int				texX;
	int				texY;
	double			texPos;
}	t_params;


int	have_walls(char **str);
void	check_extension(char *str);
int error_treatment(int nb_params, char **params, t_params *game);
char	**get_map(char *str);
int	only_one(char *str);
void	free_double_char(char **str);
int check_params_map(char **map);
int check_elements(char **str);
int get_params_map(char **map, t_params *game);
int test_border_zero(char c);
void free_parsing_success(t_params *game);
void free_parsing_failure(t_params *game);
int search_xy(t_params *game);
int	check_nl(char *str);
void count_stock_inc(int *c, char *s);
void stock_var_init(char s[6], int *i, int *c, int *j);
void count_var_i_inc(int c, int *v, int *i);
void init_game_data(t_params *game);
int make_window(t_params *game);
void	raycasting_loop(t_params *game);
void	raycasting_init(t_params *game, int x);
void	get_firstdist(t_params *game);
void	get_dist(t_params *game);
void	init_image(t_params *game, int mid, int x);
void	load_images(t_params *game);

#endif
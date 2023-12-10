/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:19:36 by kyacini           #+#    #+#             */
/*   Updated: 2023/12/08 00:12:19 by kyacini          ###   ########.fr       */
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
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include "/usr/include/X11/X.h"


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
}	t_params;

typedef struct s_data
{
    void	*mlx;
	void	*mlx_win;
    double		posx; //position x du joueur
	double		posy; //position y du joueur
	double		dirx; //vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
	double		diry; //vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
	double		planx; //vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	double		plany; //vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
	double		raydirx; //calcul de direction x du rayon
	double		raydiry; //calcul de direction y du rayon
	double		camerax; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	int		mapx; // coordonée x du carré dans lequel est pos
	int		mapy; // coordonnée y du carré dans lequel est pos
	double		sidedistx; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	double		sidedisty; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
	double		deltadistx; //distance que rayon parcours entre chaque point d'intersection vertical
	double		deltadisty; //distance que le rayon parcours entre chaque point d'intersection horizontal
	int		stepx; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int		stepy; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int		hit; // 1 si un mur a ete touche, 0 sinon
	int		side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	double		perpwalldist; // distance du joueur au mur
	int		lineheight; //hauteur de la ligne a dessiner
	int		drawstart; //position de debut ou il faut dessiner
	int		drawend; //position de fin ou il faut dessiner
	int		x;
} t_data;


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
void init_game_data(t_data *data);
void make_window(t_params *game, t_data *data);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:19:36 by kyacini           #+#    #+#             */
/*   Updated: 2023/11/19 23:58:10 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
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
    int f_color[3];
    int c_color[3];
	char	**map;
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



#endif
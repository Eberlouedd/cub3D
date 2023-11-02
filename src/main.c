/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:23:51 by kyacini           #+#    #+#             */
/*   Updated: 2023/11/02 15:34:41 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int argc, char **argv)
{
	char	**map;
	t_params *game;

	game = malloc(sizeof(t_params));
	map = error_treatment(argc, argv);
	if (!map)
		exit(1);
	get_params_map(map, game);
	printf("%s\n", game->c_color);
	printf("%s\n", game->f_color);
	printf("%s\n", game->north);
	printf("%s\n", game->west);
	printf("%s\n", game->east);
	printf("%s\n", game->south);
	return 0;
}
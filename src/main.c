/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:23:51 by kyacini           #+#    #+#             */
/*   Updated: 2023/12/07 23:40:18 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int argc, char **argv)
{
	t_params *game;
	t_data rays;

	if(!check_nl(argv[1]))
		exit(EXIT_SUCCESS);
	game = malloc(sizeof(t_params));
	if(error_treatment(argc, argv, game))
		printf("cool\n");
	else
		exit(EXIT_SUCCESS);
	init_game_data(&rays);
	rays.mlx = mlx_init();
	make_window(game, &rays);
	mlx_loop(rays.mlx);
	free_parsing_success(game);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:23:51 by kyacini           #+#    #+#             */
/*   Updated: 2023/12/22 13:26:09 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int argc, char **argv)
{
	t_params *game;
	if(!check_nl(argv[1]))
		exit(EXIT_SUCCESS);
	game = malloc(sizeof(t_params));
	if(error_treatment(argc, argv, game))
		printf("cool\n");
	else
		exit(EXIT_SUCCESS);
	game->mlx = mlx_init();
	load_images(game);
	init_game_data(game);
    game->mlx_win = mlx_new_window(game->mlx, 600, 450, "Cub3D");
	mlx_loop_hook(game->mlx, make_window, game);
	//mlx_hook(game->mlx_win, 2, 1L<<0, key_event, game);
	mlx_loop(game->mlx);
	free_parsing_success(game);
	return 0;
}
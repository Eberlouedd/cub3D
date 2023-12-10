/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:23:51 by kyacini           #+#    #+#             */
/*   Updated: 2023/12/10 16:33:39 by kyacini          ###   ########.fr       */
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
	game->mlx = mlx_init();
	make_window(game);
	mlx_hook(game->mlx_win, 2, 1L<<0, key_event, game);
	mlx_loop(game->mlx);
	
	free_parsing_success(game);
	return 0;
}
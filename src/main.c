/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:23:51 by kyacini           #+#    #+#             */
/*   Updated: 2023/12/23 23:45:49 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_params	*game;

	if (!check_nl(argv[1]))
		exit(EXIT_SUCCESS);
	game = malloc(sizeof(t_params));
	if (!game)
		exit(EXIT_SUCCESS);
	if (!error_treatment(argc, argv, game))
		exit(EXIT_SUCCESS);
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game("Can't init minilibx\n", game);
	game->main_img = mlx_new_image(game->mlx, 600, 450);
	if (!game->main_img)
		exit_game("Can't create main image\n", game);
	game->mlx_win = mlx_new_window(game->mlx, 600, 450, "Cub3D");
	if (!game->mlx_win)
		exit_game("Can't create window\n", game);
	initialize_texture_resources(game);
	init_game_data(game);
	mlx_hook(game->mlx_win, 33, 0, close_win, game);
	mlx_loop_hook(game->mlx, make_window, game);
	mlx_hook(game->mlx_win, 2, 1L << 0, key_event, game);
	mlx_loop(game->mlx);
	return (0);
}

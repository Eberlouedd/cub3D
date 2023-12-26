/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 05:29:05 by kyacini           #+#    #+#             */
/*   Updated: 2023/12/23 20:33:08 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_dir_plane(t_params *game)
{
	game->dirx = 0;
	game->diry = 0;
	game->planx = 0;
	game->plany = 0;
	if (game->map[game->x][game->y] == 'N')
	{
		game->dirx = -1;
		game->plany = 0.66;
	}
	else if (game->map[game->x][game->y] == 'S')
	{
		game->dirx = 1;
		game->plany = -0.66;
	}
	else if (game->map[game->x][game->y] == 'E')
	{
		game->planx = 0.66;
		game->diry = 1;
	}
	else if (game->map[game->x][game->y] == 'W')
	{
		game->planx = -0.66;
		game->diry = -1;
	}
}

void	init_game_data(t_params *game)
{
	init_dir_plane(game);
	game->real_x = game->x + 0.5;
	game->real_y = game->y + 0.5;
	game->speed = 0.066f;
	game->rotation = 0.0785f;
}

int	make_window(t_params *game)
{
	if (game->main_img)
		mlx_destroy_image(game->mlx, game->main_img);
	game->main_img = mlx_new_image(game->mlx, 600, 450);
	if (!game->main_img)
	{
		exit_game("Error\nMain image creation failed\n", game);
		exit(1);
	}
	game->img_data = (int *)mlx_get_data_addr(game->main_img,
			&game->bits_per_pixel, &game->size_line, &game->endian);
	process_raycasting(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->main_img, 0, 0);
	return (0);
}

void	process_raycasting(t_params *game)
{
	int	x;

	x = 0;
	while (x < 600)
	{
		init_params(game, x);
		initialize_ray_step(game);
		calculate_wall_distance(game);
		render_column(game, x);
		x++;
	}
}

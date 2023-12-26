/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:34:47 by kyacini           #+#    #+#             */
/*   Updated: 2023/12/23 03:44:39 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	initialize_texture_data(t_params *game)
{
	game->texture_north->data_img_text
		= (int *)mlx_get_data_addr(game->texture_north->img_text,
			&game->texture_north->bits_per_pixel,
			&(game->texture_north->size_line),
			&(game->texture_north->endian));
	game->texture_south->data_img_text
		= (int *)mlx_get_data_addr(game->texture_south->img_text,
			&game->texture_south->bits_per_pixel,
			&(game->texture_south->size_line),
			&(game->texture_south->endian));
	game->texture_east->data_img_text
		= (int *)mlx_get_data_addr(game->texture_east->img_text,
			&game->texture_east->bits_per_pixel,
			&(game->texture_east->size_line),
			&(game->texture_east->endian));
	game->texture_west->data_img_text
		= (int *)mlx_get_data_addr(game->texture_west->img_text,
			&game->texture_west->bits_per_pixel,
			&(game->texture_west->size_line),
			&(game->texture_west->endian));
}

int	setup_wall_textures(t_params *game)
{
	game->texture_north->img_text = mlx_xpm_file_to_image(game->mlx,
			game->north,
			&(game->texture_north->width), &(game->texture_north->height));
	if (!game->texture_north->img_text)
		return (exit_game("Error\nCan't load north texture\n", game), exit(1), 1);
	game->texture_south->img_text = mlx_xpm_file_to_image(game->mlx,
			game->south,
			&(game->texture_south->width), &(game->texture_south->height));
	if (!game->texture_south->img_text)
		return (exit_game("Error\nCan't load south texture\n", game), exit(1), 1);
	game->texture_east->img_text = mlx_xpm_file_to_image(game->mlx, game->east,
			&(game->texture_east->width), &(game->texture_east->height));
	if (!game->texture_east->img_text)
		return (exit_game("Error\nCan't load east texture\n", game), exit(1), 1);
	game->texture_west->img_text = mlx_xpm_file_to_image(game->mlx,
			game->west, &(game->texture_west->width),
			&(game->texture_west->height));
	if (!game->texture_west->img_text)
		return (exit_game("Error\nCan't load west texture\n", game), exit(1), 1);
	initialize_texture_data(game);
	return (0);
}

void	initialize_texture_resources(t_params *game)
{
	game->texture_north = malloc(sizeof(t_texture));
	game->texture_north->img_text = NULL;
	game->texture_south = malloc(sizeof(t_texture));
	game->texture_south->img_text = NULL;
	game->texture_east = malloc(sizeof(t_texture));
	game->texture_east->img_text = NULL;
	game->texture_west = malloc(sizeof(t_texture));
	game->texture_west->img_text = NULL;
	setup_wall_textures(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:34:47 by kyacini           #+#    #+#             */
/*   Updated: 2023/12/22 09:45:46 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_addr(t_texture *t)
{
	t->data_img_text = (int *)mlx_get_data_addr(t->img_text,
			&t->bits_per_pixel, &(t->size_line), &(t->endian));
}

int	load_wall(t_params *game)
{
	game->texture_north->img_text = mlx_xpm_file_to_image(game->mlx, game->north,
			&(game->texture_north->width), &(game->texture_north->height));
	if (!game->texture_north->img_text)
		return (printf("Mauvais chargement de la tnord.\n"), exit(1), 1);
	game->texture_south->img_text = mlx_xpm_file_to_image(game->mlx, game->south,
			&(game->texture_south->width), &(game->texture_south->height));
	if (!game->texture_south->img_text)
		return (printf("Mauvais chargement de la tsud.\n"), exit(1), 1);
	game->texture_east->img_text = mlx_xpm_file_to_image(game->mlx, game->east,
			&(game->texture_east->width), &(game->texture_east->height));
	if (!game->texture_east->img_text)
		return (printf("Mauvais chargement de la test.\n"), exit(1), 1);
	game->texture_west->img_text = mlx_xpm_file_to_image(game->mlx,
			game->west, &(game->texture_west->width), &(game->texture_west->height));
	if (!game->texture_west->img_text)
		return (printf("Mauvais chargement de la touest.\n"), exit(1), 1);
	get_addr(game->texture_north);
	get_addr(game->texture_south);
	get_addr(game->texture_east);
	get_addr(game->texture_west);
	return (0);
}

void	load_images(t_params *game)
{
	game->texture_north = malloc(sizeof(t_texture));
	game->texture_north->img_text = NULL;
	game->texture_south = malloc(sizeof(t_texture));
	game->texture_south->img_text = NULL;
	game->texture_east = malloc(sizeof(t_texture));
	game->texture_east->img_text = NULL;
	game->texture_west = malloc(sizeof(t_texture));
	game->texture_west->img_text = NULL;
	load_wall(game);
}

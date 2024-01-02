/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:01:16 by kyacini           #+#    #+#             */
/*   Updated: 2024/01/02 14:26:01 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	exit_game(char *error, t_params *game)
{
	ft_putstr_fd(error, 2);
	free_parsing_success(game);
	if (game->texture_east)
		destroy_texture(game, game->texture_east, game->texture_east->img_text);
	if (game->texture_north)
		destroy_texture(game, game->texture_north,
			game->texture_north->img_text);
	if (game->texture_west)
		destroy_texture(game, game->texture_west, game->texture_west->img_text);
	if (game->texture_south)
		destroy_texture(game, game->texture_south,
			game->texture_south->img_text);
	if (game->main_img)
		mlx_destroy_image(game->mlx, game->main_img);
	mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	exit(1);
}

void	destroy_texture(t_params *game, t_texture *t, void *img)
{
	if (img)
		mlx_destroy_image(game->mlx, img);
	free(t);
}

int	close_win(t_params *game)
{
	free_parsing_success(game);
	if (game->texture_east)
		destroy_texture(game, game->texture_east, game->texture_east->img_text);
	if (game->texture_north)
		destroy_texture(game, game->texture_north,
			game->texture_north->img_text);
	if (game->texture_west)
		destroy_texture(game, game->texture_west, game->texture_west->img_text);
	if (game->texture_south)
		destroy_texture(game, game->texture_south,
			game->texture_south->img_text);
	if (game->main_img)
		mlx_destroy_image(game->mlx, game->main_img);
	mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	exit(0);
	return (0);
}

void	free_buffers(char **fc, char **cc, char **map)
{
	free_double_char(cc);
	free_double_char(fc);
	free_double_char(map);
}

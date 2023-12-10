/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 05:29:05 by kyacini           #+#    #+#             */
/*   Updated: 2023/12/10 17:04:50 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void init_game_data(t_data *data)
{
    data->planx = 0;
    data->plany = 0.66;
}

void make_window(t_params *game)
{
    int i;
    int j;
    void *img;
    char *img_data;
    int bpp;
    int size_line;
    int endian;
    int color = 0xFF0000;
    int color_wall = 0xFFFFFF;
    
    i = 0;
    while(game->map[i])
    {
        i++;
    }
	game->mlx_win = mlx_new_window(game->mlx, ft_strlen(game->map[0]) * 20, i * 20, "Cub3D");
    img = mlx_new_image(game->mlx, ft_strlen(game->map[0]) * 20, i * 20);
    img_data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
    for (int y = 0; y < i * 20; y++)
    {
        for (int x = 0; x < ft_strlen(game->map[0]) * 20; x++)
        {
            int index = x * (bpp / 8) + y * size_line;
            if(game->map[y / 20][x / 20] == '1')
                *(int*)(img_data + index) = color_wall;
            else if(game->map[y / 20][x / 20] == 'N')
                *(int*)(img_data + index) = color;
        }
    }
    game->img = img;
    mlx_put_image_to_window(game->mlx, game->mlx_win, img, 0, 0);
}

int	key_event(int keycode, t_params *game)
{
	if (keycode == FORWARD_W_Z)
	{
        game->real_y -= 1;
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, game->real_x, game->real_y);
    }
	// else if (keycode == LEFT_A_Q)
	// 	move_images(game, LEFT_A_Q);
	// else if (keycode == RIGHT_D_D)
	// 	move_images(game, RIGHT_D_D);
	// else if (keycode == BACK_S_S)
	// 	move_images(game, BACK_S_S);
	return (0);
}

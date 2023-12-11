/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 05:29:05 by kyacini           #+#    #+#             */
/*   Updated: 2023/12/11 23:08:34 by kyacini          ###   ########.fr       */
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
    int perso = 0;
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
            else if(game->map[y / 20][x / 20] == 'N' && perso == 0)
            {
                *(int*)(img_data + index) = color;
                game->real_x = x;
                game->real_y = y;
                perso = 1;
            }
        }
    }
    game->img = img;
    game->angle = 90;
    game->diry = -sin(90*PI/180.0);
    game->dirx = cos(90*PI/180.0);
    mlx_put_image_to_window(game->mlx, game->mlx_win, img, 0, 0);
}

int	key_event(int keycode, t_params *game)
{
    char *img_data;
    int bpp;
    int size_line;
    int endian;
    int index;

    img_data = mlx_get_data_addr(game->img, &bpp, &size_line, &endian);
	if (keycode == FORWARD_W_Z)
	{
        printf("oui");
        index = game->real_x * (bpp / 8) + game->real_y * size_line;
        *(int*)(img_data + index) = 0x000000;
        index = game->real_x * (bpp / 8) + (game->real_y - game->diry) * size_line;
        *(int*)(img_data + index) = 0xFF0000;
        game->real_y -= game->diry;
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, 0, 0);
    }
	else if (keycode == LEFT_A_Q)
	{
        index = game->real_x * (bpp / 8) + game->real_y * size_line;
        *(int*)(img_data + index) = 0x000000;
        index = (game->real_x - game->dirx) * (bpp / 8) + game->real_y * size_line;
        *(int*)(img_data + index) = 0xFF0000;
        game->real_x -= game->dirx;
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, 0, 0);
    }
	else if (keycode == RIGHT_D_D)
    {
        index = game->real_x * (bpp / 8) + game->real_y * size_line;
        *(int*)(img_data + index) = 0x000000;
        index = (game->real_x + game->dirx) * (bpp / 8) + game->real_y * size_line;
        *(int*)(img_data + index) = 0xFF0000;
        game->real_x += game->dirx;
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, 0, 0);
    }
	else if (keycode == BACK_S_S)
    {
        index = game->real_x * (bpp / 8) + game->real_y * size_line;
        *(int*)(img_data + index) = 0x000000;
        index = game->real_x * (bpp / 8) + (game->real_y + game->diry) * size_line;
        *(int*)(img_data + index) = 0xFF0000;
        game->real_y += game->diry;
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, 0, 0);
    }
    else if(keycode == ROTATE_RIGHT)
    {
        printf("%d\n",game->dirx);
    }
	return (0);
}

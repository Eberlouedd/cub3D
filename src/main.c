/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:23:51 by kyacini           #+#    #+#             */
/*   Updated: 2023/11/20 00:03:29 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int argc, char **argv)
{
	t_params *game;

	game = malloc(sizeof(t_params));
	if(error_treatment(argc, argv, game))
		printf("cool\n");
	else
		exit(EXIT_SUCCESS);
	free_parsing_success(game);
	return 0;
}
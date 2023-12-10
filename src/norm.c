/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 04:32:25 by kyacini           #+#    #+#             */
/*   Updated: 2023/12/02 04:33:30 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void count_stock_inc(int *c, char *s)
{
	*c += 1;
	*s = '1';
}

void stock_var_init(char s[6], int *i, int *c, int *j)
{
	s[0] = 'N';
	s[1] = 'S';
	s[2] = 'W';
	s[3] = 'E';
	s[4] = 'F';
	s[5] = 'C';
	*i = 0;
	*c = 0;
	*j = 0;
}

void count_var_i_inc(int c, int *v, int *i)
{
	if(c > 6)
		*v = 1;
	*i += 1;
}
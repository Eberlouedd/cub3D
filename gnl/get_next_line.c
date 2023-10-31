/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:44:42 by kyacini           #+#    #+#             */
/*   Updated: 2022/09/09 21:01:53 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	test_n(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	formate_line(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			n++;
		if (n > 1)
			return (0);
		i++;
	}
	if (str[i - 1] == '\n')
		return (1);
	return (0);
}

void	*pmalloc(int size)
{
	void	*p;

	p = malloc(size);
	if (!p)
		exit(1);
	return (p);
}

char	*get_next_line(int fd)
{
	char		*cursor;
	char		*line;
	static char	*stock = NULL;
	int			ret;

	if (BUFFER_SIZE < 0)
		return (NULL);
	ret = 1;
	if (!test_n(stock))
	{
		cursor = pmalloc(BUFFER_SIZE + 1);
		while (ret > 0)
		{
			ret = read(fd, cursor, BUFFER_SIZE);
			if (ret <= 0)
				break ;
			cursor[ret] = '\0';
			stock = ft_strjoin(stock, cursor);
			if (test_n(cursor))
				break ;
		}
		free(cursor);
	}
	return (line = create_line(stock), stock = clean_stock(stock), line);
}

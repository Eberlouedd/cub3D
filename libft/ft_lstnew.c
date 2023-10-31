/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:11:43 by kyacini           #+#    #+#             */
/*   Updated: 2022/05/11 18:47:12 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*liste;

	liste = malloc(sizeof(t_list));
	if (!liste)
		return (NULL);
	liste->content = content;
	liste->next = NULL;
	return (liste);
}

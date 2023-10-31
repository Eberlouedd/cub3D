/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:57:26 by kyacini           #+#    #+#             */
/*   Updated: 2022/12/21 17:20:46 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*buff;

	if (!lst)
		return ;
	while (*lst)
	{
		buff = (*lst)->next;
		free(*lst);
		*lst = buff;
	}
	*lst = NULL;
}

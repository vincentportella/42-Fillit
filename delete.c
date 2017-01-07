/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:00:29 by stati             #+#    #+#             */
/*   Updated: 2016/11/13 11:13:22 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	delete_one_piece(t_piece **alst, void (*del)(void**))
{
	if (*alst != NULL)
	{
		del((void**)&(*alst)->x);
		del((void**)&(*alst)->y);
		free(*alst);
		*alst = NULL;
	}
}

void	delete_piece(t_piece **alst,
		void (*del)(t_piece**, void (*del)(void**)))
{
	t_piece *tmp;
	t_piece *list;

	list = *alst;
	if (!list)
		return ;
	while (list)
	{
		tmp = list->next;
		del(&list, &ft_memdel);
		list = tmp;
	}
	*alst = NULL;
}

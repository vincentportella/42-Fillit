/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:00:05 by stati             #+#    #+#             */
/*   Updated: 2016/11/13 11:13:01 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*update_hash(unsigned int i, int *x, int *y)
{
	t_piece	*new;

	new = malloc(sizeof(t_piece));
	if (new)
	{
		if (x == NULL || y == NULL)
		{
			new->x = NULL;
			new->y = NULL;
			new->type = 0;
		}
		else
		{
			new->type = (char)(i + 65);
			if (!(new->x = ft_memalloc(4 * 4))
				|| !(new->y = ft_memalloc(4 * 4)))
				return (NULL);
			new->x = (int*)ft_memcpy(new->x, x, 4 * 4);
			new->y = (int*)ft_memcpy(new->y, y, 4 * 4);
			get_max(&new);
		}
		new->next = NULL;
	}
	return (new);
}

void	add_hash(t_piece **blst, t_piece *lst)
{
	t_piece	*tmp;

	tmp = *blst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = lst;
}

int		bestfinder(int *ary)
{
	int	i;
	int	num;

	i = 3;
	num = 0;
	while (i > -1)
	{
		if (ary[i] > num)
			num = ary[i];
		i--;
	}
	return (num);
}

void	get_max(t_piece **lst)
{
	t_piece	*new;

	new = *lst;
	new->w = bestfinder(new->x);
	new->h = bestfinder(new->y);
}

void	print_plan(char **board, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		ft_putendl(board[i]);
		i++;
	}
}

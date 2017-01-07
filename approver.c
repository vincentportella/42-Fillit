/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   approver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:57:29 by vportell          #+#    #+#             */
/*   Updated: 2016/11/13 11:59:33 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	circle_check(t_piece *piece, int x, int y, int *n)
{
	int j;

	j = -1;
	while (j++ < 3)
		if (x == (piece->x)[j] && y - 1 == (piece->y)[j])
			(*n)++;
	j = -1;
	while (j++ < 3)
		if (x == (piece->x)[j] && y + 1 == (piece->y)[j])
			(*n)++;
	j = -1;
	while (j++ < 3)
		if (x - 1 == (piece->x)[j] && y == (piece->y)[j])
			(*n)++;
	j = -1;
	while (j++ < 3)
		if (x + 1 == (piece->x)[j] && y == (piece->y)[j])
			(*n)++;
}

int		approve_piece(t_piece *piece)
{
	int i;
	int n;

	i = -1;
	n = 0;
	while (piece->next)
		piece = piece->next;
	while (i++ < 3)
		circle_check(piece, (piece->x)[i], (piece->y)[i], &n);
	if (n < 6)
		return (0);
	return (1);
}

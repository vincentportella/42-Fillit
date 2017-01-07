/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:00:29 by stati             #+#    #+#             */
/*   Updated: 2016/11/12 22:36:06 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		spotchecker(int row, int col, char **board, t_piece *lst)
{
	int		i;
	int		x;
	int		y;

	i = 3;
	while (i >= 0)
	{
		x = lst->x[i];
		y = lst->y[i];
		if (board[row + y][col + x] != '.')
			return (0);
		i--;
	}
	return (1);
}

t_piece	**store_piece(int row, int col, char **board, t_piece *lst)
{
	int		i;
	int		x;
	int		y;

	i = 3;
	while (i >= 0)
	{
		x = lst->x[i];
		y = lst->y[i];
		board[row + y][col + x] = lst->type;
		i--;
	}
	return (&lst->next);
}

void	ft_free(int row, int col, t_piece *lst, char **board)
{
	int		i;
	int		x;
	int		y;

	i = 3;
	while (i >= 0)
	{
		x = lst->x[i];
		y = lst->y[i];
		board[row + y][col + x] = '.';
		i--;
	}
}

int		solve(int n, int row, char **board, t_piece **bgnlst)
{
	t_piece	*lst;
	int		found;
	int		col;

	lst = *bgnlst;
	if (!lst)
		return (1);
	while (row < n - lst->h)
	{
		col = 0;
		while (col < n - lst->w)
		{
			found = spotchecker(row, col, board, lst);
			if (found)
			{
				if (solve(n, 0, board,
					store_piece(row, col, board, lst)))
					return (1);
				ft_free(row, col, lst, board);
			}
			col++;
		}
		row++;
	}
	return (0);
}

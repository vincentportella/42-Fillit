/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storedash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stati <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:00:38 by stati             #+#    #+#             */
/*   Updated: 2016/11/09 21:00:39 by stati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		keyfinder(int *x, int *y, char **grill)
{
	int i;
	int j;

	i = 3;
	while (i >= 0)
	{
		j = 3;
		while (j >= 0)
		{
			if (grill[i][j] == '#')
			{
				if (i < *y)
					*y = i;
				if (j < *x)
					*x = j;
			}
			j--;
		}
		i--;
	}
}

static int		*xfinder(char **grill, int xdef, int y, int x)
{
	int	first;
	int *pointx;
	int pc;

	pointx = (int*)malloc(sizeof(int) * 4);
	pc = 0;
	while (y < 4)
	{
		x = 0;
		while (grill[y][x])
		{
			if (grill[y][x] == '#')
			{
				pointx[pc] = (x - xdef);
				if (pc == 0)
					first = pointx[pc];
				if (first)
					pointx[pc] -= 1;
				pc++;
			}
			x++;
		}
		y++;
	}
	return (pointx);
}

static int		*yfinder(char **grill, int ydef, int y, int x)
{
	int	first;
	int *pointy;
	int pc;

	pointy = (int*)malloc(sizeof(int) * 4);
	pc = 0;
	while (y < 4)
	{
		x = 0;
		while (grill[y][x])
		{
			if (grill[y][x] == '#')
			{
				pointy[pc] = (y - ydef);
				if (pc == 0)
					first = pointy[pc];
				if (first)
					pointy[pc] -= 1;
				pc++;
			}
			x++;
		}
		y++;
	}
	return (pointy);
}

void			storedash(t_piece **blst, char *str, unsigned int i)
{
	char	**grill;
	int		*x;
	int		*y;

	x = (int*)malloc(sizeof(int) * 1);
	y = (int*)malloc(sizeof(int) * 1);
	*x = 4;
	*y = 4;
	grill = ft_strsplit(str, '\n');
	keyfinder(x, y, grill);
	if (i == 0)
		*blst = update_hash(i, xfinder(grill, *x, 0, 0),
			yfinder(grill, *y, 0, 0));
	else
		add_hash(blst, update_hash(i, xfinder(grill, *x, 0, 0),
			yfinder(grill, *y, 0, 0)));
	free(x);
	free(y);
}

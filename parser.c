/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 20:04:29 by vportell          #+#    #+#             */
/*   Updated: 2016/11/13 13:00:59 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_piece(char *buf, int l)
{
	int i;
	int n;
	int m;

	i = -1;
	n = 0;
	m = 0;
	if (l > 20 && buf[20] != 10)
		return (0);
	while (buf[++i])
	{
		if (!((i + 1) % 5) && buf[i] != '\n')
			return (0);
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (0);
		if (buf[i] == '#')
			n++;
		if (buf[i] == '.')
			m++;
	}
	if (n != 4 || m != 12)
		return (0);
	return (1);
}

void	set_dimensions(t_piece *piece, const int *x, const int *y)
{
	int i;
	int min;
	int max;

	i = -1;
	min = 3;
	max = 0;
	while (i++ < 3)
		max = x[i] > max ? x[i] : max;
	while (i-- > 0)
		min = x[i] < min ? x[i] : min;
	piece->w = max - min + 1;
	min = 3;
	max = 0;
	while (i++ < 3)
		max = y[i] > max ? y[i] : max;
	while (i-- > 0)
		min = y[i] < min ? y[i] : min;
	piece->h = max - min + 1;
}

t_piece	*create_nodes(char *buf)
{
	int		i;
	int		n;
	t_piece	*piece;

	i = -1;
	n = 0;
	piece = (t_piece *)malloc(sizeof(t_piece));
	piece->x = (int *)malloc(sizeof(int) * 4);
	piece->y = (int *)malloc(sizeof(int) * 4);
	while (buf[++i])
	{
		if (buf[i] == '#')
		{
			(piece->x)[n] = i % 5;
			(piece->y)[n] = i / 5;
			n++;
		}
	}
	set_dimensions(piece, piece->x, piece->y);
	piece->next = NULL;
	return (piece);
}

void	create_piece(t_piece **piece, char *buf)
{
	t_piece *temp;

	if (*piece)
	{
		temp = *piece;
		while ((*piece)->next)
			*piece = (*piece)->next;
		(*piece)->next = create_nodes(buf);
		*piece = temp;
	}
	else
		*piece = create_nodes(buf);
}

int		parse_nodes(t_piece **node, char *s)
{
	int		fd;
	int		i;
	char	*buf;
	int		count;
	t_piece *piece;

	i = 0;
	piece = *node;
	buf = ft_strnew(21);
	fd = open(s, O_RDONLY);
	while ((count = read(fd, buf, 21)))
	{
		i = count;
		if (count < 20 || !check_piece(buf, i))
			return (free_memory(piece));
		create_piece(&piece, buf);
		if (!approve_piece(piece))
			return (free_memory(piece));
	}
	if (!piece || i != 20)
		return (0);
	*node = piece;
	close(fd);
	return (1);
}

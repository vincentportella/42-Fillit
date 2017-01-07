/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:00:29 by stati             #+#    #+#             */
/*   Updated: 2016/11/13 11:09:43 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*ft_piece_to_letter(t_piece *piece, char *av, unsigned int check)
{
	t_piece			*pieces;
	char			str[SIZE + 1];
	unsigned int	i;
	int				fd;
	int				ret;

	i = 0;
	piece = 0;
	fd = open(av, O_RDONLY);
	while ((ret = read(fd, str, SIZE + 1)))
	{
		str[ret - 1] = '\0';
		if (ret == 21)
			check++;
		storedash(&pieces, str, i);
		i++;
	}
	close(fd);
	return (pieces);
}

char	**build_plan(unsigned int size)
{
	unsigned int	i;
	char			**board;

	i = 0;
	board = (char**)malloc(sizeof(char*) * (size + 1));
	while (i < size)
	{
		board[i] = ft_strnew(size + 1);
		board[i] = ft_memset(board[i], '.', size);
		i++;
	}
	board[i] = 0;
	return (board);
}

int		square_finder(int n, int nb)
{
	if (n * n > nb)
		return (0);
	if (n * n == nb)
		return (n);
	else
		return (square_finder(n + 1, nb));
}

int		count_piece(t_piece **blst)
{
	t_piece	*lst;
	int		i;

	i = 0;
	lst = *blst;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int		give_size(t_piece *lst)
{
	unsigned int	size;
	unsigned int	i;

	size = count_piece(&lst);
	size *= 4;
	i = 0;
	while (!i)
	{
		i = square_finder(1, size);
		size++;
	}
	return (i);
}

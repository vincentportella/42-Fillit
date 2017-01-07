/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 08:02:33 by vportell          #+#    #+#             */
/*   Updated: 2016/11/13 12:09:05 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	error_message(int n)
{
	if (n != 2)
		ft_putstr("usage: ./fillit [ file ]\n");
	else
		ft_putstr("error\n");
	return (0);
}

int	free_memory(t_piece *piece)
{
	t_piece *temp;

	while (piece)
	{
		temp = piece->next;
		free(piece->x);
		free(piece->y);
		free(piece);
		piece = temp;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_piece			*pieces;
	char			**board;
	unsigned int	done;
	unsigned int	size;

	if (ac != 2 || !parse_nodes(&pieces, av[1]))
		return (error_message(ac));
	done = 0;
	pieces = ft_piece_to_letter(pieces, av[1], 0);
	size = give_size(pieces);
	while (!done)
	{
		board = build_plan(size);
		done = solve(size, 0, board, &pieces);
		if (!done)
			size++;
	}
	delete_piece(&pieces, &delete_one_piece);
	print_plan(board, size);
	return (0);
}

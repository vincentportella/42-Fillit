/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:50:14 by vportell          #+#    #+#             */
/*   Updated: 2016/11/13 15:43:05 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# define SIZE 20

typedef struct		s_piece
{
	int				*x;
	int				*y;
	int				h;
	int				w;
	char			type;
	struct s_piece	*next;
}					t_piece;

int					parse_nodes(t_piece **node, char *s);
int					approve_piece(t_piece *piece);
int					free_memory(t_piece *piece);
void				print_plan(char **board, unsigned int size);
void				delete_one_piece(t_piece **alst, void (*del)(void**));
void				delete_piece(t_piece **alst, void (*del)(t_piece**,
					void (*del)(void**)));
int					solve(int n, int row, char **board, t_piece **blst);
char				**build_plan(unsigned int size);
int					give_size(t_piece *lst);
t_piece				*ft_piece_to_letter(t_piece *piece,
					char *av, unsigned int check);
void				storedash(t_piece **blst, char *str, unsigned int i);
t_piece				*update_hash(unsigned int i, int *x, int *y);
void				add_hash(t_piece **blst, t_piece *lst);
void				get_max(t_piece **lst);

#endif

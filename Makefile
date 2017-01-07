# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vportell <vportell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 22:19:44 by vportell          #+#    #+#              #
#    Updated: 2016/11/13 16:03:30 by vportell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Wextra -Werror

SRCS =	fillit.c \
		parser.c \
		approver.c \
		solve.c \
		func.c \
		delete.c \
		hashes.c \
		storedash.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

LIBFT = ./libft/libft.a
LIBLINK =   -L./libft -lft

.PHONY: fclean all

all: $(NAME)

$(LIBFT):
	make -C ./libft

$(NAME): $(LIBFT) $(OBJS)
	gcc $(LIBLINK) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
	make -C ./libft clean
	$(RM) $(OBJS)

fclean: clean
	make -C ./libft fclean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all

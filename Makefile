# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbrantne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 20:27:34 by pbrantne          #+#    #+#              #
#    Updated: 2023/01/19 20:27:40 by pbrantne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c \
	algorithm.c \
	input_handling.c \
	coloration.c \
	schemes_one.c \
	schemes_two.c \
	key_handling.c \

LIBFT = ./libft/libft.a
MINILIBX = ./minilibx-linux/libmlx.a
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
CC = cc -g
RM = rm -f

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJS) $(MINILIBX) $(LIBFT)
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(MINILIBX) $(LIBFT) -o $(NAME) -lXext -lX11 -lm

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C ./libft

re: clean all


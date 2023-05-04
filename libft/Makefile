# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbrantne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 11:34:16 by pbrantne          #+#    #+#              #
#    Updated: 2022/11/01 16:20:58 by pbrantne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

SRC = 	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memcmp.c \
	ft_strchr.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_memchr.c \
	ft_atoi.c \
	ft_memset.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strdup.c \
	ft_calloc.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_strmapi.c \
	ft_strtrim.c \
	ft_striteri.c \
	ft_itoa.c \
	ft_split.c

SCRB =	ft_lstnew.c \
	ft_lstsize.c \
	ft_lstadd_front.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

SRCPRINTF = ft_printf.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_putchar.c \
	ft_convert.c \
	ft_convert_lower.c \
	ft_hexptr.c

OBJ = $(SRC:.c=.o) $(SRCPRINTF:.c=.o)

OBJB = $(SCRB:.c=.o)

$(NAME): all

all:
	cc $(CFLAGS) -c $(SRC) $(SRCPRINTF)
	ar rcs $(NAME) $(OBJ)

bonus:
	cc $(CFLAGS) -c $(SCRB) 
	ar rcs $(NAME) $(OBJB)

clean:
	rm -f $(OBJ) $(OBJB)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: greita <greita@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 10:29:31 by greita            #+#    #+#              #
#    Updated: 2022/02/09 12:07:44 by greita           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libft.a

LIST = 		ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
			ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
			ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
			ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c \
			get_next_line.c

OBJ = 		$(LIST:.c=.o)

CC =		gcc

FLAGS =		-Wall -Wextra -Werror

D_FILES =	$(LIST:.c=.d)

%.o :		%.c
	$(CC) $(FLAGS) -c $< -o $@ -MMD

all :		$(NAME)

-include	$(D_FILES)

$(NAME) :	$(OBJ)
	ar rcs $(NAME) $?

clean :
	rm -f $(OBJ) $(D_FILES)

fclean :	clean
	rm -f $(NAME)

re :		fclean all

.PHONY :	all clean fclean re

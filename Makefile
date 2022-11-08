# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: greita <greita@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 13:55:33 by greita            #+#    #+#              #
#    Updated: 2022/03/12 13:13:25 by greita           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		pipex

NAME_B =	pipex_bonus

SRC =		mandatory/cmds.c	\
			mandatory/init.c	\
			mandatory/init2.c	\
			mandatory/close.c	\
			mandatory/pipex.c

SRC_B =		bonus/cmds_bonus.c	\
			bonus/init_bonus.c	\
			bonus/init2_bonus.c	\
			bonus/close_bonus.c	\
			bonus/pipex_bonus.c

OBJ = 		$(SRC:.c=.o)

OBJ_B = 	$(SRC_B:.c=.o)

CC =		gcc

FLAGS =		-Wall -Wextra -Werror

D_FILES =	$(SRC:.c=.d)

D_FILES_B =	$(SRC_B:.c=.d)

%.o :		%.c
	$(CC) $(FLAGS) -c $< -o $@ -MMD

all :		$(NAME)

bonus:		$(NAME_B)

-include	$(D_FILES) $(D_FILES_B)

$(NAME) :	$(OBJ)
	make all -C ./libft
	$(CC) $(FLAGS) $(OBJ) ./libft/libft.a -o $(NAME)

$(NAME_B) :	$(OBJ_B)
	make all -C ./libft
	$(CC) $(FLAGS) $(OBJ_B) ./libft/libft.a -o $(NAME_B)

clean :
	make clean -C ./libft
	rm -f $(OBJ) $(OBJ_B) $(D_FILES) $(D_FILES_B)

fclean :	clean
	rm -f ./libft/libft.a
	rm -f $(NAME)
	rm -f $(NAME_B)

re :		fclean all

rebonus :	fclean bonus

.PHONY :	all clean fclean re rebonus bonus

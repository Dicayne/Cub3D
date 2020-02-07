# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 18:22:15 by vmoreau           #+#    #+#              #
#    Updated: 2020/02/07 18:48:00 by vmoreau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#PRINTF
NAME = Cub3D

SRCS =	src/main.c	src/init_struct.c	src/parsing.c	src/parsing_map.c	\
		src/utils.c	\

OBJS = $(SRCS:.c=.o)

INCL = header/

HEADER = $(INCL)cub3D.h

CC = clang

CFLAGS = -Werror -Wall -Wextra

LIBLINK = -L./ -lftprintf

#LIBFT
LIB = Libft/

OBJLIB = $(LIB)src/*.o

#MINILIBX

MLX = minilibx_mms_20191207_beta/

OBJMLX = $(MLX)*.o

#RULE
all : complib compmlx $(NAME)

$(OBJS) : %.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -I $(INCL) -c $< -o $@ 

$(NAME) : echoCL $(OBJS) echoCS
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(OBJLIB) -L ./ -lmlx
	#@$(CC) $(CFLAGS) -o $@ $(OBJS) $(OBJLIB) -g3 -fsanitize=address -L ./ -lmlx

complib :
	@$(MAKE) -C $(LIB) all

compmlx :
	@$(MAKE) -C $(MLX) all

cleanlibft :
	@$(MAKE) -C $(LIB) clean

fcleanlibft :
	@$(MAKE) -C $(LIB) fclean

cleanmlx :
	@$(MAKE) -C $(MLX) clean

fcleanmlx :
	@$(MAKE) -C $(MLX) fclean
	
clean : echoCLEAN cleanlibft cleanmlx
	@$(RM) $(OBJS)

fclean : clean echoFCLEAN fcleanlibft fcleanmlx
	@$(RM) $(NAME)
	@rm -rf a.out a.out.dSYM

re : fclean all

#ECHO
echoCL:
	@echo "\033[33;33m===> Compiling \033[31mCub3D"
echoCS :
	@echo "\033[32m===> Compilation Success \033[31mCub3D Ready!!"
echoCLEAN :
	@echo "\033[35m===> Cleanning OBJ Cub3D"
echoFCLEAN :
	@echo "\033[35m===> Cleanning Exec"

.PHONY : all clean fclean re complib exec cleanlibft fcleanlibft

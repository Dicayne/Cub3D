# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 18:22:15 by vmoreau           #+#    #+#              #
#    Updated: 2020/01/27 04:40:02 by vmoreau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#PRINTF
NAME = Cub3D

SRCS = \
			
OBJS = $(SRCS:.c=.o)

INCL = header/

HEADER = $(INCL)ft_printf.h

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

$(NAME) : echoCL echoCS echoAR
	@$(CC) -o $@ $(OBJS) $(OBJLIB) $(MLX)main.c -L ./ -lmlx

complib :
	@$(MAKE) -C $(LIB) all

compmlx :
	@$(MAKE) -C $(MLX) all

exec :
	@$(CC) main.c $(LIBLINK)
	@./a.out

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

# re : fclean all

#ECHO
echoCL:
	@echo "\033[33;33m===> Compiling Libftprintf\033[m"
echoCS :
	@echo "\033[1;32m===> Compilation Success\033[m"
echoCLEAN :
	@echo "\033[35m===> Cleanning OBJ Libftprintf\033[m"
echoFCLEAN :
	@echo "\033[35m===> Cleanning Libftprintf.a\033[m"
echoAR :
	@echo "\033[1;36m===> Archiving Libftprintf\033[m"

.PHONY : all clean fclean re complib exec cleanlibft fcleanlibft

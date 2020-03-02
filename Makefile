# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 18:22:15 by vmoreau           #+#    #+#              #
#    Updated: 2020/02/28 14:02:19 by vmoreau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS =	src/main.c															 \
		\
		$(PARS)init_struct_pars.c	$(PARS)parsing.c	$(PARS)parsing_map.c \
		$(PARS)utils_parsing.c		$(PARS)check_map.c	$(PARS)check_map2.c	 \
		\
		$(EVENT)init_struct_ev.c	$(EVENT)move_w_s.c	$(EVENT)move_a_d.c	 \
		$(EVENT)rotate_g_dr.c		$(EVENT)refresh.c	$(EVENT)event.c		 \
		\
		$(MAIN)init_struct_ray.c	$(MAIN)print_map.c	$(MAIN)cub3d.c		 \
		$(MAIN)init_world.c			$(MAIN)set_images.c	$(MAIN)display.c	 \
		$(MAIN)put_mini_map.c		$(MAIN)print_img.c




OBJS = $(SRCS:.c=.o)

INCL = header/

PARS = src/parsing/

MAIN = src/main/

EVENT = src/main/event/

HEADER = $(INCL)cub3D.h

CC = clang

CFLAGS = -Werror -Wall -Wextra

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
	@$(CC) $(CFLAGS) -O3 -flto -march=native -o $@ $(OBJS) $(OBJLIB) -L ./ -lmlx
	# @$(CC) $(CFLAGS) -o $@ $(OBJS) $(OBJLIB) -g3 -fsanitize=address -L ./ -lmlx

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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 18:22:15 by vmoreau           #+#    #+#              #
#    Updated: 2020/03/11 19:55:47 by vmoreau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

####################################COLOR######################################
#----------------reset----------------#
NC = \033[0m

#-----------Regular Colors------------#
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[32m
YELLOW = \033[33;33m
BLUE = \033[0;34m
PURPLE = \033[35m
CYAN = \033[1;36m
WHITE = \033[0;37m

####################################SOURCES####################################

#-----------------Main-----------------#
SRCS +=	src/main.c

#---------------Parsing----------------#
SRCS +=	$(PARS)init_struct_pars.c	$(PARS)parsing.c	$(PARS)parsing_map.c \
		$(PARS)utils_parsing.c		$(PARS)check_map.c	$(PARS)check_map2.c	 \
		$(PARS)check_sprite.c

#----------------Event-----------------#
SRCS +=	$(EVENT)init_struct_ev.c	$(EVENT)move_w_s.c	$(EVENT)move_a_d.c	 \
		$(EVENT)rotate_g_dr.c		$(EVENT)refresh.c	$(EVENT)event.c		 \
		$(EVENT)hook.c				$(EVENT)utils.c

#---------------Display----------------#
SRCS +=	$(DISP)init_world.c			$(DISP)print_img.c	$(DISP)display.c	 \
		$(DISP)put_mini_map.c		$(DISP)set_images.c	$(DISP)print_weap.c

#---------------Save_BMP---------------#
SRCS += $(SAVE)save_bmp.c

#---------------Ray_cast---------------#
SRCS +=	$(RAY)init_struct_ray.c		$(RAY)ray_cast.c	$(RAY)cub3d.c		 \
		$(RAY)sprit_cast.c			$(RAY)sprit_cast2.c

#####################################PARTH#####################################

PARS	= src/parsing/
DISP	= src/game/display/
EVENT	= src/game/event/
RAY		= src/game/ray_cast/
SAVE	= src/game/bmp_save/

#####################################BASIC#####################################

OBJS = $(SRCS:.c=.o)
INCL = header/
HEADER = $(INCL)cub3D.h
CC = clang
CFLAGS = -Wall -Wextra
ifeq ($(d), 0)
	CFLAGS += -g3
else ifeq ($(d), 1)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
else ifeq ($(d), 2)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -ansi
	CFLAGS += -pedantic
else ifeq ($(d), 3)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -ansi
	CFLAGS += -pedantic
	CFLAGS += -Wpadded
else ifeq ($(d), 4)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -ansi
	CFLAGS += -pedantic
	CFLAGS += -Wpadded
	CFLAGS += -Weverything
endif
ifeq ($(err), no)
	CFLAGS += -g3
else
	CFLAGS += -Werror
endif

#####################################LIBFT#####################################

LIB = Libft/
OBJLIB = $(LIB)src/*/*.o

####################################MINILIBX###################################

MLX = minilibx_mms_20191207_beta/
OBJMLX = $(MLX)*.o

#####################################RULES#####################################
all : complib compmlx $(NAME)

$(OBJS) : %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(INCL) -c $< -o $@
	printf "$(CYAN).$(NC)"

$(NAME) : echoCL $(OBJS) echoOK echoCS
	$(CC) -O3 $(CFLAGS) -flto -march=native -o $@ $(OBJS) $(OBJLIB) -L ./ -lmlx
	# $(CC) $(CFLAGS) -o $@ $(OBJS) $(OBJLIB) -g3 -fsanitize=address -L ./ -lmlx


complib :
	$(MAKE) -C $(LIB) all

compmlx :
	$(MAKE) -C $(MLX) all

cleanlibft :
	$(MAKE) -C $(LIB) clean

fcleanlibft :
	$(MAKE) -C $(LIB) fclean

cleanmlx :
	$(MAKE) -C $(MLX) clean

fcleanmlx :
	$(MAKE) -C $(MLX) fclean

cleancub : echoCLEAN
	$(RM) $(OBJS)

clean : echoCLEAN cleanlibft cleanmlx
	$(RM) $(OBJS)

fclean : clean echoFCLEAN fcleanlibft fcleanmlx
	$(RM) $(NAME)
	rm -rf a.out a.out.dSYM

re : fclean all

#####################################ECHO######################################
echoCL:
	echo "$(YELLOW)===> Compiling $(RED)Cub3D$(NC)"
echoOK:
	echo "$(GREEN)OK$(NC)"
echoCS :
	echo "$(GREEN)===> Compilation Success $(RED)Cub3D Ready!!$(NC)"
echoCLEAN :
	echo "$(PURPLE)===> Cleanning OBJ Cub3D$(NC)"
echoFCLEAN :
	echo "$(PURPLE)===> Cleanning Exec$(NC)"

.PHONY : all clean fclean re complib exec cleanlibft fcleanlibft
.SILENT :

####################################COLOR######################################
#----------------reset----------------#
NC = \033[0m

#-----------Regular Colors------------#
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[32m
YELLOW = \033[33;33m
BLUE = \033[0;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[0;37m

MODULE_SRC= mlx_image.swift mlx_window.swift mlx_init.swift
MODULE_OBJ= $(MODULE_SRC:.swift=.swiftmodule)

SRC= interface.swift $(MODULE_SRC)
OBJ= $(SRC:.swift=.o)

C_SRC= mlx_xpm.c mlx_png.c mlx_string_put.c
C_OBJ= $(C_SRC:.c=.o)

NAME=libmlx.dylib

INC=-I.

all: $(NAME)

$(NAME): echoCL $(MODULE_OBJ) $(OBJ) $(C_OBJ) echoOK echoCS
	swiftc $(INC) -o $(NAME) -emit-library $(OBJ) $(C_OBJ) -lz
	mv $(NAME) ../

%.o: %.swift
	swiftc $(INC) -parse-as-library -c $< -o $@
	printf "$(CYAN)."

%.swiftmodule: %.swift
	swiftc $(INC) -parse-as-library -c $< -o $@ -emit-module -module-name $(patsubst %.swift,%,$<) -module-link-name $(patsubst %.swift,%,$<)
	printf "$(CYAN)."

$(C_OBJ) : %.o: %.c
	cc -c $< -o $@
	printf "$(CYAN)."

clean:
	rm -f $(OBJ) $(MODULE_OBJ) $(C_OBJ) *.swiftdoc *~

fclean: clean
	rm -f ../$(NAME)

#ECHO
echoCL:
	echo "$(YELLOW)===> Compiling MLX$(NC)"
echoOK:
	echo "$(GREEN)OK$(NC)"
echoCS :
	echo "$(GREEN)===> Compilation Success$(NC)"
echoCLEAN :
	echo "$(PURPLE)===> Cleanning OBJ Cub3D$(NC)"
echoFCLEAN :
	echo "$(PURPLE)===> Cleanning Exec$(NC)"


.SILENT :

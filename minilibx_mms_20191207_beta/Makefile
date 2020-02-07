MODULE_SRC= mlx_image.swift mlx_window.swift mlx_init.swift
MODULE_OBJ= $(MODULE_SRC:.swift=.swiftmodule)

SRC= interface.swift $(MODULE_SRC)
OBJ= $(SRC:.swift=.o)

C_SRC= mlx_xpm.c mlx_png.c mlx_string_put.c
C_OBJ= $(C_SRC:.c=.o)

NAME=libmlx.dylib

INC=-I.

all: $(NAME)

$(NAME): echoCL $(MODULE_OBJ) $(OBJ) $(C_OBJ) echoCS
	@swiftc $(INC) -o $(NAME) -emit-library $(OBJ) $(C_OBJ) -lz
	@mv $(NAME) ../

%.o: %.swift
	@swiftc $(INC) -parse-as-library -c $< -o $@

%.swiftmodule: %.swift
	@swiftc $(INC) -parse-as-library -c $< -o $@ -emit-module -module-name $(patsubst %.swift,%,$<) -module-link-name $(patsubst %.swift,%,$<)

$(C_OBJ) : %.o: %.c
	@cc -c $< -o $@

clean:
	@rm -f $(OBJ) $(MODULE_OBJ) $(C_OBJ) *.swiftdoc *~

fclean: clean
	@rm -f ../$(NAME)

#ECHO
echoCL:
	@echo "\033[33;33m===> Compiling MLX\033[m"
echoCS :
	@echo "\033[32m===> Compilation Success\033[m"
echoCLEAN :
	@echo "\033[35m===> Cleanning OBJ Cub3D\033[m"
echoFCLEAN :
	@echo "\033[35m===> Cleanning Exec\033[m"


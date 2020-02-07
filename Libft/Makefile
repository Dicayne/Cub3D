# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 15:18:39 by vmoreau           #+#    #+#              #
#    Updated: 2020/02/07 19:10:57 by vmoreau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = 	src/ft_atoi.c			src/ft_isalnum.c	src/ft_isalpha.c	\
		src/ft_isascii.c		src/ft_isdigit.c	src/ft_isprint.c	\
		src/ft_strchr.c			src/ft_strlcpy.c	src/ft_strlen.c		\
		src/ft_strncmp.c		src/ft_strrchr.c	src/ft_tolower.c	\
		src/ft_toupper.c		src/ft_strlcat.c	src/ft_strnstr.c	\
		src/ft_memset.c			src/ft_bzero.c		src/ft_memcpy.c		\
		src/ft_memccpy.c		src/ft_memcmp.c		src/ft_memchr.c		\
		src/ft_memmove.c		src/ft_strdup.c		src/ft_calloc.c		\
		src/ft_substr.c			src/ft_strjoin.c	src/ft_itoa.c		\
		src/ft_strmapi.c		src/ft_split.c		src/ft_strtrim.c	\
		src/ft_putchar_fd.c		src/ft_putstr_fd.c	src/ft_putendl_fd.c	\
		src/ft_putnbr_fd.c		src/ft_lstlast.c	src/ft_lstnew.c		\
		src/ft_lstclear.c		src/ft_lstiter.c	src/ft_lstmap.c		\
		src/ft_lstsize.c		src/ft_lstdelone.c	src/ft_strcmp.c		\
		src/ft_lstadd_front.c	src/ft_lstadd_back.c					\
		src/get_next_line.c		src/get_next_line_utils.c				\
		src/ft_putchar.c		src/ft_putstr.c		src/ft_putnbr.c		\

CFLAGS = -Wall -Wextra -Werror

CC = clang

INC = header/

HEADER = $(INC)libft.h

OBJ = $(SRCS:.c=.o)

OBJBO = $(SRCSBO:.c=.o)

all : $(NAME)

$(OBJ): %.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(NAME) : echoCL $(OBJ) echoCS echoAR
	@ar rcs $@ $(OBJ)

clean :	echoCLEAN
	@$(RM) $(OBJ)

fclean : clean echoFCLEAN
	@$(RM) $(NAME)

re : fclean all

#ECHO

echoCL:
	@echo "\033[33;33m===> Compiling Libft\033[m"
echoCS :
	@echo "\033[1;32m===> Compilation Success\033[m"
echoCLEAN :
	@echo "\033[35m===> Cleanning OBJ libft\033[m"
echoFCLEAN :
	@echo "\033[35m===> Cleanning Libft.a\033[m"
echoAR :
	@echo "\033[1;36m===> Archiving Libft\033[m"
.PHONY : all clean fclean re

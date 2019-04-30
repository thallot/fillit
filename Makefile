# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thallot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 14:51:59 by thallot           #+#    #+#              #
#    Updated: 2019/04/30 15:50:18 by thallot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############## COLORS ##################
_WHITE=$ \x1b[37m
_BLUE=$ \x1b[36m
_GREEN=$ \033[1;32m
_GREY=$ \x1b[33m
_RED=$ \x1b[31m

############## FLAGS ##################

NAME= fillit
CC = gcc
CFLAGS = -Werror -Wall -Wextra

############## FILES ##################

SRC= main.c \
	 read.c \
	 check_input.c \
	 tetri.c \
	 map.c \
	 free.c \
	 solve.c
	

############## PATH ##################

OBJECTS	= $(SRC:.c=.o)

.PHONY: clean fclean re all

all: $(NAME)
$(NAME): $(OBJECTS)
	@make -C libft
	@$(CC) $(OBJECTS) libft/libft.a -o $(NAME)
	@make clean -C libft
	@echo "$(_GREEN)[OK] $(_BLUE)Compilation de $(_WHITE)$(NAME)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $(SRC)

clean:
	@rm -rf $(OBJECTS)
	@echo "$(_GREEN)[OK]$(_RED) Supression de tous les objets"

fclean: clean
	@rm -rf $(NAME) $(EXE)
	@rm -rf libft/libft.a
	@echo "$(_GREEN)[OK]$(_RED) Supression de $(_WHITE)$(NAME)"
	@echo "$(_GREEN)[OK]$(_RED) Supression de tous les fichiers$(_WHITE)"

re: fclean all
	@echo "$(_GREEN)[OK]$(_BLUE) Succes $(_WHITE)"

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 16:21:33 by yothmani          #+#    #+#              #
#    Updated: 2024/03/01 11:26:53 by yothmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRC_FILES = lib.c lib2.c lib3.c lib4.c lib5.c \
            low_sort.c high_sort.c main.c push_swap.c \
            push.c reverse_rotate.c rotate.c swap.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

INC = -I$(INC_DIR)

RM = rm -rf

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/push_swap.h
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ)
	@echo "✨ $(NAME) has been compiled successfully! ✨"

clean:
	@$(RM) $(OBJ_DIR)
	@echo "🧹 Cleaned object files!"

fclean: clean
	@$(RM) $(NAME)
	@echo "🗑️  Cleaned executable!"

re: fclean all

Visualizer:
	./push_swap_visualizer/build/bin/visualizer
.PHONY: all clean re fclean	

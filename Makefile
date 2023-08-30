# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 16:21:33 by yothmani          #+#    #+#              #
#    Updated: 2023/08/30 19:09:25 by yothmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

SRCS = lib.c lib2.c lib3.c lib4.c lib5.c\
low_sort.c high_sort.c main.c push_swap.c\
push.c reverse_rotate.c rotate.c swap.c\

OBJS = ${SRCS:.c=.o}

GCC = @gcc -Wall -Werror -Wextra -g

RM = rm -rf

INCLUDES = ./

.c.o:
	$(GCC) -I $(INCLUDES) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	GCC -o $(NAME) $(OBJS)

all:	$(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) push_swap.dSYM

re:	fclean all

Visualizer:
	./push_swap_visualizer/build/bin/visualizer
.PHONY: all clean re fclean	
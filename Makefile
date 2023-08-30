# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 16:21:33 by yothmani          #+#    #+#              #
#    Updated: 2023/08/30 16:23:22 by yothmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

SRCS = push_swap.c lib.c swap.c main.c lib2.c lib3.c\
low_sort.c  push.c\
reverse_rotate.c rotate.c\
lib5.c lib4.c high_sort.c\

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
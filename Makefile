# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 15:14:08 by fbelotti          #+#    #+#              #
#    Updated: 2024/04/17 17:11:38 by fbelotti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	FdF

CC =	gcc
RM =	rm -f

CFLAGS = -Wall -Wextra -Werror -g
CFLAGS += -I./libft -I
LDFLAGS = -L./libft -lft

SRCS =	./pipex.c \

OBJS =	$(SRCS:.c=.o)

all: announce libft $(NAME) finished

announce:
	@echo "Author: Florent Belotti"
	@echo "Project: Pipex"

$(NAME):	$(OBJS) libft
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -lm -o $(NAME)
	@echo "Compilation of $(NAME) finished."

libft:
	@make -C ./libft

clean :
	@$(RM) $(OBJS)
	@make -C ./libft clean
	@echo "Cleaned."

fclean : clean
	@$(RM) $(NAME)
	@make -C ./libft fclean
	@echo "Fully cleaned."

re : fclean all

finished:
	@echo "Make process finished."

.PHONY: all clean fclean re libft announce finished

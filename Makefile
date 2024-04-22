# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 15:14:08 by fbelotti          #+#    #+#              #
#    Updated: 2024/04/22 12:43:22 by fbelotti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	pipex

CC =	gcc
RM =	rm -f

CFLAGS = -Wall -Wextra -Werror -g
CFLAGS += -I./libft
LDFLAGS = -L./libft -lft

SRCS =	./handle_path.c ./handle_process.c ./pipex.c \

OBJS =	$(SRCS:.c=.o)

all: announce libft $(NAME) finished

announce:
	@echo "Author: Florent Belotti"
	@echo "Project: Pipex"

$(NAME):	$(OBJS) ./libft
	@$(CC) -v $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "Compilation of $(NAME) finished."

libft:
	@make -C ./libft -j

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

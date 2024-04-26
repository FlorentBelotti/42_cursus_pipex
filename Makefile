# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 15:14:08 by fbelotti          #+#    #+#              #
#    Updated: 2024/04/26 17:31:20 by fbelotti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	pipex
NAMEB = pipex_bonus

CC =	gcc
RM =	rm -f

CFLAGS = -Wall -Wextra -Werror -g
CFLAGS += -I./libft
LDFLAGS = -L./libft -lft

SRCS =	./Sources/handle_path.c ./Sources/handle_process.c ./Sources/pipex.c \

BONUS = ./Bonus/pipex_bonus.c ./Bonus/bonus_handle_here_doc.c \
		./Bonus/bonus_handle_path.c ./Bonus/bonus_handle_process.c \
		./Bonus/bonus_utils.c \

OBJS =	$(SRCS:.c=.o)
OBJSBONUS = $(BONUS:.c=.o)

all: announce libft $(NAME) finished
bonus : announce libft $(NAMEB) finished

announce:
	@echo "Author: Florent Belotti"
	@echo "Project: Pipex"

$(NAME):	$(OBJS) ./libft
	@$(CC) -v $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "Compilation of $(NAME) finished."

$(NAMEB):	$(OBJSBONUS) ./libft
	@$(CC) -v $(CFLAGS) $(OBJSBONUS) $(LDFLAGS) -o $(NAMEB)
	@echo "Compilation of $(NAMEB) finished."

libft:
	@make -C ./libft -j

clean :
	@$(RM) $(OBJS) $(OBJSBONUS)
	@make -C ./libft clean
	@echo "Cleaned."

fclean : clean
	@$(RM) $(NAME) $(NAMEB) $(OBJSBONUS)
	@make -C ./libft fclean
	@echo "Fully cleaned."

re : fclean all

finished:
	@echo "Make process finished."

.PHONY: all bonus clean fclean re libft announce finished

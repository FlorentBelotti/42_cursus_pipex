# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 15:14:08 by fbelotti          #+#    #+#              #
#    Updated: 2024/06/20 00:44:59 by fbelotti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAMEB = pipex_bonus
AUTHOR = Florent Belotti

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./Includes/libft
LDFLAGS = -L./Includes/libft -lft

SRCDIR = Src
BONUSDIR = Bonus
OBJDIR = obj

SRCS = $(SRCDIR)/handle_path.c $(SRCDIR)/handle_process.c $(SRCDIR)/pipex.c
BONUS = $(BONUSDIR)/pipex_bonus.c $(BONUSDIR)/bonus_handle_here_doc.c \
        $(BONUSDIR)/bonus_handle_path.c $(BONUSDIR)/bonus_handle_process.c \
        $(BONUSDIR)/bonus_utils.c

OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
OBJSBONUS = $(patsubst $(BONUSDIR)/%.c,$(OBJDIR)/%.o,$(BONUS))

DEPS = $(OBJS:.o=.d) $(OBJSBONUS:.o=.d)

all: announce intro libft $(NAME) finished
bonus: announce intro libft $(NAMEB) finished

announce:
	@echo "\n==================================="
	@echo "Author: $(AUTHOR)"
	@echo "Project: $(NAME)"
	@echo "===================================\n"

intro:
	@echo "Starting the build process...\n"

$(NAME): $(OBJS)
	@echo "pipex:	libft:	Creating library..."
	@$(MAKE) -C ./Includes/libft > /dev/null
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@
	@echo "\npipex: Executable $@ created."

$(NAMEB): $(OBJSBONUS)
	@echo "pipex_bonus:	libft:	Creating library..."
	@$(MAKE) -C ./Includes/libft > /dev/null
	@echo "pipex_bonus:	Creating executable $@..."
	@$(CC) $(CFLAGS) $(OBJSBONUS) $(LDFLAGS) -o $@
	@echo "pipex_bonus:	Executable $@ created."

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)/$(SRCDIR)
	@echo "pipex:	Creating executable $@..."
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

$(OBJDIR)/%.o: $(BONUSDIR)/%.c
	@mkdir -p $(OBJDIR)/$(BONUSDIR)
	@echo "pipex_bonus:	Creating executable $@..."
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

libft:
	@$(MAKE) -C ./Includes/libft > /dev/null

-include $(DEPS)

clean:
	@$(RM) $(OBJS) $(OBJSBONUS)
	@$(MAKE) -C ./Includes/libft clean > /dev/null
	@echo "Cleaned."

fclean: clean
	@$(RM) $(NAME) $(NAMEB)
	@$(MAKE) -C ./Includes/libft fclean > /dev/null
	@echo "Fully cleaned."

re: fclean all

debug: CFLAGS += $(DEBUG_FLAGS)
debug: re

finished:
	@echo "Make process finished."

.PHONY: all bonus clean fclean re libft announce finished intro

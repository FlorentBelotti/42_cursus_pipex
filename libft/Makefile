# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 10:53:01 by fbelotti          #+#    #+#              #
#    Updated: 2024/03/17 15:56:17 by fbelotti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
HEADER	=	libft.h

CC	= gcc -Wall -Wextra -Werror
RM	=	rm -f

LIBFT_SRCS	=	./libft_srcs/ft_strlen.c ./libft_srcs/ft_isascii.c \
				./libft_srcs/ft_memcpy.c ./libft_srcs/ft_strlcat.c \
				./libft_srcs/ft_tolower.c ./libft_srcs/ft_bzero.c \
				./libft_srcs/ft_isdigit.c ./libft_srcs/ft_memmove.c \
				./libft_srcs/ft_strlcpy.c ./libft_srcs/ft_toupper.c \
				./libft_srcs/ft_calloc.c ./libft_srcs/ft_isprint.c \
				./libft_srcs/ft_memset.c ./libft_srcs/ft_strncmp.c \
				./libft_srcs/ft_isalnum.c ./libft_srcs/ft_memchr.c \
				./libft_srcs/ft_strchr.c ./libft_srcs/ft_strnstr.c \
				./libft_srcs/ft_isalpha.c ./libft_srcs/ft_memcmp.c \
				./libft_srcs/ft_strdup.c ./libft_srcs/ft_strrchr.c \
				./libft_srcs/ft_atoi.c ./libft_srcs/ft_itoa.c \
				./libft_srcs/ft_putendl_fd.c ./libft_srcs/ft_putnbr_fd.c \
				./libft_srcs/ft_putstr_fd.c ./libft_srcs/ft_split.c \
				./libft_srcs/ft_putchar_fd.c ./libft_srcs/ft_striteri.c \
				./libft_srcs/ft_strjoin.c ./libft_srcs/ft_strmapi.c \
				./libft_srcs/ft_strtrim.c ./libft_srcs/ft_substr.c \
				./libft_bonus/ft_lstadd_back.c ./libft_bonus/ft_lstadd_front.c \
				./libft_bonus/ft_lstclear.c ./libft_bonus/ft_lstdelone.c \
				./libft_bonus/ft_lstiter.c ./libft_bonus/ft_lstlast.c \
				./libft_bonus/ft_lstmap.c ./libft_bonus/ft_lstnew.c \
				./libft_bonus/ft_lstsize.c \

PRINTF_SRCS	=	./ft_printf/ft_printf_conversions.c \
				./ft_printf/ft_printf_main.c \
				./ft_printf/ft_printf_utils.c \

GNL_SRCS	=	./get_next_line/get_next_line_bonus.c \
				./get_next_line/get_next_line_bonus_utils.c \

CUSTOM		=	./custom/ft_strtol.c ./custom/ft_ishex.c \
				./custom/ft_free_array.c ./custom/ft_free_list.c \
				./custom/ft_strcmp.c \

SRCS	= $(LIBFT_SRCS) $(PRINTF_SRCS) $(GNL_SRCS) $(CUSTOM)
OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) -c $< -o $@

clean :
	rm -f $(OBJS) $(OBJSBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

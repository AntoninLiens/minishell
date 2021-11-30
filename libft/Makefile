# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zminhas <zminhas@students.s19.be>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 17:05:49 by ctirions          #+#    #+#              #
#    Updated: 2021/11/30 17:03:22 by zminhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#			COLORS

BLACK		= $(shell tput -Txterm setaf 0)
RED			= $(shell tput -Txterm setaf 1)
GREEN		= $(shell tput -Txterm setaf 2)
YELLOW		= $(shell tput -Txterm setaf 3)
LIGHTPURPLE	= $(shell tput -Txterm setaf 4)
PURPLE		= $(shell tput -Txterm setaf 5)
BLUE		= $(shell tput -Txterm setaf 6)
WHITE		= $(shell tput -Txterm setaf 7)
RESET		= $(shell tput -Txterm sgr0)

#			SOURCES

SRCS		= ft_atoi.c \
			  ft_isprint.c \
			  ft_lstlast.c \
			  ft_memcpy.c \
			  ft_split.c \
			  ft_strmapi.c \
			  ft_toupper.c \
			  ft_bzero.c \
			  ft_itoa.c \
			  ft_memmove.c \
			  ft_strchr.c \
			  ft_strncmp.c \
			  ft_calloc.c \
			  ft_memset.c \
			  ft_strdup.c \
			  ft_strnstr.c \
			  ft_isalnum.c \
			  ft_putchar_fd.c \
			  ft_strjoin.c \
			  ft_strrchr.c \
			  ft_isalpha.c \
			  ft_memccpy.c \
			  ft_putendl_fd.c \
			  ft_strlcat.c \
			  ft_strtrim.c \
			  ft_isascii.c \
			  ft_memchr.c \
			  ft_putnbr_fd.c \
			  ft_strlcpy.c \
			  ft_substr.c \
			  ft_isdigit.c \
			  ft_memcmp.c \
			  ft_putstr_fd.c \
			  ft_strlen.c \
			  ft_tolower.c \
			  ft_ternarys.c

SRCS_BONUS	= ft_lstnew.c \
			  ft_lstadd_front.c \
			  ft_lstsize.c \
			  ft_lstlast.c \
			  ft_lstadd_back.c \
			  ft_lstdelone.c \
			  ft_lstclear.c \
			  ft_lstiter.c \
			  ft_lstmap.c

SRCS_GNL	= get_next_line.c \
			  get_next_line_utils.c\

SRCS_PRINTF	= ft_convert_c.c \
			  ft_convert_i_d.c \
			  ft_convert_p.c \
			  ft_convert_s.c \
			  ft_convert_u.c \
			  ft_convert_x.c \
			  ft_execute.c \
			  ft_get_element.c \
			  ft_printf.c \
			  ft_utils.c

#			OBJECTS

OBJS		= $(addprefix srcs/, ${SRCS:.c=.o})

OBJS_BONUS	= $(addprefix srcs/, ${SRCS_BONUS:.c=.o})

OBJS_GNL	= $(addprefix srcs/GNL/, ${SRCS_GNL:.c=.o})

OBJS_PRINTF	= $(addprefix srcs/ft_printf/, ${SRCS_PRINTF:.c=.o})

#			MAIN

NAME		= libft.a
RM			= rm -f

.c.o:
			@gcc -Wall -Wextra -Werror -c -I./includes $< -o ${<:.c=.o}

$(NAME):	${OBJS} ${OBJS_PRINTF} ${OBJS_GNL}
			@ar -rcs ${NAME} ${OBJS} ${OBJS_PRINTF} ${OBJS_GNL}

all:		${NAME}

bonus:		${OBJS_BONUS}
			@ar -rcs ${NAME} ${OBJS_BONUS}

full:		all	bonus

clean:
			@$(RM) ${OBJS} ${OBJS_PRINTF} ${OBJS_GNL} ${OBJS_BONUS}

fclean:		
			@$(RM) ${OBJS} ${OBJS_PRINTF} ${OBJS_GNL} ${OBJS_BONUS}
			@$(RM) $(NAME)
			
re:			fclean all

.PHONY:		all clean fclean re bonus full

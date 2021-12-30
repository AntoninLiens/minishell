# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliens <aliens@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 14:42:50 by aliens            #+#    #+#              #
#    Updated: 2021/12/30 12:05:39 by aliens           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED		=	$(shell tput -Txterm setaf 1)
GREEN	=	$(shell tput -Txterm setaf 2)
PURPLE	=	$(shell tput -Txterm setaf 5)
BLUE	=	$(shell tput -Txterm setaf 6)
RESET	=	$(shell tput -Txterm sgr0)

SRCSDIR = 	srcs/
OBJSDIR = 	objs/

FILES =		init/init_env.c			\
			init/shlvl.c		\
			parser/parse.c		\
			parser/env.c		\
			exec/minishell.c	\
			exec/exec.c			\
			utils/utils.c		\
			utils/signals.c		\
			utils/pipes.c		\
			commands/pwd.c		\
			commands/env.c		\
			commands/variables.c\
			commands/echo.c		\
			commands/cd.c

SRCS	=	$(addprefix srcs/, $(FILES))
OBJS	=	$(patsubst srcs%.c, objs%.o, $(SRCS))

NAME	=	minishell
RM		=	rm -f
CC		=	gcc -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C ./libft
			@$(CC) -o $(NAME) $(OBJS) libft/libft.a -lreadline
			@echo "[$(GREEN)✓$(RESET)] minishell created"
			
objs/%.o:	srcs/%.c
			@printf "[$(PURPLE)✓$(RESET)] compilation of $<       \r"
			@$(CC) $(CFLAGS) -c -I./includes $^ -o $@

run:		@make && ./minishell

clean:
			@make clean -C ./libft
			@$(RM) $(OBJS)
			@echo "[$(BLUE)✓$(RESET)] objects erased"

fclean:
			@make fclean -C ./libft		
			@$(RM) $(OBJS)
			@echo "[$(BLUE)✓$(RESET)] objects erased"
			@$(RM) $(NAME)
			@echo "[$(RED)✓$(RESET)] minishell erased"

re:			fclean $(NAME)

.PHONY:		all clean fclean re minishell .c.o
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 14:42:50 by aliens            #+#    #+#              #
#    Updated: 2021/12/21 17:07:08 by ctirions         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED		=	$(shell tput -Txterm setaf 1)
GREEN	=	$(shell tput -Txterm setaf 2)
PURPLE	=	$(shell tput -Txterm setaf 5)
BLUE	=	$(shell tput -Txterm setaf 6)
RESET	=	$(shell tput -Txterm sgr0)

SRCSDIR = srcs/
OBJSDIR = objs/

FILES	=	minishell.c				\
			init.c					\
			utils.c					\
			shlvl.c					\
			env.c					\
			exec.c					\
			signals.c				\
			parse.c					\
			pipes.c					\
			commands/pwd.c			\
			commands/env.c			\
			commands/variables.c	\
			commands/echo.c			\
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
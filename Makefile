# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 14:42:50 by aliens            #+#    #+#              #
#    Updated: 2021/12/14 17:04:56 by ctirions         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED		=	$(shell tput -Txterm setaf 1)
GREEN	=	$(shell tput -Txterm setaf 2)
PURPLE	=	$(shell tput -Txterm setaf 5)
BLUE	=	$(shell tput -Txterm setaf 6)
RESET	=	$(shell tput -Txterm sgr0)

SRCSDIR = srcs/
OBJSDIR = objs/

FILES	=	minishell.c	\
			init.c		\
			utils.c		\
			shlvl.c		\
			env.c		\
			signals.c

SRCS	=	$(addprefix srcs/, $(FILES))
OBJS	=	$(patsubst srcs%.c, objs%.o, $(SRCS))

NAME	=	minishell
RM		=	rm -f
CC		=	gcc -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C ./libft
			@$(CC) $(SRCS) libft/libft.a -lreadline -o $(NAME)
			@echo "[$(GREEN)✓$(RESET)] minishell created"
.c.o:
			@printf "[$(PURPLE)✓$(RESET)] compilation of $<       \r"
			@$(CC) $(CFLAGS) -c -I./includes $^ -o $(patsubst srcs%, objs%, $@)

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
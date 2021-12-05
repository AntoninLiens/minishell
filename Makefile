# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 14:42:50 by aliens            #+#    #+#              #
#    Updated: 2021/12/05 01:20:31 by ctirions         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED		=	$(shell tput -Txterm setaf 1)
GREEN	=	$(shell tput -Txterm setaf 2)
PURPLE	=	$(shell tput -Txterm setaf 5)
BLUE	=	$(shell tput -Txterm setaf 6)
RESET	=	$(shell tput -Txterm sgr0)

SRCSDIR = srcs
OBJSDIR = objs

SRCS	=	srcs/minishell.c	\
			srcs/init.c		\
			srcs/utils.c		\
			srcs/shlvl.c		\
			srcs/env.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	minishell
RM		=	rm -f
CC		=	gcc -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo ""
			@make -C ./libft
			@$(CC) $(SRCS) libft/libft.a -lreadline -o $(NAME)
			@echo "[$(GREEN)✓$(RESET)] minishell created"
			@mv $(OBJS) $(OBJSDIR)

.c.o:
			@printf "[$(PURPLE)✓$(RESET)] compilation of $<       \r"
			@$(CC) $(CFLAGS) -c -I./includes $< -o $(<:.c=.o)

clean:
			@make clean -C ./libft
			@$(RM) $(OBJSDIR)/*.o
			@echo "[$(BLUE)✓$(RESET)] objects erased"

fclean:
			@make fclean -C ./libft		
			@$(RM) $(OBJSDIR)/*.o
			@echo "[$(RED)✓$(RESET)] objects erased"
			@$(RM) $(NAME)
			@echo "[$(RED)✓$(RESET)] minishell erased"

re:			fclean $(NAME)

.PHONY:		all clean fclean re minishell .c.o
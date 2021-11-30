# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliens <aliens@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 14:42:50 by aliens            #+#    #+#              #
#    Updated: 2021/11/30 15:11:16 by aliens           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED		=	$(shell tput -Txterm setaf 1)
GREEN	=	$(shell tput -Txterm setaf 2)
PURPLE	=	$(shell tput -Txterm setaf 5)
BLUE	=	$(shell tput -Txterm setaf 6)
RESET	=	$(shell tput -Txterm sgr0)

SRCS	=	

OBJS	=	$(SRCS:.c=.o)

NAME	=	minishell
RM		=	rm -f
CC		=	gcc -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C ./libft
			@$(CC) libft/libft.a $(SRCS) -o $(NAME)
			@echo "[$(GREEN)✓$(RESET)] minishell created"

.c.o:
			@$(CC) $(CFLAGS) -c -I./includes $< -o $(<:.c=.o)
			@echo "[$(PURPLE)✓$(RESET)] compilation of $<"

clean:
			make clean -C ./libft
			@$(RM) $(OBJS)
			@echo "[$(BLUE)✓$(RESET)] objects erased"

fclean:
			make fclean -C ./libft		
			@$(RM) $(OBJS)
			@echo "[$(BLUE)✓$(RESET)] objects erased"
			@$(RM) $(NAME)
			@echo "[$(RED)✓$(RESET)] minishell erased"

re:			fclean $(NAME)

.PHONY:		all clean fclean re minishell .c.o
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 13:51:47 by agpereir          #+#    #+#              #
#    Updated: 2024/04/17 16:37:47 by agpereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#CORLORS
RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= 033[1;33m
BLUE	= \033[1;34m
MAGENTA	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

#LIBFT
LIB_PATH = ./libft

#COMMANDS
CC = gcc
RM = rm -f
CFLAGS = -pthread -Wall -Wextra -Werror -g -fsanitize=thread
INCLUDE = -I include
MAKE = make -s -C
LIBFT_PATH = libft
LFLAGS = -L ${LIBFT_PATH} -lft -lreadline

#FILES

NAME 	= philo
SRCS 	= 	srcs/fork.c \
			srcs/get_time.c \
			srcs/init.c \
			srcs/is_eating.c \
			srcs/is_sleeping.c \
			srcs/is_thinking.c \
			srcs/main.c \
			srcs/parse.c \
			srcs/routine.c


OBJS_PATH = objs
OBJS = $(SRCS:%.c=$(OBJS_PATH)/%.o)

$(OBJS_PATH)/%.o: %.c
	@mkdir -p $(@D)
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@
	@echo "$(GREEN)$(NAME)$(RESET) : $(CYAN)Compiling $<$(RESET)"

$(NAME): ${OBJS}
		@${MAKE} ${LIBFT_PATH}
		@${CC} ${CFLAGS} ${INCLUDE} ${OBJS} ${LFLAGS} -o ${NAME}
		@echo "$(GREEN)${LIBFT_PATH}$(RESET) : $(CYAN)Compilation done$(RESET)"
		@echo "$(GREEN)$(NAME)$(RESET) : $(CYAN)Compilation done$(RESET)"

all:	${NAME}

clean:
		@${MAKE} ${LIBFT_PATH} clean
		@echo "$(GREEN)$(LIBFT_PATH)$(RESET) : $(CYAN)Cleaning done$(RESET)"
		@${RM} ${OBJS}
		@echo "$(GREEN)$(NAME)$(RESET) : $(CYAN)Cleaning done$(RESET)"

fclean: clean
		@${MAKE} ${LIBFT_PATH} fclean 
		@${RM} ${NAME}
		@echo "$(GREEN)$(NAME)$(RESET) : $(CYAN)Full Cleaning done$(RESET)"

re: fclean all 

.PHONY: all clean fclean re 






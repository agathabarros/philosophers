# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agpereir <agpereir@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 13:51:47 by agpereir          #+#    #+#              #
#    Updated: 2024/04/22 13:14:33 by agpereir         ###   ########.fr        #
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

#COMMANDS
CC = gcc
RM = rm -f
CFLAGS = -pthread -Wall -Wextra -Werror -g -fsanitize=thread
INCLUDE = -I include

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
			srcs/utils.c \
			srcs/routine.c


OBJS_PATH = objs
OBJS = $(SRCS:%.c=$(OBJS_PATH)/%.o)

$(OBJS_PATH)/%.o: %.c
	@mkdir -p $(@D)
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@
	@echo "$(GREEN)$(NAME)$(RESET) : $(CYAN)Compiling $<$(RESET)"

$(NAME): ${OBJS}
		@${CC} ${CFLAGS} ${INCLUDE} ${OBJS} ${LFLAGS} -o ${NAME}
		@echo "$(GREEN)$(NAME)$(RESET) : $(CYAN)Compilation done$(RESET)"

all:	${NAME}

clean:
		@${RM} ${OBJS}
		@echo "$(GREEN)$(NAME)$(RESET) : $(CYAN)Cleaning done$(RESET)"

fclean: clean
		@${RM} ${NAME}
		@echo "$(GREEN)$(NAME)$(RESET) : $(CYAN)Full Cleaning done$(RESET)"

re: fclean all 

.PHONY: all clean fclean re 






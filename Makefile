# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agpereir <agpereir@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 13:51:47 by agpereir          #+#    #+#              #
#    Updated: 2024/03/27 13:36:07 by agpereir         ###   ########.fr        #
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
CC = cc -g 
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=address
INCLUDE = -I include
MAKE = make -C
LIBFT_PATH = libft
LFLAGS = -L ${LIBFT_PATH} -lft -lreadline

#FILES

NAME 	= philo
SRCS 	= 	$(wildcard srcs/*.c)

OBJS_PATH = objs
OBJS = $(SRCS:%.c=$(OBJS_PATH)/%.o)

$(OBJS_PATH)/%.o: %.c
	@mkdir -p $(@D)
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@
	@echo "$(GREEN)$(NAME)$(RESET) : $(CYAN)Compiling $<$(RESET)"

$(NAME): ${OBJS}
		@${MAKE} ${LIBFT_PATH}
		@${CC} ${CFLAGS} ${INCLUDE} ${OBJS} ${LFLAGS} -o ${NAME}
		@echo "$(GREEN)$(NAME)$(RESET) : $(CYAN)Compilation done$(RESET)"

all:	${NAME}

clean:
		@${MAKE} ${LIBFT_PATH} clean
		@${RM} ${OBJS}
		@echo "$(GREEN)$(NAME)$(RESET) : $(CYAN)Cleaning done$(RESET)"

fclean: clean
		@${MAKE} ${LIBFT_PATH} fclean
		@${RM} ${NAME}
		@echo "$(GREEN)$(NAME)$(RESET) : $(CYAN)Full Cleaning done$(RESET)"

re: fclean all

.PHONY: all clean fclean re 






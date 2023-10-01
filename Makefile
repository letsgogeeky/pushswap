# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/12 20:26:46 by ramoussa          #+#    #+#              #
#    Updated: 2023/10/01 19:33:00 by ramoussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= push_swap
B_NAME := checker

CFLAGS	:= -Wextra -Wall -Werror -g -fsanitize=address
BASELIB := ./lib/ft-baselib

HEADERS := -I ./include -I ${BASELIB}/include
LIBS := ${BASELIB}/baselib.a

SRCS := operations/swap.c operations/rotate.c \
		operations/reverse.c operations/push.c \
		meta.c sort.c go_big.c insertion.c \
		parser.c utils.c stack.c error.c
MANDATORY := main.c
BONUS := bonus/checker.c
OBJS := ${addprefix src/, ${SRCS:.c=.o} ${MANDATORY:.c=.o}}
BONUS_OBJS := ${addprefix src/, ${SRCS:.c=.o} ${BONUS:.c=.o}}

all: BASELIB ${NAME}

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

${NAME}: ${OBJS}
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) && echo "Successful build...!"

${B_NAME}: ${BONUS_OBJS}
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBS) $(HEADERS) -o $(B_NAME) && echo "Bonus Successful build...!"

BASELIB:
	@if [ -d ${BASELIB} ]; then\
		echo "${BASELIB} already exists... proceeding to next step.";\
	else\
		mkdir lib;\
		git clone git@github.com:letsgogeeky/ft-baselib.git ${BASELIB};\
	fi
	make --directory=${BASELIB}

bonus: BASELIB ${B_NAME}

clean:
	@rm -rf $(OBJS)
	@rm -rf ${BONUS_OBJS}

fclean: clean
	make fclean --directory=${BASELIB}
	rm -f ${NAME}
	rm -f ${B_NAME}

re: fclean all

.PHONY: all rmlib clean fclean re
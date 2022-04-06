# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dyeboa <dyeboa@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/26 14:06:32 by dyeboa        #+#    #+#                  #
#    Updated: 2022/03/31 16:34:06 by dyeboa        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		= gcc
SRCS	= 
OBJS	= $(SRCS:.c=.o)
FLAGS	= -Wall -Wextra

.c.o :
	${CC} -c ${FLAGS} -o $@ $<

$(NAME): ${OBJS}
	ar -rcs $(NAME) $(OBJS)

run:
	rm -f run
	${CC} ${FLAGS} $(SRCS) main.c -o run
	./run

all: $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(NAME)
	rm -f run

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY:	all clean fclean
	
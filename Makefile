# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dyeboa <dyeboa@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/26 14:06:32 by dyeboa        #+#    #+#                  #
#    Updated: 2022/06/10 16:44:14 by dyeboa        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= gcc  
FLAGS	= -c -Wall -Wextra -Werror -I${INCLUDE} -I./${LIB_DIR}	  
INCLUDE = ./include
LIB_DIR = libft
LIBFT	= ${LIB_DIR}/libft.a
SRC_DIR	=	src
SRC		=	input_check.c\
			main.c\
			list.c\
			sort.c\
			commands.c\
			parser.c\
			sort_small.c\
			sort_utils.c

vpath %.c ${SRC_DIR}

OBJ_DIR	=	obj
OBJ		=	$(patsubst %.c, ${OBJ_DIR}/%.o, ${SRC})

all: $(NAME)

${NAME}: ${OBJ} ${LIBFT}
		 ${CC} -o $@ $^ -g -fsanitize=address
		 
${LIBFT}:
			${MAKE} -C ${LIB_DIR}
${OBJ_DIR}/%.o	:	%.c
			mkdir -p ${OBJ_DIR}
			${CC} ${FLAGS} -g $< -o $@

clean	:
			${MAKE} clean -C ${LIB_DIR}
			rm -rf ${OBJ_DIR}

fclean	:	clean
			${MAKE} fclean -C ${LIB_DIR}
			rm -rf ${NAME}

re		:	fclean all

.PHONY	:	clean fclean all 
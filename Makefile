# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dyeboa <dyeboa@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/26 14:06:32 by dyeboa        #+#    #+#                  #
#    Updated: 2022/06/10 18:13:58 by dyeboa        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Program name
NAME	= push_swap
CC = gcc

CFLAGS = -Wall -Wextra -Werror -I ${INCLUDE}
INCLUDE = ./include


SRC_DIR	=	src
SRC_FILES =	input_check.c\
			main.c\
			list.c\
			sort.c\
			commands.c\
			parser.c\
			sort_small.c\
			sort_utils.c

HEADER_FILES = 	push_swap.h \
			
# object files
OBJ_DIR	=	obj
OBJ 	= $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

# Libft
LIBFT_DIR = libft



# all
all: $(NAME)

.c.o:
	${CC} ${CFLAGS} -I$(INCLUDE) -c $< -o ${<:.c=.o}
			
# obj dir
${OBJ_DIR}:
	mkdir -p ${OBJ_DIR}

# Libft
$(LIBFT):
	make -C libft

# Build executable
${NAME}: ${OBJ_FILES} 
	$(CC) $(CFLAGS) $^ libft/$(LIBFT) -o $@

$(OBJ_FILES): $(OBJ_DIR)/%.o : %.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -rf ${OBJ_DIR}
	${MAKE} fclean -C ${LIB_DIR}

fclean:	clean
	rm -rf ${NAME}

re : fclean all

.PHONY : clean fclean all 
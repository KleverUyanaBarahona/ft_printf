# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klever <klever@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/11 19:47:39 by kbarahon          #+#    #+#              #
#    Updated: 2020/10/12 02:39:15 by klever           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_atoi.c ft_inspector_format.c ft_isalpha.c ft_isdigit.c \
		ft_num_len.c ft_printf.c ft_strcmp.c get_data_type.c init_values_t_var.c \
		print_caracter.c print_percentage.c print_zero_space.c put_fuctions.c \
		reset_values_t_var.c spect_format.c

SRC: main.c		

OBJS        =   ${SRCS:.c=.o}

CC          =   gcc

CFLAGS      =   -c -Wall -Wextra -Werror -g

RM			=	rm -f

all:		$(NAME)

$(NAME):	${SRCS}
	${CC} ${CFLAGS} ${SRCS}
	ar -rc ${NAME} ${OBJS}
	ranlib ${NAME}

clean:	
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

made: ${CC} ${CFLAGS} ${SRC} libftprintf.a

.PHONY:		all clean fclean re
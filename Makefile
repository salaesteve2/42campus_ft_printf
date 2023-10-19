# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 15:18:29 by sasalama          #+#    #+#              #
#    Updated: 2022/02/23 12:21:55 by sasalama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = ft_printf.c ft_itoa.c ft_itoa2.c ft_print_hex.c ft_putchar_fd.c ft_putstr_fd.c
OBJS    = ${SRCS:.c=.o}
NAME    = libftprintf.a
CC  = gcc
RM  = rm -f
CFLAGS  = -Wall -Wextra -Werror
AR = ar rc
.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:    ${OBJS}
				${AR} ${NAME} ${OBJS}
				ranlib ${NAME}
all:        ${NAME} 
clean:
				${RM} ${OBJS}
fclean:     clean
				${RM} ${NAME}
re:         fclean all
.PHONY:     all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 10:55:42 by thbierne          #+#    #+#              #
#    Updated: 2024/02/07 11:01:31 by thbierne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/ft_isalnum.c 			\
			srcs/ft_isprint.c 			\
			srcs/ft_memcmp.c 			\
			srcs/ft_putnbr_fd.c 		\
			srcs/ft_putchar_fd.c 		\
			srcs/ft_split.c 			\
			srcs/ft_strlcat.c 			\
			srcs/ft_strncmp.c 			\
			srcs/ft_substr.c 			\
			srcs/ft_atoi.c 				\
			srcs/ft_isalpha.c 			\
			srcs/ft_itoa.c 				\
			srcs/ft_memcpy.c 			\
			srcs/ft_putendl_fd.c 		\
			srcs/ft_strchr.c 			\
			srcs/ft_strlcpy.c 			\
			srcs/ft_strnstr.c 			\
			srcs/ft_tolower.c 			\
			srcs/ft_bzero.c 			\
			srcs/ft_isascii.c 			\
			srcs/ft_memccpy.c 			\
			srcs/ft_memmove.c 			\
			srcs/ft_strdup.c 			\
			srcs/ft_strlen.c 			\
			srcs/ft_strrchr.c 			\
			srcs/ft_toupper.c 			\
			srcs/ft_calloc.c 			\
			srcs/ft_isdigit.c 			\
			srcs/ft_memchr.c 			\
			srcs/ft_memset.c 			\
			srcs/ft_putstr_fd.c 		\
			srcs/ft_strjoin.c 			\
			srcs/ft_strmapi.c 			\
			srcs/ft_strtrim.c 			\

OBJS    = ${SRCS:.c=.o}
NAME    = libft.a
CC      = gcc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror



all:        ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):    ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

clean:
	${RM} ${OBJS}

fclean:     clean
	${RM} ${NAME}

re:         fclean all

.PHONY:     all clean fclean re
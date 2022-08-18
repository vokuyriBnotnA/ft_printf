# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 14:16:56 by klemongr          #+#    #+#              #
#    Updated: 2021/11/11 15:14:37 by klemongr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIST =	ft_printf.c \
		ft_printf_flags.c \
		ft_printf_type.c \
		ft_printf_pct.c \
		ft_printf_c.c \
		ft_printf_s.c \
		ft_printf_d.c \
		ft_printf_u.c \
		ft_printf_p.c \
		ft_printf_x.c \
		ft_pow.c

OBJ = $(LIST:.c=.o)

OPTFLAGS = -O2
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

bonus : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

%.o : %.c
	gcc $(FLAGS) $(OPTFLAGS) -c $<

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
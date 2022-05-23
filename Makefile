# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smessal <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 12:00:58 by smessal           #+#    #+#              #
#    Updated: 2022/05/18 12:01:20 by smessal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				=	ft_printf.c

OBJS				=	$(SRCS:.c=.o)

CC					=	gcc
RM					=	rm -f
CFLAGS				=	-Wall -Wextra -Werror

NAME				=	libftprintf.a

all:				$(NAME)

$(NAME):	$(OBJ)
			$(MAKE) all -C libft
			cp libft/libft.a $(NAME)
			ar rcs $(NAME) $(OBJ)

clean:		
			$(MAKE) clean -C ./libft
			$(RM) $(OBJ)

fclean:		clean
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)

re:					fclean $(NAME)

.PHONY:				all clean fclean re bonus
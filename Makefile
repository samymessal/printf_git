# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smessal <smessal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 12:00:58 by smessal           #+#    #+#              #
#    Updated: 2022/05/24 17:34:43 by smessal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				=	ft_printf.c ft_lens.c

OBJS				=	$(SRCS:.c=.o)

CC					=	gcc
RM					=	rm -f
CFLAGS				=	-Wall -Wextra -Werror

NAME				=	libftprintf.a

all:				$(NAME)

$(NAME):	$(OBJS) #ft_printf.
			$(MAKE) all -C libft
			cp libft/libft.a $(NAME)
			ar rcs $(NAME) $(OBJS)

clean:		
			$(MAKE) clean -C ./libft
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)

re:					fclean $(NAME)

.PHONY:				all clean fclean re bonus
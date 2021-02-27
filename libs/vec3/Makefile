# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galves-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/19 04:50:18 by galves-d          #+#    #+#              #
#    Updated: 2021/02/27 18:29:40 by galves-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libvec3.a

SRCS_FILES	=	vec3.c	\
				v3_basic_operations.c\
				v3_operations.c

SRCS_DIR	=	./srcs
OBJS_DIR	=	./obj
INC_DIR		=	.

CC			=	gcc
CC_FLAGS	=	-Wall -Wextra -Werror

INCS		=	-I$(INC_DIR)
LIBS		=	-lm

SRCS		=	$(patsubst %.c, $(SRCS_DIR)/%.c, $(SRCS_FILES))
OBJS		=	$(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS_FILES))

all:	$(NAME)

$(NAME):	$(OBJS)
	@ar rcs $@ $^
	@ranlib $@

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CC_FLAGS) $(INCS) -c $< -o $@ $(LIBS)

clean:
	@$(RM) -r $(OBJS_DIR)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galves-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/19 04:50:18 by galves-d          #+#    #+#              #
#    Updated: 2021/03/30 16:42:19 by galves-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libmathx.a

SRCS_FILES	=	mx_tuple.c		\
				mx_point.c		\
				mx_vector.c		\
				mx_equal.c		\
				mx_equalxyz.c	\
				mx_equalt.c		\
				mx_negate.c		\
				mx_sum.c		\
				mx_sub.c		\
				mx_prod.c		\
				mx_div.c		\
				mx_length.c		\
				mx_unit.c		\
				mx_to_unit.c	\
				mx_dot.c		\
				mx_cross.c		\
				mx_matrix.c		\
				mx_equalm.c		\
				mx_multiply.c	\
				mx_transform.c	\
				mx_identity.c	\
				mx_transpose.c	\
				mx_submatrix.c	\
				mx_det.c		\
				mx_minor.c		\
				mx_cofactor.c	\
				mx_inv.c		\
				mx_translate.c	\
				mx_scale.c		\
				mx_rotate.c		\
				mx_rotated.c	\
				mx_skew.c

SRCS_DIR	=	./srcs
OBJS_DIR	=	./objs
INC_DIR		=	./incs

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
	$(CC) $(CC_FLAGS) $(INCS) -c $< -o $@

clean:
	@$(RM) -r $(OBJS_DIR)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

test: main.c all
	$(CC) $(INCS) -c $< -o main.o
	@$(CC) main.o $(OBJS) -o test $(LIBS)
	@$(RM) main.o
	./test
	@$(RM) test

.PHONY:	all clean fclean re

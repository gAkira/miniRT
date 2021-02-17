# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galves-d <galves-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 20:29:05 by galves-d          #+#    #+#              #
#    Updated: 2021/02/17 22:55:20 by galves-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executable file
NAME		=	miniRT

# Files needed to build this project
SRCS_FILES	=	minirt.c

# Location of the dependencies used
SRCS_DIR	=	.
OBJS_DIR	=	./obj
MLX_DIR		=	/home/user42/minilibx-linux
X_DIR		=	/usr/include

# C Compiler configuration
CC			=	gcc
CC_FLAGS	=	-Wall -Wextra -Werror
OPTM_FLAGS	=	-O3

# Libraries and its location
LIBMLX		=	libmlx.a
LIBS_DIR	=	-L$(MLX_DIR) -L$(X_DIR)
LIBS		=	-lbsd -lmlx -lXext -lX11 -lm

# Apply path to source files and object ones
SRCS		=	$(patsubst %.c, $(SRCS_DIR)/%.c, $(SRCS_FILES))
OBJS		=	$(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS_FILES))

all:	$(MLX_DIR)/$(LIBMLX) $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CC_FLAGS) $^ $(LIBS_DIR) $(LIBS) -o $@

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CC_FLAGS) -c $< -o $@

$(MLX_DIR)/$(LIBMLX):
	@echo "Making libmlx . . ."
	@$(MAKE) -C $(MLX_DIR) all
	@echo "libmlx is ready to use!"

clean:
	@echo "Cleaning libmlx . . ."
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "libmlx has been cleaned!"
	@echo "Removing object files [.obj] . . ."
	$(RM) -r $(OBJS_DIR)
	@echo "Object files were removed successfully!"

fclean:	clean
	@echo "Removing $(NAME) . . ."
	$(RM) $(NAME)
	@echo "$(NAME) was removed successfully!"

re:	fclean all

.PHONY:	all clean fclean re

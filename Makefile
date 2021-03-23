# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galves-d <galves-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 20:29:05 by galves-d          #+#    #+#              #
#    Updated: 2021/03/23 01:47:46 by galves-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executable file
NAME		=	miniRT

# Files needed to build this project
SRCS_FILES	=	main.c				\
				error_handler.c		\
				validate_args.c		\
				free_args.c			\
				in_range.c			\
				allocation_flags.c	\
				validate_res.c		\
				validate_amb.c		\
				validate_c.c		\
				validate_l.c		\
				validate_sp.c		\
				validate_pl.c		\
				validate_sq.c		\
				validate_cy.c		\
				validate_tr.c		\
				validate_objs.c		\
				validate_rt_file.c

# Location of the dependencies used
SRCS_DIR	=	./srcs
INCS_DIR	=	./incs
OBJS_DIR	=	./objs
FT_DIR		=	./libs/libft
MLX_DIR		=	./libs/minilibx-linux
VEC3_DIR	=	./libs/vec3
X_DIR		=	/usr/include

# C Compiler configuration
CC			=	gcc
CC_FLAGS	=	-Wall -Wextra -Werror

# Libraries and its location
LIBFT		=	libft.a
LIBMLX		=	libmlx.a
LIBVEC3		=	libvec3.a
LIBS_DIR_ALL=	-L$(X_DIR) -L$(MLX_DIR) -L$(VEC3_DIR) -L$(FT_DIR)
LIBS_ALL	=	-lbsd -lmlx -lXext -lX11 -lvec3 -lm -lft
INCS_ALL	=	-I$(INCS_DIR) -I$(MLX_DIR) -I$(VEC3_DIR) -I$(FT_DIR)

# Apply path to source files and object ones
SRCS		=	$(patsubst %.c, $(SRCS_DIR)/%.c, $(SRCS_FILES))
OBJS		=	$(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS_FILES))

all:	$(FT_DIR)/$(LIBFT) $(MLX_DIR)/$(LIBMLX) $(VEC3_DIR)/$(LIBVEC3) $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CC_FLAGS) $^ $(LIBS_DIR_ALL) $(LIBS_ALL) -o $@

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CC_FLAGS) $(INCS_ALL) -c $< -o $@

$(FT_DIR)/$(LIBFT):
	@echo "Making libft . . ."
	@$(MAKE) -C $(FT_DIR) all
	@echo "libft is ready to use!"

$(MLX_DIR)/$(LIBMLX):
	@echo "Making libmlx . . ."
	@$(MAKE) -C $(MLX_DIR) all
	@echo "libmlx is ready to use!"

$(VEC3_DIR)/$(LIBVEC3):
	@echo "Making libvec3 . . ."
	@$(MAKE) -C $(VEC3_DIR) all
	@echo "libvec3 is ready to use!"

clean:
	@echo "Cleaning libft . . ."
	@$(MAKE) -C $(FT_DIR) clean
	@echo "libft has been cleaned!"
	@echo "Cleaning libvec3 . . ."
	@$(MAKE) -C $(VEC3_DIR) clean
	@echo "libvec3 has been cleaned!"
	@echo "Removing object files [.obj] . . ."
	$(RM) -r $(OBJS_DIR)
	@echo "Object files were removed successfully!"

fclean:	clean
	@echo "Cleaning libmlx . . ."
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "libmlx has been cleaned!"
	@echo "Full cleaning libft . . ."
	@$(MAKE) -C $(FT_DIR) fclean
	@echo "libft has been cleaned thoroughly!"
	@echo "Full cleaning libvec3 . . ."
	@$(MAKE) -C $(VEC3_DIR) fclean
	@echo "libvec3 has been cleaned thoroughly!"
	@echo "Removing $(NAME) . . ."
	$(RM) $(NAME)
	@echo "$(NAME) was removed successfully!"

re:	fclean all

.PHONY:	all clean fclean re

#		░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
#		░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░
#		░░░░░░░░▄▀░░░░░░░░░░░░▄░░░░░░░▀▄░░░░░░░
#		░░░░░░░░█░░▄░░░░▄░░░░░░░░░░░░░░█░░░░░░░
#		░░░░░░░░█░░░░░░░░░░░░▄█▄▄░░▄░░░█░▄▄▄░░░
#		░▄▄▄▄▄░░█░░░░░░▀░░░░▀█░░▀▄░░░░░█▀▀░██░░
#		░██▄▀██▄█░░░▄░░░░░░░██░░░░▀▀▀▀▀░░░░██░░
#		░░▀██▄▀██░░░░░░░░▀░██▀░░░░░░░░░░░░░▀██░
#		░░░░▀████░▀░░░░▄░░░██░░░▄█░░░░▄░▄█░░██░
#		░░░░░░░▀█░░░░▄░░░░░██░░░░▄░░░▄░░▄░░░██░
#		░░░░░░░▄█▄░░░░░░░░░░░▀▄░░▀▀▀▀▀▀▀▀░░▄▀░░
#		░░░░░░█▀▀█████████▀▀▀▀████████████▀░░░░
#		░░░░░░████▀░░███▀░░░░░░▀███░░▀██▀░░░░░░
#		░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

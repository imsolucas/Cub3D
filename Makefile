# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yourusername <yourusername@student.42.fr>   +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 10:00:00 by yourusername      #+#    #+#             #
#    Updated: 2025/01/06 10:00:00 by yourusername     ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I./includes -I./lib/libft -I./lib/ft_printf -g3
RM			= rm -f
MK			= mkdir -p

# Directories
SRC_DIR		= src/
OBJ_DIR		= obj/
INC_DIR		= includes/
LIB_DIR		= lib/

# Libraries
LIBFT		= $(LIB_DIR)libft/libft.a
PRINTF		= $(LIB_DIR)ft_printf/libftprintf.a
LIBS		= $(LIBFT) $(PRINTF)

# Source files
SRC_FILES	= main.c \

SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS		= $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

# Colors and formatting
GREEN		= \033[0;32m
BLUE		= \033[0;34m
PURPLE		= \033[0;35m
CYAN		= \033[0;36m
RESET		= \033[0m
BOLD		= \033[1m
CLEAR		= \033[2K\r

# Progress bar variables
TOTAL_FILES	= $(words $(SRC_FILES))
CURR_FILE	= 0

# Compilation rule with progress display
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@if [ ! -d $(OBJ_DIR) ]; then \
		$(MK) $(OBJ_DIR); \
	fi
	@$(eval CURR_FILE=$(shell echo $$(($(CURR_FILE) + 1))))
	@printf "$(CLEAR)$(BLUE)➜ $(PURPLE)Compiling $(CYAN)%d/%d $(BLUE)%s$(RESET)" $(CURR_FILE) $(TOTAL_FILES) $<
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GREEN) ✓$(RESET)\n"

all: logo libs $(NAME)

logo:
	@printf "$(CYAN)$$LOGO$(RESET)\n"

libs:
	@printf "$(BLUE)Building libraries...$(RESET)"
	@make --no-print-directory -C $(LIB_DIR)libft >/dev/null
	@make --no-print-directory -C $(LIB_DIR)ft_printf >/dev/null
	@printf "$(GREEN) ✓$(RESET)\n"

$(NAME): $(OBJS)
	@printf "$(BLUE)Linking files"
	@for i in 1 2 3; do \
		printf "." && sleep 0.2; \
	done
	@printf "\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@printf "$(GREEN)$(BOLD)✨ Build successful! '$(NAME)' is ready.$(RESET)\n"

clean:
	@$(RM) -r $(OBJ_DIR)
	@make --no-print-directory -C $(LIB_DIR)libft clean >/dev/null
	@make --no-print-directory -C $(LIB_DIR)ft_printf clean >/dev/null
	@printf "$(BLUE)🧹 Cleaned object files$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@make --no-print-directory -C $(LIB_DIR)libft fclean >/dev/null
	@make --no-print-directory -C $(LIB_DIR)ft_printf fclean >/dev/null
	@printf "$(BLUE)🗑️  Cleaned binary file$(RESET)\n"
	@sleep 0.5
	@clear

re: fclean all

bonus: all

# Define the ASCII art logo
define LOGO

   ██████╗██╗   ██╗██████╗ ██████╗ ██████╗ 
  ██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗
  ██║     ██║   ██║██████╔╝ █████╔╝██║  ██║
  ██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║
  ╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝
   ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ 
                                            
endef
export LOGO

.PHONY: all clean fclean re bonus logo libs
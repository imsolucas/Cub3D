NAME		= cub3D
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I./includes -I./lib/libft -I./lib/ft_printf -I./lib/mlx_linux -g3 -fsanitize=address
RM			= rm -f
MK			= mkdir -p

# Directories
SRC_DIR		= src/
OBJ_DIR		= obj/
INC_DIR		= includes/
LIB_DIR		= lib/

# Sources Directory
PARSE_DIR = parsing/
UTILS_DIR = utils/
GNL_DIR = get_next_line/
DEBUG_DIR = debug/
INIT_DIR = init/
RENDER_DIR = render/

# Libraries
LIBFT		= $(LIB_DIR)libft/libft.a
PRINTF		= $(LIB_DIR)ft_printf/libftprintf.a
MLX			= $(LIB_DIR)mlx_linux/libmlx.a
LIBS		= $(MLX) $(LIBFT) $(PRINTF)  

# Source files
SRC_FILES	= main.c \
			  $(addprefix $(PARSE_DIR), parse.c ft_split_whitespace.c parse_map.c parse_utils.c validate_map.c validate_map_utils.c) \
			  $(addprefix $(GNL_DIR), get_next_line.c) \
			  $(addprefix $(UTILS_DIR), utils.c utils2.c error.c) \
			  $(addprefix $(DEBUG_DIR), debug.c) \
			  $(addprefix $(INIT_DIR), init_game.c init_elements.c init_struct.c) \
			  $(addprefix $(RENDER_DIR), raycasting.c render.c render_utils.c) \

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
	@$(MK) $(dir $@)
	@$(eval CURR_FILE=$(shell echo $$(($(CURR_FILE) + 1))))
	@printf "$(CLEAR)$(BLUE)➜ $(PURPLE)Compiling $(CYAN)%d/%d $(BLUE)%s$(RESET)" $(CURR_FILE) $(TOTAL_FILES) $<
	@$(CC) $(CFLAGS) -Imlx_linux -O3 -c $< -o $@
	@printf "$(GREEN) ✓$(RESET)\n"

all: logo libs $(NAME)

logo:
	@printf "$(CYAN)$$LOGO$(RESET)\n"

libs:
	@printf "$(BLUE)Building libraries...$(RESET)"
	@make --no-print-directory -C $(LIB_DIR)libft >/dev/null
	@make --no-print-directory -C $(LIB_DIR)ft_printf >/dev/null
	@make --no-print-directory -C $(LIB_DIR)mlx_linux >/dev/null
	@printf "$(GREEN) ✓$(RESET)\n"

$(NAME): $(OBJS)
	@printf "$(BLUE)Linking files"
	@for i in 1 2 3; do \
		printf "." && sleep 0.2; \
	done
	@printf "\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -lX11 -lXext -lm -o $(NAME)
	@printf "$(GREEN)$(BOLD)✨ Build successful! '$(NAME)' is ready.$(RESET)\n"

clean:
	@$(RM) -r $(OBJ_DIR)
	@make --no-print-directory -C $(LIB_DIR)libft clean >/dev/null
	@make --no-print-directory -C $(LIB_DIR)ft_printf clean >/dev/null
	@make --no-print-directory -C $(LIB_DIR)mlx_linux clean >/dev/null
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
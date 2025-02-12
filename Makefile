NAME		= cub3D
BONUS_NAME	= cub3D_bonus
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I./includes -I./lib/libft -I./lib/ft_printf -I./lib/mlx_linux -g3 -fsanitize=address
RM			= rm -f
MK			= mkdir -p

# Directories
SRC_DIR		= src/
OBJ_DIR		= obj/
BONUS_OBJ_DIR	= obj_bonus/
INC_DIR		= includes/
LIB_DIR		= lib/

# Sources Directory
PARSE_DIR = parsing/
UTILS_DIR = utils/
GNL_DIR = get_next_line/
DEBUG_DIR = debug/
INIT_DIR = init/
RENDER_DIR = render/
MOVEMENT_DIR = movement/
DOOR_DIR = door/

# Libraries
LIBFT		= $(LIB_DIR)libft/libft.a
PRINTF		= $(LIB_DIR)ft_printf/libftprintf.a
MLX			= $(LIB_DIR)mlx_linux/libmlx.a
LIBS		= $(MLX) $(LIBFT) $(PRINTF)  

# Source files
SRC_FILES	= main.c \
			  $(addprefix $(PARSE_DIR), parse.c parse_validate.c parse_process.c ft_split_whitespace.c parse_map.c parse_utils.c parse_utils2.c validate_map.c validate_map_flood.c validate_map_utils.c) \
			  $(addprefix $(GNL_DIR), get_next_line.c) \
			  $(addprefix $(UTILS_DIR), utils.c utils2.c error.c) \
			  $(addprefix $(DEBUG_DIR), debug.c) \
			  $(addprefix $(INIT_DIR), init_game.c init_elements.c init_struct.c) \
			  $(addprefix $(RENDER_DIR), raycasting.c render.c draw_utils.c draw.c) \
			  $(addprefix $(MOVEMENT_DIR), direction.c rotation.c events.c) \

# Bonus source files (includes mouse.c and uses main_bonus.c instead of main.c)
BONUS_FILES	= main_bonus.c \
			  $(addprefix $(PARSE_DIR), parse.c parse_validate.c parse_process.c ft_split_whitespace.c parse_utils.c parse_utils2.c validate_map_flood.c validate_map_utils.c) \
			  $(addprefix $(GNL_DIR), get_next_line.c) \
			  $(addprefix $(UTILS_DIR), utils.c error.c) \
			  $(addprefix $(DEBUG_DIR), debug.c) \
			  $(addprefix $(INIT_DIR), init_elements.c init_struct.c) \
			  $(addprefix $(RENDER_DIR), raycasting.c draw_utils.c minimap.c minimap_utils.c) \
			  $(addprefix $(MOVEMENT_DIR), direction.c rotation.c events.c mouse.c) \
			  $(addprefix $(DOOR_DIR), handle_door.c draw_bonus.c parse_map_bonus.c validate_map_bonus.c utils2_bonus.c init_game_bonus.c) \

SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))
BONUS_SRCS	= $(addprefix $(SRC_DIR), $(BONUS_FILES))
OBJS		= $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))
BONUS_OBJS	= $(addprefix $(BONUS_OBJ_DIR), $(BONUS_FILES:.c=.o))

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

$(BONUS_OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(MK) $(dir $@)
	@$(eval CURR_FILE=$(shell echo $$(($(CURR_FILE) + 1))))
	@printf "$(CLEAR)$(BLUE)➜ $(PURPLE)Compiling bonus $(CYAN)%d/%d $(BLUE)%s$(RESET)" $(CURR_FILE) $(TOTAL_FILES) $<
	@$(CC) $(CFLAGS) -Imlx_linux -O3 -c $< -o $@
	@printf "$(GREEN) ✓$(RESET)\n"

all: logo libs $(NAME)

bonus: logo libs $(BONUS_NAME)

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

$(BONUS_NAME): $(BONUS_OBJS)
	@printf "$(BLUE)Linking bonus files"
	@for i in 1 2 3; do \
		printf "." && sleep 0.2; \
	done
	@printf "\n"
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBS) -lX11 -lXext -lm -o $(BONUS_NAME)
	@printf "$(GREEN)$(BOLD)✨ Build successful! '$(BONUS_NAME)' is ready.$(RESET)\n"

clean:
	@$(RM) -r $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@make --no-print-directory -C $(LIB_DIR)libft clean >/dev/null
	@make --no-print-directory -C $(LIB_DIR)ft_printf clean >/dev/null
	@make --no-print-directory -C $(LIB_DIR)mlx_linux clean >/dev/null
	@printf "$(BLUE)🧹 Cleaned object files$(RESET)\n"

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@make --no-print-directory -C $(LIB_DIR)libft fclean >/dev/null
	@make --no-print-directory -C $(LIB_DIR)ft_printf fclean >/dev/null
	@printf "$(BLUE)🗑️  Cleaned binary files$(RESET)\n"
	@sleep 0.5
	@clear

re: fclean all

re_bonus: fclean bonus

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

.PHONY: all clean fclean re bonus re_bonus logo libs
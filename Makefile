# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbarraul <gbarraul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/08 15:09:01 by yyang             #+#    #+#              #
#    Updated: 2015/03/02 17:56:02 by gbarraul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include Makefile.cfg

NAME = $(CONFIG_NAME)
OUTPUT_TYPE = $(CONFIG_OUTPUT_TYPE)

MLX_PATH = ./libs/minilibx
MLX_HEADERS = -I $(MLX_PATH)
MLX_SRC= $(MLX_PATH)/mlx_shaders.c $(MLX_PATH)/mlx_new_window.m \
	$(MLX_PATH)/mlx_init_loop.m $(MLX_PATH)/mlx_new_image.m \
	$(MLX_PATH)/mlx_xpm.c $(MLX_PATH)/mlx_int_str_to_wordtab.c
MLX_OBJ1=$(MLX_SRC:.c=.o)
MLX_OBJ=$(MLX_OBJ1:.m=.o)

C_DIR = srcs/
O_DIR = .tmp/objects/

CC_FLAGS = -g -Wall -Wextra -Werror
CC_HEADERS = -I ./includes -I ./srcs/libft/includes $(MLX_HEADERS)
CC_DEBUG =
DEBUG = 0

C_FILES = $(shell find $(C_DIR) -type f -follow -print | grep ".*\.c$$")
C_DIRS = $(shell find $(C_DIR) -type d -follow -print)

H_FILES = $(shell find includes -type f -follow -print | grep ".*\.h$$")

O_DIRS = $(C_DIRS:$(C_DIR)%=$(O_DIR)%)
O_FILES = $(C_FILES:$(C_DIR)%.c=$(O_DIR)%.o)

COL_GRAY = \033[1;30m
COL_RESET = \033[0;0m
COL_RED = \033[0;31m
COL_GREEN = \033[0;32m
CC_OPTIONS = $(CC_FLAGS) $(CC_HEADERS) $(CC_FLAGS_EXTRA)

DEBUG_FILE_NAME = .debug.out

MAKE = make -s

all: $(NAME)

$(NAME): $(O_FILES) $(MLX_OBJ)
	@echo ""
	$(MAKE) -C $(MLX_PATH)
	@echo "[info] compile $(OUTPUT_TYPE) ..."
ifeq ($(OUTPUT_TYPE), lib)
	@ar rcs $@ $^ $(MLX_OBJ)
endif
ifeq ($(OUTPUT_TYPE), exec)
	@gcc $(CC_OPTIONS) $(CC_DEBUG) $^ -o $@
endif
	@echo "$(COL_GREEN)lib compiled$(COL_RESET)"

$(O_DIR)%.o: $(C_DIR)%.c $(H_FILES)
	@mkdir -p $(O_DIRS) $(O_DIR) 2> /dev/null || echo "" > /dev/null
	@gcc $(CC_OPTIONS) $(CC_DEBUG) -o $@ -c $< && printf "."

debug: _debug all

clean:
	$(MAKE) -C $(MLX_PATH) clean
	$(info [info] $@ ...)
	@rm $(O_FILES) 2> /dev/null || echo "" > /dev/null
	@rmdir $(O_DIRS) $(O_DIR) 2> /dev/null || echo "" > /dev/null

fclean: clean
	$(info [info] $@ ...)
	@rm $(NAME) 2> /dev/null || echo "" > /dev/null

re:
	$(MAKE) -C $(MLX_PATH) re
	$(MAKE) fclean
	$(MAKE) all

_debug:
	$(eval CC_FLAGS = -Wall -Wextra -g)
	$(eval DEBUG = 1)
	$(eval CC_DEBUG = -D DEBUG_ASSERT_ENABLED)

run:
	./$(NAME)

check:
	$(MAKE) -C tests/moulitest_tests

norm:
	find srcs includes -name '*.c' -o -name '*.h' | xargs norminette

log:
	touch $(DEBUG_FILE_NAME)
	tail -f $(DEBUG_FILE_NAME)

.PHONY: all debug clean fclean re _debug

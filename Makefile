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
C_DIR = srcs
O_DIR = .tmp/objects

# CC_OPTIMIZATION_FLAGS = -O2
CC_LIBMLX = -L/usr/X11/lib -lmlx -lXext -lX11
CC_FLAGS = -g -Wall -Wextra -Werror
CC_HEADERS = -I ./includes -I ./srcs/libft/includes
CC_DEBUG =
DEBUG = 0

C_FILES = $(shell find $(C_DIR) -type f -follow -print | grep ".*\.c$$")
C_DIRS = $(shell find $(C_DIR) -type d -follow -print)

O_DIRS = $(C_DIRS:$(C_DIR)%=$(O_DIR)%)
O_FILES = $(C_FILES:$(C_DIR)%.c=$(O_DIR)%.o)

COL_GRAY = \033[1;30m
COL_RESET = \033[0;0m
COL_RED = \033[0;31m
COL_GREEN = \033[0;32m
CC_OPTIONS = $(CC_FLAGS) $(CC_HEADERS) $(CC_FLAGS_EXTRA)

all:
ifeq ($(DEBUG), 1)
	@make -j4 _debug $(NAME);
else
	@make -j4 $(NAME)
endif

$(NAME): $(O_FILES)
	$(info [info] compile $(OUTPUT_TYPE) ...)
ifeq ($(OUTPUT_TYPE), lib)
	@ar rcs $@ $^
endif
ifeq ($(OUTPUT_TYPE), exec)
	@gcc $(CC_OPTIONS) $(CC_LIBMLX) $(CC_DEBUG) $^ -o $@
endif
	@echo "$(COL_GREEN)$(NAME)$(COL_RESET)"

$(O_DIR)%.o: $(C_DIR)%.c
	@mkdir -p $(O_DIRS) $(O_DIR) 2> /dev/null || echo "" > /dev/null
	@gcc $(CC_OPTIONS) $(CC_DEBUG) -o $@ -c $< \
		&& echo "$<  >>>>  $@" | sed 's;//;/;g'

debug: _debug all

clean:
	$(info [info] $@ ...)
	@rm $(O_FILES) 2> /dev/null || echo "" > /dev/null
	@rmdir $(O_DIRS) $(O_DIR) 2> /dev/null || echo "" > /dev/null

fclean: clean
	$(info [info] $@ ...)
	@rm $(NAME) 2> /dev/null || echo "" > /dev/null

re: fclean all

_debug:
	$(eval CC_FLAGS = -Wall -Wextra -g)
	$(eval DEBUG = 1)
	$(eval CC_DEBUG = -D DEBUG_ASSERT_ENABLED)

run:
	./$(NAME)

check:
	make -C tests/moulitest_tests

norm:
	find srcs includes -name '*.c' -o -name '*.h' | xargs norminette

.PHONY: all debug clean fclean re _debug

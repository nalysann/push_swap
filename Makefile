# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/27 11:46:04 by nalysann          #+#    #+#              #
#    Updated: 2020/08/27 11:46:06 by nalysann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker

PUSH_SWAP = push_swap

SRC_DIR = src

SRC_CHECKER = checker.c \
              deque_operations.c \
              deque_utils.c \
              operations.c \
              validation.c

SRC_PUSH_SWAP = deque_minmax.c \
                deque_operations.c \
                deque_utils.c \
                get_best_ops.c \
                move.c \
                operations.c \
                push_swap.c \
                sort_utils.c \
                validation.c

INC_DIR = inc \
          $(LIB_DIR)/inc

OBJ_DIR = obj

OBJ_CHECKER = $(addprefix $(OBJ_DIR)/, $(SRC_CHECKER:.c=.o))

OBJ_PUSH_SWAP = $(addprefix $(OBJ_DIR)/, $(SRC_PUSH_SWAP:.c=.o))

DEP_CHECKER = $(addprefix $(OBJ_DIR)/, $(SRC_CHECKER:.c=.d))

DEP_PUSH_SWAP = $(addprefix $(OBJ_DIR)/, $(SRC_PUSH_SWAP:.c=.d))

LIB_DIR = libft

LIB = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror \
         $(addprefix -I , $(INC_DIR)) \
         -MMD \
         -march=native -O2 -pipe

LDFLAGS = -L $(LIB_DIR) -lft

SHELL = /bin/zsh

RESET = "\033[0;0m"
RED = "\033[1;31m"
GREEN = "\033[1;32m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
MAGENTA = "\033[1;35m"
CYAN = "\033[1;36m"
GREY = "\033[1;37m"

.PHONY: all clean fclean re

all: $(LIB_DIR)/$(LIB) $(CHECKER) $(PUSH_SWAP)

$(LIB_DIR)/$(LIB):
	@$(MAKE) -C $(LIB_DIR)

$(CHECKER): $(LIB_DIR)/$(LIB) $(OBJ_CHECKER)
	@echo -en $(GREEN)
	$(CC) $(LDFLAGS) $(OBJ_CHECKER) -o $@
	@echo -en $(RESET)

$(PUSH_SWAP): $(LIB_DIR)/$(LIB) $(OBJ_PUSH_SWAP)
	@echo -en $(GREEN)
	$(CC) $(LDFLAGS) $(OBJ_PUSH_SWAP) -o $@
	@echo -en $(RESET)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo -en $(GREY)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo -en $(RESET)

include $(wildcard $(DEP_CHECKER))
include $(wildcard $(DEP_PUSH_SWAP))

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	@echo -en $(RED)
	rm -rf $(OBJ_DIR)
	@echo -en $(RESET)

fclean: clean
	@$(MAKE) fclean -C $(LIB_DIR)
	@echo -en $(RED)
	rm -f $(CHECKER) $(PUSH_SWAP)
	@echo -en $(RESET)

re: fclean all

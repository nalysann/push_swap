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
                rotation_type.c \
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

WHITE = "\033[0;0m"
RED = "\033[1;31m"
GREEN = "\033[1;32m"
YELLOW = "\033[1;33m"
BACK = "\033[A\033[M"

.PHONY: all clean fclean re

all:
	@$(MAKE) -sC $(LIB_DIR)
	@$(MAKE) $(CHECKER)
	@$(MAKE) $(PUSH_SWAP)

$(CHECKER): $(LIB_DIR)/$(LIB) $(OBJ_CHECKER)
	@$(CC) $(LDFLAGS) $(OBJ_CHECKER) -o $@
	@echo -e $(BACK)$(GREEN)$@ created$(WHITE)
	@echo

$(PUSH_SWAP): $(LIB_DIR)/$(LIB) $(OBJ_PUSH_SWAP)
	@$(CC) $(LDFLAGS) $(OBJ_PUSH_SWAP) -o $@
	@echo -e $(BACK)$(GREEN)$@ created$(WHITE)

$(OBJ_DIR):
	@mkdir -p $@
	@echo

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -e $(YELLOW)compiling: $(@:$(OBJ_DIR)/%=%)$(BACK)$(WHITE)

include $(wildcard $(DEP_CHECKER))
include $(wildcard $(DEP_PUSH_SWAP))

clean:
	@$(MAKE) clean -sC $(LIB_DIR)
	@rm -rf $(OBJ_DIR)
	@echo -e $(RED)object and dependency files deleted$(WHITE)

fclean: clean
	@$(MAKE) fclean -sC $(LIB_DIR)
	@rm -f $(CHECKER) $(PUSH_SWAP)
	@echo -e $(RED)$(CHECKER) and $(PUSH_SWAP) deleted$(WHITE)

re: fclean all

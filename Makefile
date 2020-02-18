# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xzhu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/12 14:55:11 by xzhu              #+#    #+#              #
#    Updated: 2018/07/12 14:55:16 by xzhu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

P_NAME		=	push_swap
C_NAME		=	checker

NOC			=	\033[0m
GREEN		=	\033[0;36m
BLUE		=	\033[0;34m
RED			=	\033[0;31m

CC			=	gcc
CC_FLAGS	=	-Wall -Wextra -Werror -g

SRC_PATH	=	./srcs/
INC_PATH	=	./includes/
OBJ_PATH	=	./obj/
LFT_PATH	=	./libftprintf/

P_SRC		=	$(addprefix $(SRC_PATH),$(P_SRC_NAME))
C_SRC		=	$(addprefix $(SRC_PATH),$(C_SRC_NAME))
P_OBJ		=	$(addprefix $(OBJ_PATH),$(P_OBJ_NAME))
C_OBJ		=	$(addprefix $(OBJ_PATH),$(C_OBJ_NAME))
INC			=	$(addprefix -I,$(INC_PATH))

P_OBJ_NAME	=	$(P_SRC_NAME:.c=.o)
C_OBJ_NAME	=	$(C_SRC_NAME:.c=.o)

P_SRC_NAME	=	push_swap.c queue.c stack.c p_input.c print.c index_group.c radix_sort.c sort_small.c dispatch.c ops_1.c ops_2.c ops_3.c
C_SRC_NAME	=	checker.c queue.c stack.c dispatch.c ops_1.c ops_2.c ops_3.c c_input.c print.c

all:
	@make -C $(LFT_PATH)
	@make $(P_NAME)
	@make $(C_NAME)

$(P_NAME): $(P_OBJ)
	@$(CC) -o $(P_NAME) $(P_OBJ) -L $(LFT_PATH) -lftprintf
	@echo "$(GREEN)PUSH_SWAP ✓ Push_swap ready$(NOC)"

$(C_NAME): $(C_OBJ)
	@$(CC) -o $(C_NAME) $(C_OBJ) -L $(LFT_PATH) -lftprintf
	@echo "$(GREEN)CHECKER   ✓ Checker   ready$(NOC)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "$(BLUE)PUSH_SWAP ✓ Removed .o files$(NOC)"
	@echo "$(BLUE)CHECKER   ✓ Removed .o files$(NOC)"

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(P_NAME)
	@rm -f $(C_NAME)
	@echo "$(RED)PUSH_SWAP ✓ Removed Push_swap executable$(NOC)"
	@echo "$(RED)CHECKER   ✓ Removed Checker   executable$(NOC)"

re: fclean all

.PHONY: all, $(P_NAME), $(C_NAME), clean, fclean, re

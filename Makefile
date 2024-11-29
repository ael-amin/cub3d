# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 17:47:56 by rlabbiz           #+#    #+#              #
#    Updated: 2023/09/01 20:35:44 by rlabbiz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLG = -Wall -Wextra -Werror
MLX = -Imlx -lmlx -framework OpenGL -framework AppKit

NAME = cub3d
OBJ =	src/mandatory/check_map.o \
		src/mandatory/draw_map.o \
		src/mandatory/draw_map_utils.o \
		src/mandatory/draw_map_utils2.o \
		src/mandatory/handle_key.o \
		src/mandatory/handle_key_utils.o \
		src/mandatory/ray_casting.o \
		src/mandatory/ray_casting_utils.o \
		src/mandatory/cub3d_utils.o \
		src/mandatory/check_map_utils.o \
		src/mandatory/check_map_utils1.o \
		src/mandatory/check_map_utils2.o
MAIN = src/mandatory/cub3d.c
DEF = include/cub3d.h

NAME_BONUS = cub3d_bonus
OBJ_BONUS =	src/bonus/check_map_bonus.o \
		src/bonus/draw_map_bonus.o \
		src/bonus/draw_map_utils_bonus.o \
		src/bonus/draw_map_utils2_bonus.o \
		src/bonus/handle_key_bonus.o \
		src/bonus/handle_key_utils_bonus.o \
		src/bonus/ray_casting_bonus.o \
		src/bonus/ray_casting_utils_bonus.o \
		src/bonus/cub3d_utils_bonus.o \
		src/bonus/check_map_utils_bonus.o \
		src/bonus/check_map_utils1_bonus.o \
		src/bonus/check_map_utils2_bonus.o
MAIN_BONUS = src/bonus/cub3d_bonus.c
DEF_BONUS = include/cub3d_bonus.h

LIBFT = libft/libft.a

GRN=\033[0;32m
RED=\033[0;31m
BLU=\033[0;34m
END=\033[0m

%.o: %.c $(DEF)
	@$(CC) -c -o $@ $< $(FLG)
	@echo "$(GRN)$<... DONE!$(END)"

.PHONY : all clean fclean re 

all : $(NAME)
bonus : $(NAME_BONUS)
$(LIBFT) :
	@make bonus -C libft
	@echo "$(GRN)libft... DONE!$(END)"

$(NAME) : $(OBJ) $(DEF) $(MAIN) $(LIBFT)
	@$(CC) $(FLG) $(MLX) $(MAIN) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GRN)create the cub3d... DONE!$(END)"

$(NAME_BONUS) : $(OBJ_BONUS) $(DEF_BONUS) $(MAIN_BONUS) $(LIBFT)
	@$(CC) $(FLG) $(MLX) $(MAIN_BONUS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)
	@echo "$(GRN)create the cub3d_bonus... DONE!$(END)"

clean :
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@make clean -C libft
	@echo "$(GRN)Remove all objects file... DONE!$(END)"

fclean : clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@make fclean -C libft
	@echo "$(GRN)Remove the cub3d... DONE!$(END)"

re : fclean all 

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 15:51:33 by jwilen            #+#    #+#              #
#    Updated: 2020/11/04 15:51:37 by jwilen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBRARIES = -lft -L$(LIBFT_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)
TERMCAP = -ltermcap

LIBFT_DIRECTORY = ./libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_HEADERS = $(LIBFT_DIRECTORY)

HEADERS_DIRECTORY = ./includes/
HEADER_FILES = header.h
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADER_FILES))

SOURCES_DIRECTORY = ./srcs/
SOURCE_FILES =		minishell.c \
					builtins/builtins.c \
					builtins/cd.c \
					builtins/cd2.c \
					builtins/env.c \
					builtins/exit.c \
					builtins/help.c \
					builtins/setenv.c \
					builtins/unsetenv.c \
					history/history.c \
					history/history2.c \
					lexer/lexi.c \
					lexer/lexi2.c \
					lexer/token.c \
					main/handel_key.c \
					main/handel_key2.c \
					main/line_edit.c \
					main/parse.c \
					main/read.c\
					main/run.c \
					main/run2.c \
					main/signal.c \
					main/termcap.c \
					util/check_rights.c \
					util/free.c \
					util/logo.c \
					util/prompt.c \
					util/util.c \
					util/util2.c \
					util/util3.c \
					util/util4.c \

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCE_FILES))

OBJECTS_DIRECTORY = ./objects/
OBJ_DIR_BI = $(OBJ_DIR)./objects/builtins/
OBJ_DIR_LE = $(OBJ_DIR)./objects/lexer/
OBJ_DIR_UT = $(OBJ_DIR)./objects/util/
OBJ_DIR_MA = $(OBJ_DIR)./objects/main/
OBJ_DIR_HI = $(OBJ_DIR)./objects/history/

OBJECT_FILES = $(patsubst %.c, %.o, $(SOURCE_FILES))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECT_FILES))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(SOURCES) $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS) $(OBJECTS_PS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(TERMCAP) $(OBJECTS) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)$(NAME) object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"
	@mkdir -p $(OBJ_DIR_BI)
	@echo "Built ins: [$(COLOR_SUCCESS)$(OBJ_DIR_BI) was created$(RESET)]"
	@mkdir -p $(OBJ_DIR_LE)
	@echo "Lexer: [$(COLOR_SUCCESS)$(OBJ_DIR_LE) was created$(RESET)]"
	@mkdir -p $(OBJ_DIR_UT)
	@echo "Utils: [$(COLOR_SUCCESS)$(OBJ_DIR_UT) was created$(RESET)]"
	@mkdir -p $(OBJ_DIR_MA)
	@echo "Main: [$(COLOR_SUCCESS)$(OBJ_DIR_MA) was created$(RESET)]"
	@mkdir -p $(OBJ_DIR_HI)
	@echo "History: [$(COLOR_SUCCESS)$(OBJ_DIR_HI) was created$(RESET)]"


$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(LIBFT) OK!$(RESET)"

run:
	$(OBJECTS_DIRECTORY) $(OBJECTS) $(OBJECTS_PS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)$(NAME) object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

	$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

	$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

lib:
	@echo "$(NAME): $(GREEN)creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(LIBFT) OK!$(RESET)"

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): [$(RED)object files were deleted$(RESET)]"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME): [$(RED)$(LIBFT) was deleted$(RESET)]"
	@rm -f $(NAME)
	@echo "$(NAME): [$(RED)$(NAME) was deleted$(RESET)]"


re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re

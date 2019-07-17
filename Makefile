NAME = minishell

# <=== LIBS ===>

LIBFT_NAME = libft.a

# <=== DIR PATHS ===>

SRC_PATH = ./source/
SRC_BUILTINS_PATH = $(SRC_PATH)builtins
SRC_UTILS_PATH = $(SRC_PATH)utils
SRC_ENVORONMENT_PATH = $(SRC_PATH)environment

INC_PATH = ./headers/
INC_BUILTINS_PATH = $(INC_PATH)builtins
INC_UTILS_PATH = $(INC_PATH)utils
INC_ENVORONMENT_PATH = $(INC_PATH)environment

LIB_PATH = ./libft/

# <=== SOURCES ===>

SRC =           	main.c \
					main_loop.c \
	

SRC_BUILTINS =		builtins_1.c \
					builtins_2.c \

SRC_UTILS =		

SRC_ENVORONMENT =	environment.c \

# <=== OBJ ===>

OBJ_DIR = obj

OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_SRC_BUILTINS = $(addprefix $(OBJ_DIR)/, $(SRC_BUILTINS:.c=.o))
OBJ_SRC_UTILS = $(addprefix $(OBJ_DIR)/, $(SRC_UTILS:.c=.o))
OBJ_SRC_ENVORONMENT = $(addprefix $(OBJ_DIR)/, $(SRC_ENVORONMENT:.c=.o))

# <=== COMPILER ===>

CC = clang

FLG =	-Werror -Wextra -Wall -I$(LIB_PATH)includes -I$(INC_PATH) -I$(INC_BUILTINS_PATH) \
		-I$(INC_UTILS_PATH) -I$(INC_ENVORONMENT_PATH)

# <=== RULES ===>

all: $(NAME)

$(NAME): $(OBJ_SRC) $(OBJ_SRC_BUILTINS) $(OBJ_SRC_UTILS) $(OBJ_SRC_ENVORONMENT)
	@make -C $(LIB_PATH)
	@$(CC) $(FLG) -g $(LIB_PATH)$(LIBFT_NAME)  \
	$(OBJ_SRC) $(OBJ_SRC_BUILTINS) $(OBJ_SRC_UTILS) \
	$(OBJ_SRC_ENVORONMENT) -o $(NAME)
	@echo "shell ✅"

$(OBJ_DIR)/%.o : $(SRC_PATH)%.c
	@/bin/mkdir -p $(OBJ_DIR)
	@$(CC) $(FLG) -c -o $@ $<

$(OBJ_DIR)/%.o : $(SRC_BUILTINS_PATH)%.c
	@$(CC) $(FLG) -c -o $@ $<

$(OBJ_DIR)/%.o : $(SRC_UTILS_PATH)%.c
	@$(CC) $(FLG) -c -o $@ $<

$(OBJ_DIR)/%.o : $(SRC_ENVORONMENT_PATH)%.c
	@$(CC) $(FLG) -c -o $@ $<

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make -C $(LIB_PATH) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIB_PATH) fclean

re: fclean all
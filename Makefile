NAME = minishell

# <=== LIBS ===>

LIBFT_NAME = libft.a

# <=== DIR PATHS ===>

SRC_PATH = ./source/
SRC_BUILTINS_PATH = $(SRC_PATH)builtins/
SRC_UTILS_PATH = $(SRC_PATH)utils/
SRC_ENVORONMENT_PATH = $(SRC_PATH)environment/
SRC_EXECUTION_PATH = $(SRC_PATH)execution/
SRC_HASH_PATH = $(SRC_PATH)hash/

INC_PATH = ./headers/
INC_BUILTINS_PATH = $(INC_PATH)builtins/
INC_UTILS_PATH = $(INC_PATH)utils/
INC_ENVORONMENT_PATH = $(INC_PATH)environment/
INC_EXECUTION_PATH = $(INC_PATH)execution/
INC_HASH_PATH = $(INC_PATH)hash/

LIB_PATH = ./libft/

# <=== SOURCES ===>

SRC =           	main.c \
					main_loop.c \
	

SRC_BUILTINS =		builtins_1.c \
					builtins_2.c \
					cd_cmd.c \

SRC_UTILS =			environment_utils.c \
					errors.c \

SRC_ENVORONMENT =	environment.c \
					variables_expansion.c \

SRC_EXECUTION =		execution.c \

SRC_HASH =			string_to_hash.c \

# <=== OBJ ===>

OBJ_DIR = obj

OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_SRC_BUILTINS = $(addprefix $(OBJ_DIR)/, $(SRC_BUILTINS:.c=.o))
OBJ_SRC_UTILS = $(addprefix $(OBJ_DIR)/, $(SRC_UTILS:.c=.o))
OBJ_SRC_ENVORONMENT = $(addprefix $(OBJ_DIR)/, $(SRC_ENVORONMENT:.c=.o))
OBJ_SRC_EXECUTION = $(addprefix $(OBJ_DIR)/, $(SRC_EXECUTION:.c=.o))
OBJ_SRC_HASH = $(addprefix $(OBJ_DIR)/, $(SRC_HASH:.c=.o))

# <=== COMPILER ===>

CC = clang

INCLUDES = -I$(INC_PATH) -I$(INC_BUILTINS_PATH) -I$(INC_UTILS_PATH) \
			-I$(INC_ENVORONMENT_PATH) -I$(INC_EXECUTION_PATH) \
			-I$(INC_HASH_PATH) \

FLG =	-Werror -Wextra -Wall -I$(LIB_PATH)includes $(INCLUDES)

# <=== RULES ===>

all: $(NAME)

$(NAME): $(OBJ_SRC) $(OBJ_SRC_BUILTINS) $(OBJ_SRC_UTILS) \
			$(OBJ_SRC_ENVORONMENT) $(OBJ_SRC_EXECUTION) \
			$(OBJ_SRC_HASH)
	@make -C $(LIB_PATH)
	@$(CC) $(FLG) -g $(LIB_PATH)$(LIBFT_NAME)  \
	$(OBJ_SRC) $(OBJ_SRC_BUILTINS) $(OBJ_SRC_UTILS) \
	$(OBJ_SRC_ENVORONMENT) $(OBJ_SRC_EXECUTION) \
	$(OBJ_SRC_HASH) -o $(NAME)
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

$(OBJ_DIR)/%.o : $(SRC_EXECUTION_PATH)%.c
	@$(CC) $(FLG) -c -o $@ $<

$(OBJ_DIR)/%.o : $(SRC_HASH_PATH)%.c
	@$(CC) $(FLG) -c -o $@ $<

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make -C $(LIB_PATH) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIB_PATH) fclean

re: fclean all
NAME = minishell

# <=== LIBS ===>

LIBFT_NAME = libft.a

# <=== DIR PATHS ===>

SRC_PATH = ./source/
SRC_ = ./source/...

INC_PATH = ./headers/
LIB_PATH = ../libft/

# <=== SOURCES ===>

SRC =           main.c \


SRC_ =     

# <=== OBJ ===>

OBJ_DIR = obj

OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJ_SRC_UTILS = $(addprefix $(OBJ_DIR)/, $(SRC_:.c=.o))

# <=== COMPILER ===>

CC = clang

FLG = -O3 -Werror -Wextra -Wall -I$(LIB_PATH)includes -I$(INC_PATH)

# <=== RULES ===>

all: $(NAME)

$(NAME): $(OBJ_SRC) $(OBJ_SRC_) 
	@make -C $(LIB_PATH)
	@$(CC) $(FLG) -g $(LIB_PATH)$(LIBFT_NAME) -g $(LIBUI_PATH) \
	$(OBJ_SRC) $(OBJ_SRC_) -o $(NAME)
	@echo "shell ✅"

$(OBJ_DIR)/%.o : $(SRC_PATH)%.c
	@/bin/mkdir -p $(OBJ_DIR)
	@$(CC) $(FLG) -c -I$(INC_PATH) -c -o $@ $<

$(OBJ_DIR)/%.o : $(SRC__PATH)%.c
	@$(CC) $(FLG) -c -I$(INC_PATH) -c -o $@ $<

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make -C $(LIB_PATH) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIB_PATH) fclean

re: fclean all
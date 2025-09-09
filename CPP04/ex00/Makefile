# **************************************************************************** #
#                                Makefile                                      #
# **************************************************************************** #

NAME        = animals

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -Iinc -g

SRC_DIR     = src
OBJ_DIR     = obj

SRC         = main.cpp \
              Animal.cpp \
              Dog.cpp \
              Cat.cpp \
              WrongAnimal.cpp \
              WrongCat.cpp

SRCS        = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS        = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

# Colors
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
RED         = \033[0;31m
NC          = \033[0m

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✔ Build successful: $(NAME)$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiled $< $(NC)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)✖ Object files removed$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)✖ Executable removed$(NC)"

re: fclean all

.PHONY: all clean fclean re

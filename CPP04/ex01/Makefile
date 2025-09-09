# Compiler and flags
CXX        = c++
CXXFLAGS   = -Wall -Wextra -Werror -std=c++98 -Iinc

# Directories
SRC_DIR    = src
OBJ_DIR    = obj
INC_DIR    = inc

# Sources and objects
SRC        = main.cpp \
             Animal.cpp \
             Dog.cpp \
             Cat.cpp \
             Brain.cpp
SRCS       = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS       = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

# Executable name
NAME       = animal_sim

# Colors
GREEN      = \033[0;32m
YELLOW     = \033[0;33m
RED        = \033[0;31m
NC         = \033[0m

# Default rule
all: $(NAME)

# Build executable
$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✔ Build successful: $(NAME)$(NC)"

# Compile source files to objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiled $<$(NC)"

# Create object directory if not exists
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Clean object files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)✖ Object files removed$(NC)"

# Clean objects + executable
fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)✖ Executable removed$(NC)"

# Rebuild everything
re: fclean all

# Prevent conflicts with file names
.PHONY: all clean fclean re
